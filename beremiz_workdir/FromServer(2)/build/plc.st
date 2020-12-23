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


FUNCTION call_method : STRING
  VAR_INPUT
    id_Node : INT;
    nameFunction : STRING;
    id_Obj : INT;
    id_SubObj : INT;
    d_value : REAL;
  END_VAR

  call_method:=CONCAT(nameFunction,INT_TO_STRING(id_Node),',',INT_TO_STRING(id_Obj),',',REAL_TO_STRING(d_value),')');
END_FUNCTION

FUNCTION_BLOCK load_socket_node
  VAR
    pyTrigger : BOOL;
    nameFunction : STRING := 'load_socket_node(';
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
    d_value : REAL;
  END_VAR
  VAR
    NOT2_OUT : BOOL;
    call_method8_OUT : STRING;
    STRING_TO_REAL12_OUT : REAL;
  END_VAR

  NOT2_OUT := NOT(pyTrigger);
  pyTrigger := NOT2_OUT;
  call_method8_OUT := call_method(id_Node, nameFunction, id_Obj, id_SubObj, 0.0);
  python_eval0(TRIG := NOT2_OUT, CODE := call_method8_OUT);
  STRING_TO_REAL12_OUT := STRING_TO_REAL(python_eval0.RESULT);
  d_value := STRING_TO_REAL12_OUT;
END_FUNCTION_BLOCK

FUNCTION_BLOCK set_socket_node
  VAR
    pyTrigger : BOOL;
    nameFunction : STRING := 'set_socket_node(';
  END_VAR
  VAR_INPUT
    id_Node : INT := 1;
    id_Obj : INT := 4097;
    id_SubObj : INT := 0;
  END_VAR
  VAR
    python_eval0 : python_eval;
  END_VAR
  VAR_INPUT
    d_value : REAL;
  END_VAR
  VAR
    NOT2_OUT : BOOL;
    call_method8_OUT : STRING;
  END_VAR

  NOT2_OUT := NOT(pyTrigger);
  pyTrigger := NOT2_OUT;
  call_method8_OUT := call_method(id_Node, nameFunction, id_Obj, id_SubObj, d_value);
  python_eval0(TRIG := NOT2_OUT, CODE := call_method8_OUT);
END_FUNCTION_BLOCK

PROGRAM mainServer
  VAR
    id_Node : INT := 1;
    i_Obj : INT := 4096;
    i_Obj_1 : INT := 4097;
    i_SubObj : INT := 0;
    trigger0 : BOOL := False;
    s_out : STRING;
    d_value : REAL;
    d_val_out_1 : REAL;
    load_socket_node0 : load_socket_node;
    INTEGRAL0 : INTEGRAL;
    cycle : STRING := '0:0:1';
    set_socket_node0 : set_socket_node;
    NOT14_OUT : BOOL;
    STRING_TO_TIME21_OUT : TIME;
  END_VAR

  set_socket_node0(id_Node := id_Node, id_Obj := i_Obj_1, id_SubObj := i_SubObj, d_value := d_val_out_1);
  load_socket_node0(id_Node := id_Node, id_Obj := i_Obj, id_SubObj := i_SubObj);
  d_value := load_socket_node0.d_value;
  NOT14_OUT := NOT(trigger0);
  STRING_TO_TIME21_OUT := STRING_TO_TIME(cycle);
  INTEGRAL0(RUN := trigger0, R1 := NOT14_OUT, XIN := d_value, X0 := 0.1, CYCLE := STRING_TO_TIME21_OUT);
  d_val_out_1 := INTEGRAL0.XOUT;
  trigger0 := NOT14_OUT;
END_PROGRAM

PROGRAM test_1
  VAR
    id_Node : INT := 1;
    i_Obj : INT := 4096;
    i_Obj_1 : INT := 4097;
    i_SubObj : INT := 0;
    trigger0 : BOOL := False;
    s_out : STRING;
    d_value : REAL;
    d_val_out_1 : REAL;
    load_socket_node0 : load_socket_node;
    cycle : STRING := '0:0:1';
    set_socket_node0 : set_socket_node;
    EXPT31_OUT : REAL;
  END_VAR

  set_socket_node0(id_Node := id_Node, id_Obj := i_Obj_1, id_SubObj := i_SubObj, d_value := EXPT31_OUT);
  load_socket_node0(id_Node := id_Node, id_Obj := i_Obj, id_SubObj := i_SubObj);
  d_value := load_socket_node0.d_value;
  EXPT31_OUT := EXPT(d_value, 2);
  d_val_out_1 := EXPT31_OUT;
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
    TASK taskServer(INTERVAL := T#50ms,PRIORITY := 0);
    PROGRAM srv WITH taskServer : test_1;
  END_RESOURCE
END_CONFIGURATION
