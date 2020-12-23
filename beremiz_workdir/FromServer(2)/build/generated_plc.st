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