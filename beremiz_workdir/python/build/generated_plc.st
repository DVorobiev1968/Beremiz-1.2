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
