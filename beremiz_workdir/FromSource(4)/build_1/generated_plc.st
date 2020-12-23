TYPE
  datatype0 : STRUCT
    _1NJ20T001 : STRING := '_1NJ20T001.csv';
    _1CV20T001 : STRING := '_1CV20T001.csv';
    Rashod_1 : STRING := 'Rashod_1.csv';
    Rashod_2 : STRING := 'Rashod_2.csv';
    PID_1 : STRING := 'PID_1.csv';
    PID_2 : STRING := 'PID_2.csv';
    PID_3 : STRING := 'PID_3.csv';
    IN : STRING := 'IN';
    OUT : STRING := 'OUT';
    IBM : STRING := 'IBM.csv';
    Amper : STRING := 'Amper';
    Amper_A : STRING := 'Amper_A';
    Amper_B : STRING := 'Amper_B';
    Amper_C : STRING := 'Amper_C';
  END_STRUCT;
  StateMachine : (STANDBY, START, STOP);
END_TYPE

FUNCTION writeSignalCSV : STRING
  VAR_INPUT
    nameFile : STRING;
  END_VAR

  writeSignalCSV:=CONCAT('writeCSV("',nameFile,'")');
END_FUNCTION

FUNCTION openCSV : STRING
  VAR_INPUT
    arg : STRING;
  END_VAR

  openCSV:=CONCAT('openCSV("',arg,'")');
END_FUNCTION

FUNCTION readSignal : STRING
  VAR_INPUT
    arg : STRING;
  END_VAR

  readSignal:=CONCAT('readSignal("',arg,'")');
END_FUNCTION

FUNCTION_BLOCK SourceFromFile
  VAR
    pyTrigger : BOOL;
  END_VAR
  VAR_INPUT
    nameFileFB : STRING := '_1NJ20T001.csv';
  END_VAR
  VAR_OUTPUT
    value_outFB : REAL;
  END_VAR
  VAR
    python_eval0 : python_eval;
    str_func : STRING;
    NOT2_OUT : BOOL;
    readSignal11_OUT : STRING;
    STRING_TO_REAL5_OUT : REAL;
  END_VAR

  NOT2_OUT := NOT(pyTrigger);
  pyTrigger := NOT2_OUT;
  readSignal11_OUT := readSignal(nameFileFB);
  python_eval0(TRIG := NOT2_OUT, CODE := readSignal11_OUT);
  STRING_TO_REAL5_OUT := STRING_TO_REAL(python_eval0.RESULT);
  value_outFB := STRING_TO_REAL5_OUT;
END_FUNCTION_BLOCK

PROGRAM DG
  VAR
    SourceFromFile0 : SourceFromFile;
    SourceFromFile1 : SourceFromFile;
    IN1 : datatype0;
    IN2 : datatype0;
    Exp_IN : INT := 3;
    Val_OUT : REAL;
    Rashod_1_IN : REAL;
    Rashod_2_IN : REAL;
    SQRT5_OUT : REAL;
    EXPT6_OUT : REAL;
    ADD8_OUT : REAL;
  END_VAR

  SourceFromFile0(nameFileFB := IN1.Rashod_1);
  Rashod_1_IN := SourceFromFile0.value_outFB;
  SQRT5_OUT := SQRT(Rashod_1_IN);
  EXPT6_OUT := EXPT(Rashod_2_IN, Exp_IN);
  ADD8_OUT := ADD(SQRT5_OUT, EXPT6_OUT);
  Val_OUT := ADD8_OUT;
  SourceFromFile1(nameFileFB := IN2.Rashod_2);
  Rashod_2_IN := SourceFromFile1.value_outFB;
END_PROGRAM

PROGRAM TestSourceFromFile
  VAR_INPUT
    NameFile : STRING := '_1NJ20T002.csv';
  END_VAR
  VAR
    NameFileDataType : datatype0;
  END_VAR
  VAR_EXTERNAL
    ValueOUT : REAL;
  END_VAR
  VAR_OUTPUT
    value_1 : REAL;
  END_VAR
  VAR
    SourceFromFile0 : SourceFromFile;
    SourceFromFile1 : SourceFromFile;
    SourceFromFile2 : SourceFromFile;
    ADD7_OUT : REAL;
  END_VAR

  SourceFromFile0(nameFileFB := NameFile);
  SourceFromFile1(nameFileFB := '_1NJ20T001.csv');
  ADD7_OUT := ADD(SourceFromFile0.value_outFB, SourceFromFile1.value_outFB);
  ValueOUT := ADD7_OUT;
  SourceFromFile2(nameFileFB := NameFileDataType._1NJ20T001);
  value_1 := SourceFromFile2.value_outFB;
