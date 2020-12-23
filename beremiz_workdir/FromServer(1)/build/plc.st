TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    ADD10_OUT : UINT;
    EQ13_OUT : BOOL;
    SEL15_OUT : UINT;
    AND7_OUT : BOOL;
  END_VAR

  ADD10_OUT := ADD(COUNTER, 1);
  EQ13_OUT := EQ(N, ADD10_OUT);
  SEL15_OUT := SEL(EQ13_OUT, ADD10_OUT, 0);
  COUNTER := SEL15_OUT;
  AND7_OUT := AND(EQ13_OUT, TRIG);
  py_eval(TRIG := AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK



FUNCTION_BLOCK GetBoolString
  VAR_INPUT
    VALUE : BOOL;
  END_VAR
  VAR_OUTPUT
    CODE : STRING;
  END_VAR

  IF VALUE THEN
    CODE := 'True';
  ELSE
    CODE := 'False';
  END_IF;
END_FUNCTION_BLOCK

FUNCTION_BLOCK Button
  VAR
    ID : STRING;
  END_VAR
  VAR_INPUT
    back_id : STRING;
    sele_id : STRING;
    toggle : BOOL;
    set_state : BOOL;
    state_in : BOOL;
  END_VAR
  VAR_OUTPUT
    state_out : BOOL;
  END_VAR
  VAR
    init_Command : python_eval;
    GetButtonState : GetBoolString;
    setstate_Command : python_eval;
    getstate_Command : python_poll;
    GetButtonToggle : GetBoolString;
    CONCAT2_OUT : STRING;
    CONCAT22_OUT : STRING;
    STRING_TO_INT25_OUT : INT;
    INT_TO_BOOL26_OUT : BOOL;
    AND31_OUT : BOOL;
    CONCAT7_OUT : STRING;
  END_VAR

  GetButtonToggle(VALUE := toggle);
  CONCAT2_OUT := CONCAT('createSVGUIControl("button",back_id="', back_id, '",sele_id="', sele_id, '",toggle=', GetButtonToggle.CODE, ',active=True)');
  init_Command(TRIG := BOOL#1, CODE := CONCAT2_OUT);
  ID := init_Command.RESULT;
  CONCAT22_OUT := CONCAT('int(getAttr(', ID, ',"state",False))');
  getstate_Command(TRIG := init_Command.ACK, CODE := CONCAT22_OUT);
  STRING_TO_INT25_OUT := STRING_TO_INT(getstate_Command.RESULT);
  INT_TO_BOOL26_OUT := INT_TO_BOOL(STRING_TO_INT25_OUT);
  state_out := INT_TO_BOOL26_OUT;
  AND31_OUT := AND(init_Command.ACK, set_state);
  GetButtonState(VALUE := state_in);
  CONCAT7_OUT := CONCAT('setAttr(', ID, ',"state",', GetButtonState.CODE, ')');
  setstate_Command(TRIG := AND31_OUT, CODE := CONCAT7_OUT);
END_FUNCTION_BLOCK

FUNCTION_BLOCK Led
  VAR
    ID : STRING;
  END_VAR
  VAR_INPUT
    back_id : STRING;
    sele_id : STRING;
    state_in : BOOL;
  END_VAR
  VAR
    init_Command : python_eval;
    setstate_Command : python_poll;
    GetLedState : GetBoolString;
    CONCAT2_OUT : STRING;
    CONCAT7_OUT : STRING;
  END_VAR

  CONCAT2_OUT := CONCAT('createSVGUIControl("button",back_id="', back_id, '",sele_id="', sele_id, '",toggle=True,active=False)');
  init_Command(TRIG := BOOL#1, CODE := CONCAT2_OUT);
  ID := init_Command.RESULT;
  GetLedState(VALUE := state_in);
  CONCAT7_OUT := CONCAT('setAttr(', ID, ',"state",', GetLedState.CODE, ')');
  setstate_Command(TRIG := init_Command.ACK, CODE := CONCAT7_OUT);
END_FUNCTION_BLOCK

FUNCTION_BLOCK TextCtrl
  VAR
    ID : STRING;
  END_VAR
  VAR_INPUT
    back_id : STRING;
    set_text : BOOL;
    text : STRING;
  END_VAR
  VAR
    SVGUI_TEXTCTRL : python_eval;
    setstate_Command : python_eval;
    CONCAT1_OUT : STRING;
    AND31_OUT : BOOL;
    CONCAT12_OUT : STRING;
  END_VAR

  CONCAT1_OUT := CONCAT('createSVGUIControl("textControl", back_id="', back_id, '")');
  SVGUI_TEXTCTRL(TRIG := BOOL#1, CODE := CONCAT1_OUT);
  ID := SVGUI_TEXTCTRL.RESULT;
  AND31_OUT := AND(SVGUI_TEXTCTRL.ACK, set_text);
  CONCAT12_OUT := CONCAT('setAttr(', ID, ',"text","', text, '")');
  setstate_Command(TRIG := AND31_OUT, CODE := CONCAT12_OUT);
END_FUNCTION_BLOCK


PROGRAM mainServer1
  VAR
    python_eval0 : python_eval;
    trigger : BOOL := False;
    trigger0 : BOOL := False;
    s_out : STRING;
    d_value : LREAL;
    python_eval1 : python_eval;
    NOT8_OUT : BOOL;
    STRING_TO_LREAL10_OUT : LREAL;
    NOT4_OUT : BOOL;
  END_VAR

  NOT8_OUT := NOT(trigger);
  trigger := NOT8_OUT;
  python_eval0(TRIG := NOT8_OUT, CODE := 'load_socket_node(5, 0x1000+7)');
  STRING_TO_LREAL10_OUT := STRING_TO_LREAL(python_eval0.RESULT);
  d_value := STRING_TO_LREAL10_OUT;
  NOT4_OUT := NOT(trigger0);
  trigger0 := NOT4_OUT;
  python_eval1(TRIG := NOT4_OUT, CODE := 'set_socket_node(5,0x1000+8,3,1968)');
END_PROGRAM

FUNCTION_BLOCK load_socket_node
  VAR
    pyTrigger : BOOL;
  END_VAR
  VAR_INPUT
    id_Node : INT := 1;
    id_Obj : INT := 4096;
    id_SubObj : INT := 0;
  END_VAR
  VAR
    python_eval0 : python_eval;
  END_VAR
  VAR_OUTPUT
    d_value : LREAL;
  END_VAR
  VAR
    NOT2_OUT : BOOL;
    set_load_param8_OUT : STRING;
    STRING_TO_LREAL1_OUT : LREAL;
  END_VAR

  NOT2_OUT := NOT(pyTrigger);
  pyTrigger := NOT2_OUT;
  set_load_param8_OUT := set_load_param(id_Node, id_Obj, id_SubObj);
  python_eval0(TRIG := NOT2_OUT, CODE := set_load_param8_OUT);
  STRING_TO_LREAL1_OUT := STRING_TO_LREAL(python_eval0.RESULT);
  d_value := STRING_TO_LREAL1_OUT;
END_FUNCTION_BLOCK

FUNCTION set_load_param : STRING
  VAR_INPUT
    id_Node : INT;
    id_Obj : INT;
    id_SubObj : INT;
  END_VAR

  set_load_param:=CONCAT('load_socket_node(',INT_TO_STRING(id_Node),',',INT_TO_STRING(id_Obj),')');
END_FUNCTION

PROGRAM mainServer
  VAR
    id_Node : INT := 5;
    i_Obj : INT := 4103;
    i_SubObj : INT := 0;
    trigger0 : BOOL := False;
    s_out : STRING;
    d_value : LREAL;
    d_val_out_1 : REAL;
    python_eval1 : python_eval;
    load_socket_node0 : load_socket_node;
    INTEGRAL0 : INTEGRAL;
    cycle : STRING := '0:0:1';
    NOT14_OUT : BOOL;
    LREAL_TO_REAL19_OUT : REAL;
    STRING_TO_TIME21_OUT : TIME;
  END_VAR

  load_socket_node0(id_Node := id_Node, id_Obj := i_Obj, id_SubObj := i_SubObj);
  d_value := load_socket_node0.d_value;
  NOT14_OUT := NOT(trigger0);
  LREAL_TO_REAL19_OUT := LREAL_TO_REAL(d_value);
  STRING_TO_TIME21_OUT := STRING_TO_TIME(cycle);
  INTEGRAL0(RUN := trigger0, R1 := NOT14_OUT, XIN := LREAL_TO_REAL19_OUT, X0 := 0.1, CYCLE := STRING_TO_TIME21_OUT);
  d_val_out_1 := INTEGRAL0.XOUT;
  trigger0 := NOT14_OUT;
  python_eval1(CODE := 'set_socket_node(5,0x1000+8,3,1968)');
END_PROGRAM


CONFIGURATION config
  VAR_GLOBAL
    debug : INT := 0;
    PATH : STRING := 'C:\\users\\user\\Beremiz\\beremiz_workdir\\';
    i_status : INT := 1;
    host : STRING := 'localhost';
    PORT : INT := 8889;
    INFO : INT := 1;
    WARNING : INT := 2;
    ERROR : INT := 3;
  END_VAR

  RESOURCE resource1 ON PLC
    TASK taskServer(INTERVAL := T#1s0ms,PRIORITY := 0);
    PROGRAM srv WITH taskServer : mainServer;
  END_RESOURCE
END_CONFIGURATION
