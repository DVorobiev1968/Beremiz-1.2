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