END_PROGRAM

FUNCTION get_val_row : STRING
  VAR_INPUT
    nameFile : STRING;
    nameField : STRING;
  END_VAR

  get_val_row:=CONCAT('get_val_row("',nameFile,'","',nameField,'")');
END_FUNCTION

FUNCTION_BLOCK get_value_CSV
  VAR
    pyTrigger : BOOL;
  END_VAR
  VAR_INPUT
    nameFile : STRING;
    nameField : STRING := 'IN';
  END_VAR
  VAR_OUTPUT
    value_outFB : REAL;
  END_VAR
  VAR
    python_eval0 : python_eval;
    NOT2_OUT : BOOL;
    get_val_row15_OUT : STRING;
    STRING_TO_REAL5_OUT : REAL;
  END_VAR

  NOT2_OUT := NOT(pyTrigger);
  pyTrigger := NOT2_OUT;
  get_val_row15_OUT := get_val_row(nameFile, nameField);
  python_eval0(TRIG := NOT2_OUT, CODE := get_val_row15_OUT);
  STRING_TO_REAL5_OUT := STRING_TO_REAL(python_eval0.RESULT);
  value_outFB := STRING_TO_REAL5_OUT;
END_FUNCTION_BLOCK

FUNCTION readSignalCSV : STRING
  VAR_INPUT
    nameFile : STRING;
    i_status : STRING;
  END_VAR

  readSignalCSV:=CONCAT('readSignalCSV("',i_status,'","',nameFile,'")');
END_FUNCTION

FUNCTION_BLOCK SourceFromFileCSV
  VAR
    pyTrigger : BOOL := TRUE;
    pyTriggerOpenCSV : BOOL := TRUE;
  END_VAR
  VAR_INPUT
    nameFileFB : STRING := 'unknow.csv';
  END_VAR
  VAR_OUTPUT
    i_status_readSignal_CSV : INT;
    i_status_writeSignal_CSV : INT;
  END_VAR
  VAR
    python_eval0 : python_eval;
    str_func : STRING;
    python_eval1 : python_eval;
    python_eval2 : python_eval;
    con_writeCSV : STRING;
    NOT2_OUT : BOOL;
    openCSV18_OUT : STRING;
    readSignalCSV24_OUT : STRING;
    STRING_TO_INT21_OUT : INT;
    writeSignalCSV26_OUT : STRING;
    STRING_TO_INT29_OUT : INT;
  END_VAR

  NOT2_OUT := NOT(pyTrigger);
  pyTrigger := NOT2_OUT;
  openCSV18_OUT := openCSV(nameFileFB);
  python_eval1(TRIG := pyTriggerOpenCSV, CODE := openCSV18_OUT);
  readSignalCSV24_OUT := readSignalCSV(nameFileFB, python_eval1.RESULT);
  python_eval0(TRIG := NOT2_OUT, CODE := readSignalCSV24_OUT);
  STRING_TO_INT21_OUT := STRING_TO_INT(python_eval0.RESULT);
  i_status_readSignal_CSV := STRING_TO_INT21_OUT;
  writeSignalCSV26_OUT := writeSignalCSV(nameFileFB);
  python_eval2(TRIG := NOT2_OUT, CODE := writeSignalCSV26_OUT);
  STRING_TO_INT29_OUT := STRING_TO_INT(python_eval2.RESULT);
  i_status_writeSignal_CSV := STRING_TO_INT29_OUT;
END_FUNCTION_BLOCK

FUNCTION set_val_row : STRING
  VAR_INPUT
    nameFile : STRING;
    nameField : STRING;
    value : REAL;
  END_VAR
  VAR
    str_temp : STRING;
  END_VAR

  set_val_row:=CONCAT('set_val_row("',CONCAT(nameFile,'","',nameField),'","',REAL_TO_STRING(value),'")');
END_FUNCTION

