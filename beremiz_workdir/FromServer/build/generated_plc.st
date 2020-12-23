PROGRAM mainServer
  VAR
    python_eval0 : python_eval;
    trigger : BOOL := False;
    trigger0 : BOOL := False;
    s_out : STRING;
    python_eval1 : python_eval;
  END_VAR

  python_eval0(TRIG := trigger, CODE := 'getValue()');
  s_out := python_eval0.RESULT;
  python_eval1(TRIG := trigger0, CODE := 'main()');
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
