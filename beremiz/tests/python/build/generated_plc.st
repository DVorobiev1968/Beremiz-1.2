TYPE
  CPLX_TYPE : STRUCT
    FIRSTBYTE : SINT;
    SECONDBYTE : SINT;
  END_STRUCT;
  StateMachine : (STANDBY, START, STOP);
  datatype0 : BOOL;
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
    extern int PLC_C_Call(char, char *);
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
  (* If you do not use GetFbVar and SetFbVar macros, expect unexpected behaviour*)
  Global_RS();
END_FUNCTION_BLOCK

FUNCTION function0 : datatype0
  VAR_INPUT
    LocalVar0 : datatype0;
  END_VAR

  function0 := LocalVar0;
END_FUNCTION

PROGRAM main_pytest
  VAR
    mux1_sel : INT := 3;
    mux2_sel : INT := 3;
    pytest_var1 : STRING;
    fefvsd : datatype0;
    pytest_var2 : BOOL;
    py1 : python_eval;
    Block1 : python_eval;
    Block2 : python_eval;
    Block3 : python_eval;
    pytest_var3 : BOOL;
    FromC : SINT;
    C_Pragma0 : C_Pragma;
  END_VAR
  VAR_EXTERNAL
    TestInput : SINT;
    TestOutput : SINT;
  END_VAR
  VAR
    FromInput : SINT;
    Test_BCD : WORD := 151;
    Test_BCD_WRONG : WORD := 154;
    Test_BCD_CONVERTED : BOOL;
    Test_BCD_RESULT : UINT;
    Test_BCD_WRONG_RESULT : UINT;
    Test_DT : DT := DT#2013-02-23-22:35:46;
    Test_TOD : TOD;
    Test_TOD_STRING : STRING;
    Test_Date : DATE;
    Test_String : STRING := 'test';
    Test_Bool : BOOL;
  END_VAR
  VAR_EXTERNAL
    Global_RS : RS;
    TUTU : INT;
    TOTO : INT;
    Test_Python_Var : INT;
    Second_Python_Var : INT;
  END_VAR
  VAR
    NOT7_OUT : BOOL;
    MUX21_OUT : BOOL;
    MUX17_OUT : STRING;
    function061_OUT : datatype0;
    BCD_TO_UINT35_OUT : UINT;
    BCD_TO_UINT67_ENO : BOOL;
    BCD_TO_UINT67_OUT : UINT;
    DATE_AND_TIME_TO_TIME_OF_DAY37_OUT : TOD;
    TOD_TO_STRING55_OUT : STRING;
    DATE_AND_TIME_TO_DATE38_OUT : DATE;
    INT_TO_STRING46_OUT : STRING;
    STRING_TO_BOOL44_OUT : BOOL;
    AND51_OUT : BOOL;
    OR41_OUT : BOOL;
  END_VAR

  NOT7_OUT := NOT(pytest_var2);
  py1(TRIG := NOT7_OUT, CODE := 'time.sleep(1)');
  Block1(TRIG := NOT7_OUT, CODE := 'sys.stdout.write("FBID :"+str(FBID)+"\n")');
  Block2(TRIG := NOT7_OUT, CODE := 'PLCBinary.Simple_C_Call(5678)');
  Block3(TRIG := NOT7_OUT, CODE := 'MyPythonFunc(42)');
  MUX21_OUT := MUX(mux1_sel, py1.ACK, Block1.ACK, Block2.ACK, Block3.ACK);
  pytest_var3 := MUX21_OUT;
  pytest_var2 := NOT7_OUT;
  MUX17_OUT := MUX(mux2_sel, py1.RESULT, Block1.RESULT, Block2.RESULT, Block3.RESULT);
  pytest_var1 := MUX17_OUT;
  C_Pragma0(IN := 23);
  FromC := C_Pragma0.OUT;
  TestOutput := 10;
  FromInput := TestInput;
  function061_OUT := function0(fefvsd);
  fefvsd := function061_OUT;
  Test_Python_Var := 23;
  BCD_TO_UINT35_OUT := BCD_TO_UINT(Test_BCD);
  Test_BCD_RESULT := BCD_TO_UINT35_OUT;
  BCD_TO_UINT67_OUT := BCD_TO_UINT(IN := Test_BCD_WRONG, ENO => BCD_TO_UINT67_ENO);
  Test_BCD_CONVERTED := BCD_TO_UINT67_ENO;
  Test_BCD_WRONG_RESULT := BCD_TO_UINT67_OUT;
  DATE_AND_TIME_TO_TIME_OF_DAY37_OUT := DATE_AND_TIME_TO_TIME_OF_DAY(Test_DT);
  Test_TOD := DATE_AND_TIME_TO_TIME_OF_DAY37_OUT;
  TOD_TO_STRING55_OUT := TOD_TO_STRING(Test_TOD);
  Test_TOD_STRING := TOD_TO_STRING55_OUT;
  DATE_AND_TIME_TO_DATE38_OUT := DATE_AND_TIME_TO_DATE(Test_DT);
  Test_Date := DATE_AND_TIME_TO_DATE38_OUT;
  INT_TO_STRING46_OUT := INT_TO_STRING(Second_Python_Var);
  Test_String := INT_TO_STRING46_OUT;
  STRING_TO_BOOL44_OUT := STRING_TO_BOOL('True');
  Test_Bool := STRING_TO_BOOL44_OUT;
  AND51_OUT := AND(NOT(Global_RS.Q1), BOOL#TRUE);
  Global_RS.S := AND51_OUT;
  OR41_OUT := OR(Global_RS.Q1, BOOL#FALSE);
  Global_RS.R1 := OR41_OUT;
  TOTO := 42;
  TUTU := 42;
END_PROGRAM

FUNCTION norm : REAL
  VAR_INPUT
    IN1 : REAL;
    IN2 : REAL;
  END_VAR

  NORM := SQRT(IN1 * IN1 + IN2 * IN2);
END_FUNCTION


CONFIGURATION config
  VAR_GLOBAL
    Global_RS : RS;
    TUTU : INT;
    Test_Python_Var : INT := 4;
    Second_Python_Var : INT := 5;
    TestInput : SINT := 0;
    TestOutput : SINT;
    SomeVarName : DINT;
    Grumpf : STRING;
  END_VAR

  RESOURCE res_pytest ON PLC
    VAR_GLOBAL
      TOTO : INT;
    END_VAR
    TASK pytest_task(INTERVAL := T#1ms,PRIORITY := 0);
    PROGRAM pytest_instance : main_pytest;
  END_RESOURCE
END_CONFIGURATION