FUNCTION_BLOCK set_value_CSV
  VAR
    pyTrigger : BOOL;
  END_VAR
  VAR_INPUT
    nameFile : STRING;
    nameField : STRING := 'IN';
  END_VAR
  VAR_OUTPUT
    i_status : INT;
  END_VAR
  VAR
    python_eval0 : python_eval;
  END_VAR
  VAR_INPUT
    value_IN : REAL;
  END_VAR
  VAR
    NOT2_OUT : BOOL;
    set_val_row17_OUT : STRING;
    STRING_TO_INT19_OUT : INT;
  END_VAR

  NOT2_OUT := NOT(pyTrigger);
  pyTrigger := NOT2_OUT;
  set_val_row17_OUT := set_val_row(nameFile, nameField, value_IN);
  python_eval0(TRIG := NOT2_OUT, CODE := set_val_row17_OUT);
  STRING_TO_INT19_OUT := STRING_TO_INT(python_eval0.RESULT);
  i_status := STRING_TO_INT19_OUT;
END_FUNCTION_BLOCK

PROGRAM TestCSV
  VAR
    pyTriger : BOOL := FALSE;
    Tags : datatype0;
    result : STRING;
    i_status_read_CSV : INT;
    i_status_read_CSV1 : INT;
    i_status_write_CSV : INT;
    i_status_open_CSV : INT;
    val_out_1 : REAL;
    val_out_2 : REAL;
    val_out_3 : REAL;
    val_out_4 : REAL;
    val_out_5 : REAL;
    val_out_6 : REAL;
    val_out_7 : REAL;
    val_out_8 : REAL;
    val_out_9 : REAL;
    val_out_10 : REAL;
    val_out_12 : REAL;
    val_IN : datatype0;
    get_value_CSV0 : get_value_CSV;
    get_value_CSV1 : get_value_CSV;
    SourceFromFileCSV0 : SourceFromFileCSV;
    SourceFromFileCSV1 : SourceFromFileCSV;
    get_value_CSV2 : get_value_CSV;
    get_value_CSV3 : get_value_CSV;
    set_value_CSV0 : set_value_CSV;
    set_value_CSV1 : set_value_CSV;
    set_value_CSV2 : set_value_CSV;
    set_value_CSV3 : set_value_CSV;
    MUL31_OUT : REAL;
    ADD29_OUT : REAL;
  END_VAR

  set_value_CSV0(nameFile := Tags.PID_1, nameField := 'val_out_1', value_IN := val_out_1);
  i_status_write_CSV := set_value_CSV0.i_status;
  SourceFromFileCSV0(nameFileFB := Tags.PID_1);
  i_status_read_CSV := SourceFromFileCSV0.i_status_readSignal_CSV;
  get_value_CSV0(nameFile := Tags.PID_1, nameField := val_IN.IN);
  val_out_1 := get_value_CSV0.value_outFB;
  MUL31_OUT := MUL(val_out_1, val_out_2);
  val_out_6 := MUL31_OUT;
  get_value_CSV1(nameFile := Tags.PID_1, nameField := val_IN.OUT);
  val_out_2 := get_value_CSV1.value_outFB;
  SourceFromFileCSV1(nameFileFB := Tags.PID_2);
  i_status_read_CSV1 := SourceFromFileCSV1.i_status_readSignal_CSV;
  get_value_CSV2(nameFile := Tags.PID_2, nameField := 'IN_1');
  val_out_3 := get_value_CSV2.value_outFB;
  ADD29_OUT := ADD(val_out_3, val_out_4);
  val_out_5 := ADD29_OUT;
  get_value_CSV3(nameFile := Tags.PID_2, nameField := 'IN_2');
  val_out_4 := get_value_CSV3.value_outFB;
  set_value_CSV1(nameFile := Tags.PID_1, nameField := 'val_out_2', value_IN := val_out_2);
  set_value_CSV2(nameFile := Tags.PID_1, nameField := 'val_out_6', value_IN := val_out_6);
  set_value_CSV3(nameFile := Tags.PID_1, nameField := 'VAL_5', value_IN := val_out_5);
END_PROGRAM

