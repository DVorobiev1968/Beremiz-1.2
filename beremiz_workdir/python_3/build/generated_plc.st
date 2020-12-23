PROGRAM main
  VAR
    In : INT;
    Out : INT;
    b_Triger : BOOL := False;
    python_eval0 : python_eval;
    NOT2_OUT : BOOL;
    STRING_TO_INT5_OUT : INT;
  END_VAR

  NOT2_OUT := NOT(b_Triger);
  b_Triger := NOT2_OUT;
  python_eval0(TRIG := NOT2_OUT, CODE := 'random.randon()');
  STRING_TO_INT5_OUT := STRING_TO_INT(python_eval0.RESULT);
  Out := STRING_TO_INT5_OUT;
END_PROGRAM


CONFIGURATION config
  VAR_GLOBAL
    Test_Python_Var : INT := 4;
    Second_Python_Var : INT := 5;
    test : INT := 1;
  END_VAR

  RESOURCE resource1 ON PLC
    TASK main_task(INTERVAL := T#1s0ms,PRIORITY := 0);
    PROGRAM maiin : main;
  END_RESOURCE
END_CONFIGURATION
