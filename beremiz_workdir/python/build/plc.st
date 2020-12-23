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


TYPE
  CPLX_TYPE : STRUCT
    FIRSTBYTE : SINT;
    SECONDBYTE : SINT;
  END_STRUCT;
  StateMachine : (STANDBY, START, STOP);
END_TYPE

FUNCTION_BLOCK C_Pragma
  VAR_OUTPUT
    OUT : SINT;
  END_VAR
  VAR_INPUT
    IN : SINT;
  END_VAR
  VAR
    COORDS : ARRAY [0..5] OF SINT := [54, 55, 56, 57, 58, 59];
    SMURF : CPLX_TYPE;
  END_VAR
  VAR_EXTERNAL
    Global_RS : RS;
  END_VAR

  (* hereafter is a C pragma accessing FB interface in a clean way *)
  {{
    char toPLC;
    char fromPLC = GetFbVar(IN);
    if(PLC_C_Call(fromPLC, &toPLC)){
      SetFbVar(OUT, toPLC);
    }
    if(0){
      /* that code demonstrate C access to complex types */
      char somebyte = GetFbVar(COORDS, .table[3]);
      SetFbVar(SMURF, somebyte, .FIRSTBYTE);
      SetFbVar(COORDS, somebyte, .table[4]);
    }
  }}
  (* If you do not use __GET_VAR and _SET_VAR macro, expect unexpected *)
  Global_RS();
END_FUNCTION_BLOCK

PROGRAM main_pytest
  VAR
    pytest_var1 : STRING;
    pytest_var2 : BOOL;
    py1 : python_eval;
    Block1 : python_eval;
    Block2 : python_eval;
    Block3 : python_eval;
    pytest_var3 : BOOL;
    FromC : SINT;
    C_Pragma0 : C_Pragma;
  END_VAR
  VAR
    TestInput AT %IB1.0 : SINT;
    TestOutput AT %QB1.0 : SINT;
  END_VAR
  VAR
    FromInput : SINT;
    Test_BCD : WORD := 300;
    Test_BCD_RESULT : UINT;
    Test_BCD_ENO : BOOL;
    Test_DT : DT := DT#2013-02-23-22:35:46;
    Test_TOD : TOD;
    Test_TOD_STRING : STRING;
    Test_Date : DATE;
    Test_String : STRING := 'test';
    Test_Bool : BOOL;
  END_VAR
  VAR_EXTERNAL
    Global_RS : RS;
  END_VAR
  VAR
    NOT7_OUT : BOOL;
    MUX21_OUT : BOOL;
    MUX17_OUT : STRING;
    BCD_TO_UINT35_ENO : BOOL;
    BCD_TO_UINT35_OUT : UINT;
    DATE_AND_TIME_TO_TIME_OF_DAY37_OUT : TOD;
    TOD_TO_STRING55_OUT : STRING;
    DATE_AND_TIME_TO_DATE38_OUT : DATE;
    BYTE_TO_STRING46_OUT : STRING;
    STRING_TO_BOOL44_OUT : BOOL;
    AND51_OUT : BOOL;
    OR41_OUT : BOOL;
  END_VAR

  NOT7_OUT := NOT(pytest_var2);
  py1(TRIG := NOT7_OUT, CODE := 'time.sleep(1)');
  Block1(TRIG := NOT7_OUT, CODE := 'sys.stdout.write("FBID :"+str(FBID)+"\n")');
  Block2(TRIG := NOT7_OUT, CODE := 'PLCBinary.Simple_C_Call(5678)');
  Block3(TRIG := NOT7_OUT, CODE := 'MyPythonFunc(42)');
  MUX21_OUT := MUX(3, py1.ACK, Block1.ACK, Block2.ACK, Block3.ACK);
  pytest_var3 := MUX21_OUT;
  pytest_var2 := NOT7_OUT;
  MUX17_OUT := MUX(3, py1.RESULT, Block1.RESULT, Block2.RESULT, Block3.RESULT);
  pytest_var1 := MUX17_OUT;
  C_Pragma0(IN := 23);
  FromC := C_Pragma0.OUT;
  TestOutput := 10;
  BCD_TO_UINT35_OUT := BCD_TO_UINT(IN := Test_BCD, ENO => BCD_TO_UINT35_ENO);
  Test_BCD_ENO := BCD_TO_UINT35_ENO;
  Test_BCD_RESULT := BCD_TO_UINT35_OUT;
  FromInput := TestInput;
  DATE_AND_TIME_TO_TIME_OF_DAY37_OUT := DATE_AND_TIME_TO_TIME_OF_DAY(Test_DT);
  Test_TOD := DATE_AND_TIME_TO_TIME_OF_DAY37_OUT;
  TOD_TO_STRING55_OUT := TOD_TO_STRING(Test_TOD);
  Test_TOD_STRING := TOD_TO_STRING55_OUT;
  DATE_AND_TIME_TO_DATE38_OUT := DATE_AND_TIME_TO_DATE(Test_DT);
  Test_Date := DATE_AND_TIME_TO_DATE38_OUT;
  BYTE_TO_STRING46_OUT := BYTE_TO_STRING(BYTE#145);
  Test_String := BYTE_TO_STRING46_OUT;
  STRING_TO_BOOL44_OUT := STRING_TO_BOOL('True');
  Test_Bool := STRING_TO_BOOL44_OUT;
  AND51_OUT := AND(NOT(Global_RS.Q1), BOOL#TRUE);
  Global_RS.S := AND51_OUT;
  OR41_OUT := OR(Global_RS.Q1, BOOL#FALSE);
  Global_RS.R1 := OR41_OUT;
END_PROGRAM

FUNCTION norm : REAL
  VAR_INPUT
    IN1 : REAL;
    IN2 : REAL;
  END_VAR

  NORM := SQRT(IN1 * IN1 + IN2 * IN2);
END_FUNCTION


CONFIGURATION conf_pytest
  VAR_GLOBAL
    Global_RS : RS;
    Test_Python_Var : INT := 4;
    Second_Python_Var : INT := 5;
    SomeVarName : DINT;
    Grumpf : STRING;
  END_VAR

  RESOURCE res_pytest ON PLC
    VAR_GLOBAL
      TOTO : INT;
    END_VAR
    TASK pytest_task(INTERVAL := T#1s0ms,PRIORITY := 0);
    PROGRAM pytest_instance : main_pytest;
  END_RESOURCE
END_CONFIGURATION