PROGRAM TestCSV_v_1
  VAR
    pyTriger : BOOL := FALSE;
    Tags : datatype0;
    result : STRING;
    i_status_read_CSV : INT;
    i_status_read_CSV1 : INT;
    i_status_write_CSV : INT;
    i_status_open_CSV : INT;
    val_out_1 : REAL;
    val_out_2 : REAL;
    val_out_3 : REAL;
    val_out_4 : REAL;
    val_out_5 : REAL;
    val_out_6 : REAL;
    val_out_7 : REAL;
    val_out_8 : REAL;
    val_out_9 : REAL;
    val_out_10 : REAL;
    val_IN : datatype0;
    get_value_CSV0 : get_value_CSV;
    get_value_CSV1 : get_value_CSV;
    SourceFromFileCSV0 : SourceFromFileCSV;
    SourceFromFileCSV1 : SourceFromFileCSV;
    get_value_CSV2 : get_value_CSV;
    get_value_CSV3 : get_value_CSV;
    set_value_CSV0 : set_value_CSV;
    set_value_CSV1 : set_value_CSV;
    set_value_CSV2 : set_value_CSV;
    set_value_CSV3 : set_value_CSV;
    set_value_CSV4 : set_value_CSV;
    set_value_CSV5 : set_value_CSV;
    MUL31_OUT : REAL;
    ADD29_OUT : REAL;
  END_VAR

  set_value_CSV4(nameFile := Tags.PID_2, nameField := 'val_out_3', value_IN := val_out_3);
  get_value_CSV0(nameFile := Tags.PID_1, nameField := val_IN.IN);
  val_out_1 := get_value_CSV0.value_outFB;
  MUL31_OUT := MUL(val_out_1, val_out_2);
  val_out_6 := MUL31_OUT;
  get_value_CSV1(nameFile := Tags.PID_1, nameField := val_IN.OUT);
  val_out_2 := get_value_CSV1.value_outFB;
  get_value_CSV2(nameFile := Tags.PID_2, nameField := 'IN_1');
  val_out_3 := get_value_CSV2.value_outFB;
  ADD29_OUT := ADD(val_out_3, val_out_4);
  val_out_5 := ADD29_OUT;
  get_value_CSV3(nameFile := Tags.PID_2, nameField := 'IN_2');
  val_out_4 := get_value_CSV3.value_outFB;
  set_value_CSV0(nameFile := Tags.PID_1, nameField := 'val_out_1', value_IN := val_out_1);
  SourceFromFileCSV0(nameFileFB := Tags.PID_1);
  set_value_CSV1(nameFile := Tags.PID_1, nameField := 'val_out_2', value_IN := val_out_2);
  set_value_CSV2(nameFile := Tags.PID_1, nameField := 'val_out_6', value_IN := val_out_6);
  SourceFromFileCSV1(nameFileFB := Tags.PID_2);
  set_value_CSV3(nameFile := Tags.PID_1, nameField := 'VAL_5', value_IN := val_out_5);
  set_value_CSV5(nameFile := Tags.PID_2, nameField := 'val_out_4', value_IN := val_out_4);
END_PROGRAM

PROGRAM TestCSV_v_3
  VAR
    pyTriger : BOOL := FALSE;
    Tags : datatype0;
    result : STRING := 'Initial String';
    i_status_read_CSV : INT := 0;
    i_status_read_CSV1 : INT := 0;
    i_status_write_CSV : INT := 0;
    i_status_open_CSV : INT := 0;
    val_out_1 : REAL := 0.0;
    val_out_2 : REAL := 0.0;
    val_out_3 : REAL := 0.0;
    val_IN : datatype0;
    SourceFromFileCSV0 : SourceFromFileCSV;
    get_value_CSV0 : get_value_CSV;
    get_value_CSV1 : get_value_CSV;
    set_value_CSV0 : set_value_CSV;
    set_value_CSV1 : set_value_CSV;
    set_value_CSV2 : set_value_CSV;
    INTEGRAL0 : INTEGRAL;
    run : BOOL := true;
    cycle : STRING := '0:0:1';
    triger : BOOL := false;
    NOT22_OUT : BOOL;
    STRING_TO_TIME23_OUT : TIME;
  END_VAR

  get_value_CSV0(nameFile := 'dg.csv', nameField := 'consumption');
  val_out_1 := get_value_CSV0.value_outFB;
  NOT22_OUT := NOT(triger);
  STRING_TO_TIME23_OUT := STRING_TO_TIME(cycle);
  INTEGRAL0(RUN := run, R1 := NOT22_OUT, XIN := val_out_1, X0 := val_out_2, CYCLE := STRING_TO_TIME23_OUT);
  val_out_3 := INTEGRAL0.XOUT;
  get_value_CSV1(nameFile := 'dg.csv', nameField := 'angle');
  val_out_2 := get_value_CSV1.value_outFB;
  triger := NOT22_OUT;
  SourceFromFileCSV0(nameFileFB := 'dg.csv');
  set_value_CSV0(nameFile := 'dg.csv', nameField := 'val_out_3', value_IN := val_out_3);
  set_value_CSV1(nameFile := 'dg.csv', nameField := 'val_out_1', value_IN := val_out_1);
  set_value_CSV2(nameFile := 'dg.csv', nameField := 'val_out_2', value_IN := val_out_2);
END_PROGRAM

PROGRAM TestCSV_v_2
  VAR
    pyTriger : BOOL := FALSE;
    Tags : datatype0;
    result : STRING := 'Initial String';
    i_status_read_CSV : INT := 0;
    i_status_read_CSV1 : INT := 0;
    i_status_write_CSV : INT := 0;
    i_status_open_CSV : INT := 0;
    val_out_1 : REAL := 0.0;
    val_out_2 : REAL := 0.0;
    val_out_3 : REAL := 0.0;
    val_out_4 : REAL := 0.0;
    val_out_5 : REAL := 0.0;
    val_out_6 : REAL := 0.0;
    val_out_7 : REAL := 0.0;
    val_out_8 : REAL := 0.0;
    val_out_9 : REAL := 0.0;
    val_out_10 : REAL := 0.0;
    val_out_11 : REAL := 10.0;
    val_IN : datatype0;
    SourceFromFileCSV0 : SourceFromFileCSV;
    get_value_CSV0 : get_value_CSV;
    get_value_CSV1 : get_value_CSV;
    set_value_CSV0 : set_value_CSV;
    set_value_CSV1 : set_value_CSV;
    set_value_CSV2 : set_value_CSV;
    ADD9_OUT : REAL;
  END_VAR

  get_value_CSV0(nameFile := 'PID_1.csv', nameField := 'IN_1');
  val_out_1 := get_value_CSV0.value_outFB;
  ADD9_OUT := ADD(val_out_1, val_out_2);
  val_out_3 := ADD9_OUT;
  get_value_CSV1(nameFile := 'PID_1.csv', nameField := 'IN_2');
  val_out_2 := get_value_CSV1.value_outFB;
  SourceFromFileCSV0(nameFileFB := 'PID_1.csv');
  set_value_CSV0(nameFile := 'PID_1.csv', nameField := 'val_out_3', value_IN := val_out_3);
  set_value_CSV1(nameFile := 'PID_1.csv', nameField := 'val_out_1', value_IN := val_out_1);
  set_value_CSV2(nameFile := 'PID_1.csv', nameField := 'val_out_2', value_IN := val_out_2);
END_PROGRAM


CONFIGURATION config
  VAR_GLOBAL
    Global_RS : RS;
    Test_Python_Var : INT := 4;
    Second_Python_Var : INT := 5;
    debug : INT := 3;
    PATH : STRING := 'D:\\beremiz_workdir\\';
    Grumpf : STRING := 'Grumpf_value';
    i_status : INT := 1;
    i_status_CSV : INT := 1;
    NameFile : STRING := '_1NJ20T001.csv';
    NameFileCSV : STRING := 'unknow.csv';
    WRITE_OK : INT;
    WRITE_FAIL : INT;
    READ_OK : INT;
    READ_FAIL : INT;
    NEXT_OK : INT;
    NEXT_FAIL : INT;
    OPEN_DICT_OK : INT := 3;
    OPEN_DICT_FAIL : INT;
    OPEN_CSV_OK : INT;
    OPEN_CSV_FAIL : INT;
    UPDATE_OK : INT;
    FILE_EOF : INT;
    UPDATE_FAIL : INT;
    SET_VAL_OK : INT;
    SET_VAL_FAIL : INT;
    FILE_NOT_FOUND : INT;
    CLOSE_CSV_OK : INT;
    CLOSE_CSV_FAIL : INT;
    SAVE_CSV_OK : INT;
    SAVE_CSV_FAIL : INT;
    SIGNAL_NOT_CONNECT : INT;
    INFO : INT := 1;
    WARNING : INT := 2;
    ERROR : INT := 3;
  END_VAR

  RESOURCE res_pytest ON PLC
    VAR_GLOBAL
      ValueOUT : REAL;
    END_VAR
    TASK pytest_task(INTERVAL := T#100ms,PRIORITY := 0);
    PROGRAM MyProg : TestCSV_v_3;
  END_RESOURCE
END_CONFIGURATION
