void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->ADD10_OUT,0,retain)
  __INIT_VAR(data__->EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEL15_OUT,0,retain)
  __INIT_VAR(data__->AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->ADD10_OUT,)));
  __SET_VAR(data__->,SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (UINT)__GET_VAR(data__->ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->SEL15_OUT,));
  __SET_VAR(data__->,AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void GETBOOLSTRING_init__(GETBOOLSTRING *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->VALUE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
}

// Code part
void GETBOOLSTRING_body__(GETBOOLSTRING *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->VALUE,)) {
    __SET_VAR(data__->,CODE,,__STRING_LITERAL(4,"True"));
  } else {
    __SET_VAR(data__->,CODE,,__STRING_LITERAL(5,"False"));
  };

  goto __end;

__end:
  return;
} // GETBOOLSTRING_body__() 





void BUTTON_init__(BUTTON *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ID,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->BACK_ID,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->SELE_ID,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TOGGLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SET_STATE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATE_IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATE_OUT,__BOOL_LITERAL(FALSE),retain)
  PYTHON_EVAL_init__(&data__->INIT_COMMAND,retain);
  GETBOOLSTRING_init__(&data__->GETBUTTONSTATE,retain);
  PYTHON_EVAL_init__(&data__->SETSTATE_COMMAND,retain);
  PYTHON_POLL_init__(&data__->GETSTATE_COMMAND,retain);
  GETBOOLSTRING_init__(&data__->GETBUTTONTOGGLE,retain);
  __INIT_VAR(data__->CONCAT2_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->CONCAT22_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STRING_TO_INT25_OUT,0,retain)
  __INIT_VAR(data__->INT_TO_BOOL26_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AND31_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CONCAT7_OUT,__STRING_LITERAL(0,""),retain)
}

// Code part
void BUTTON_body__(BUTTON *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->GETBUTTONTOGGLE.,VALUE,,__GET_VAR(data__->TOGGLE,));
  GETBOOLSTRING_body__(&data__->GETBUTTONTOGGLE);
  __SET_VAR(data__->,CONCAT2_OUT,,CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)7,
    (STRING)__STRING_LITERAL(37,"createSVGUIControl(\"button\",back_id=\""),
    (STRING)__GET_VAR(data__->BACK_ID,),
    (STRING)__STRING_LITERAL(11,"\",sele_id=\""),
    (STRING)__GET_VAR(data__->SELE_ID,),
    (STRING)__STRING_LITERAL(9,"\",toggle="),
    (STRING)__GET_VAR(data__->GETBUTTONTOGGLE.CODE,),
    (STRING)__STRING_LITERAL(13,",active=True)")));
  __SET_VAR(data__->INIT_COMMAND.,TRIG,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->INIT_COMMAND.,CODE,,__GET_VAR(data__->CONCAT2_OUT,));
  PYTHON_EVAL_body__(&data__->INIT_COMMAND);
  __SET_VAR(data__->,ID,,__GET_VAR(data__->INIT_COMMAND.RESULT,));
  __SET_VAR(data__->,CONCAT22_OUT,,CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)3,
    (STRING)__STRING_LITERAL(12,"int(getAttr("),
    (STRING)__GET_VAR(data__->ID,),
    (STRING)__STRING_LITERAL(16,",\"state\",False))")));
  __SET_VAR(data__->GETSTATE_COMMAND.,TRIG,,__GET_VAR(data__->INIT_COMMAND.ACK,));
  __SET_VAR(data__->GETSTATE_COMMAND.,CODE,,__GET_VAR(data__->CONCAT22_OUT,));
  PYTHON_POLL_body__(&data__->GETSTATE_COMMAND);
  __SET_VAR(data__->,STRING_TO_INT25_OUT,,STRING_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (STRING)__GET_VAR(data__->GETSTATE_COMMAND.RESULT,)));
  __SET_VAR(data__->,INT_TO_BOOL26_OUT,,INT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->STRING_TO_INT25_OUT,)));
  __SET_VAR(data__->,STATE_OUT,,__GET_VAR(data__->INT_TO_BOOL26_OUT,));
  __SET_VAR(data__->,AND31_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->INIT_COMMAND.ACK,),
    (BOOL)__GET_VAR(data__->SET_STATE,)));
  __SET_VAR(data__->GETBUTTONSTATE.,VALUE,,__GET_VAR(data__->STATE_IN,));
  GETBOOLSTRING_body__(&data__->GETBUTTONSTATE);
  __SET_VAR(data__->,CONCAT7_OUT,,CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)5,
    (STRING)__STRING_LITERAL(8,"setAttr("),
    (STRING)__GET_VAR(data__->ID,),
    (STRING)__STRING_LITERAL(9,",\"state\","),
    (STRING)__GET_VAR(data__->GETBUTTONSTATE.CODE,),
    (STRING)__STRING_LITERAL(1,")")));
  __SET_VAR(data__->SETSTATE_COMMAND.,TRIG,,__GET_VAR(data__->AND31_OUT,));
  __SET_VAR(data__->SETSTATE_COMMAND.,CODE,,__GET_VAR(data__->CONCAT7_OUT,));
  PYTHON_EVAL_body__(&data__->SETSTATE_COMMAND);

  goto __end;

__end:
  return;
} // BUTTON_body__() 





void LED_init__(LED *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ID,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->BACK_ID,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->SELE_ID,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE_IN,__BOOL_LITERAL(FALSE),retain)
  PYTHON_EVAL_init__(&data__->INIT_COMMAND,retain);
  PYTHON_POLL_init__(&data__->SETSTATE_COMMAND,retain);
  GETBOOLSTRING_init__(&data__->GETLEDSTATE,retain);
  __INIT_VAR(data__->CONCAT2_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->CONCAT7_OUT,__STRING_LITERAL(0,""),retain)
}

// Code part
void LED_body__(LED *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,CONCAT2_OUT,,CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)5,
    (STRING)__STRING_LITERAL(37,"createSVGUIControl(\"button\",back_id=\""),
    (STRING)__GET_VAR(data__->BACK_ID,),
    (STRING)__STRING_LITERAL(11,"\",sele_id=\""),
    (STRING)__GET_VAR(data__->SELE_ID,),
    (STRING)__STRING_LITERAL(27,"\",toggle=True,active=False)")));
  __SET_VAR(data__->INIT_COMMAND.,TRIG,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->INIT_COMMAND.,CODE,,__GET_VAR(data__->CONCAT2_OUT,));
  PYTHON_EVAL_body__(&data__->INIT_COMMAND);
  __SET_VAR(data__->,ID,,__GET_VAR(data__->INIT_COMMAND.RESULT,));
  __SET_VAR(data__->GETLEDSTATE.,VALUE,,__GET_VAR(data__->STATE_IN,));
  GETBOOLSTRING_body__(&data__->GETLEDSTATE);
  __SET_VAR(data__->,CONCAT7_OUT,,CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)5,
    (STRING)__STRING_LITERAL(8,"setAttr("),
    (STRING)__GET_VAR(data__->ID,),
    (STRING)__STRING_LITERAL(9,",\"state\","),
    (STRING)__GET_VAR(data__->GETLEDSTATE.CODE,),
    (STRING)__STRING_LITERAL(1,")")));
  __SET_VAR(data__->SETSTATE_COMMAND.,TRIG,,__GET_VAR(data__->INIT_COMMAND.ACK,));
  __SET_VAR(data__->SETSTATE_COMMAND.,CODE,,__GET_VAR(data__->CONCAT7_OUT,));
  PYTHON_POLL_body__(&data__->SETSTATE_COMMAND);

  goto __end;

__end:
  return;
} // LED_body__() 





void TEXTCTRL_init__(TEXTCTRL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ID,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->BACK_ID,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->SET_TEXT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TEXT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->SVGUI_TEXTCTRL,retain);
  PYTHON_EVAL_init__(&data__->SETSTATE_COMMAND,retain);
  __INIT_VAR(data__->CONCAT1_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->AND31_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CONCAT12_OUT,__STRING_LITERAL(0,""),retain)
}

// Code part
void TEXTCTRL_body__(TEXTCTRL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,CONCAT1_OUT,,CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)3,
    (STRING)__STRING_LITERAL(43,"createSVGUIControl(\"textControl\", back_id=\""),
    (STRING)__GET_VAR(data__->BACK_ID,),
    (STRING)__STRING_LITERAL(2,"\")")));
  __SET_VAR(data__->SVGUI_TEXTCTRL.,TRIG,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->SVGUI_TEXTCTRL.,CODE,,__GET_VAR(data__->CONCAT1_OUT,));
  PYTHON_EVAL_body__(&data__->SVGUI_TEXTCTRL);
  __SET_VAR(data__->,ID,,__GET_VAR(data__->SVGUI_TEXTCTRL.RESULT,));
  __SET_VAR(data__->,AND31_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->SVGUI_TEXTCTRL.ACK,),
    (BOOL)__GET_VAR(data__->SET_TEXT,)));
  __SET_VAR(data__->,CONCAT12_OUT,,CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)5,
    (STRING)__STRING_LITERAL(8,"setAttr("),
    (STRING)__GET_VAR(data__->ID,),
    (STRING)__STRING_LITERAL(9,",\"text\",\""),
    (STRING)__GET_VAR(data__->TEXT,),
    (STRING)__STRING_LITERAL(2,"\")")));
  __SET_VAR(data__->SETSTATE_COMMAND.,TRIG,,__GET_VAR(data__->AND31_OUT,));
  __SET_VAR(data__->SETSTATE_COMMAND.,CODE,,__GET_VAR(data__->CONCAT12_OUT,));
  PYTHON_EVAL_body__(&data__->SETSTATE_COMMAND);

  goto __end;

__end:
  return;
} // TEXTCTRL_body__() 





// FUNCTION
STRING CALL_METHOD(
  BOOL EN, 
  BOOL *__ENO, 
  INT ID_NODE, 
  STRING NAMEFUNCTION, 
  INT ID_OBJ, 
  INT ID_SUBOBJ, 
  REAL D_VALUE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  STRING CALL_METHOD = __STRING_LITERAL(0,"");

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return CALL_METHOD;
  }
  CALL_METHOD = CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)7,
    (STRING)NAMEFUNCTION,
    (STRING)INT_TO_STRING(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)ID_NODE),
    (STRING)__STRING_LITERAL(1,","),
    (STRING)INT_TO_STRING(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)ID_OBJ),
    (STRING)__STRING_LITERAL(1,","),
    (STRING)REAL_TO_STRING(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)D_VALUE),
    (STRING)__STRING_LITERAL(1,")"));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return CALL_METHOD;
}


void LOAD_FOR_ALGORITM_init__(LOAD_FOR_ALGORITM *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PYTRIGGER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->NAMEFUNCTION,__STRING_LITERAL(18,"load_for_algoritm("),retain)
  __INIT_VAR(data__->ID_NODE,1,retain)
  __INIT_VAR(data__->ID_OBJ,4096,retain)
  __INIT_VAR(data__->ID_SUBOBJ,0,retain)
  PYTHON_EVAL_init__(&data__->PYTHON_EVAL0,retain);
  __INIT_VAR(data__->D_VALUE,0,retain)
  __INIT_VAR(data__->NOT2_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CALL_METHOD8_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STRING_TO_REAL12_OUT,0,retain)
}

// Code part
void LOAD_FOR_ALGORITM_body__(LOAD_FOR_ALGORITM *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,NOT2_OUT,,!(__GET_VAR(data__->PYTRIGGER,)));
  __SET_VAR(data__->,PYTRIGGER,,__GET_VAR(data__->NOT2_OUT,));
  __SET_VAR(data__->,CALL_METHOD8_OUT,,CALL_METHOD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->ID_NODE,),
    (STRING)__GET_VAR(data__->NAMEFUNCTION,),
    (INT)__GET_VAR(data__->ID_OBJ,),
    (INT)__GET_VAR(data__->ID_SUBOBJ,),
    (REAL)0.0));
  __SET_VAR(data__->PYTHON_EVAL0.,TRIG,,__GET_VAR(data__->NOT2_OUT,));
  __SET_VAR(data__->PYTHON_EVAL0.,CODE,,__GET_VAR(data__->CALL_METHOD8_OUT,));
  PYTHON_EVAL_body__(&data__->PYTHON_EVAL0);
  __SET_VAR(data__->,STRING_TO_REAL12_OUT,,STRING_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (STRING)__GET_VAR(data__->PYTHON_EVAL0.RESULT,)));
  __SET_VAR(data__->,D_VALUE,,__GET_VAR(data__->STRING_TO_REAL12_OUT,));

  goto __end;

__end:
  return;
} // LOAD_FOR_ALGORITM_body__() 





void TEST_21_init__(TEST_21 *data__, BOOL retain) {
  __INIT_VAR(data__->ID_NODE,1,retain)
  __INIT_VAR(data__->I_OBJ,4096,retain)
  __INIT_VAR(data__->I_SUBOBJ,0,retain)
  __INIT_VAR(data__->D_VALUE,0,retain)
  LOAD_FOR_ALGORITM_init__(&data__->LOAD_FOR_ALGORITM0,retain);
}

// Code part
void TEST_21_body__(TEST_21 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->LOAD_FOR_ALGORITM0.,ID_NODE,,__GET_VAR(data__->ID_NODE,));
  __SET_VAR(data__->LOAD_FOR_ALGORITM0.,ID_OBJ,,__GET_VAR(data__->I_OBJ,));
  __SET_VAR(data__->LOAD_FOR_ALGORITM0.,ID_SUBOBJ,,__GET_VAR(data__->I_SUBOBJ,));
  LOAD_FOR_ALGORITM_body__(&data__->LOAD_FOR_ALGORITM0);
  __SET_VAR(data__->,D_VALUE,,__GET_VAR(data__->LOAD_FOR_ALGORITM0.D_VALUE,));

  goto __end;

__end:
  return;
} // TEST_21_body__() 





void SAVE_FOR_ALGORITM_init__(SAVE_FOR_ALGORITM *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PYTRIGGER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->NAMEFUNCTION,__STRING_LITERAL(18,"save_for_algoritm("),retain)
  __INIT_VAR(data__->ID_NODE,2,retain)
  __INIT_VAR(data__->ID_OBJ,4096,retain)
  __INIT_VAR(data__->ID_SUBOBJ,0,retain)
  PYTHON_EVAL_init__(&data__->PYTHON_EVAL0,retain);
  __INIT_VAR(data__->D_VALUE,0,retain)
  __INIT_VAR(data__->NOT2_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CALL_METHOD8_OUT,__STRING_LITERAL(0,""),retain)
}

// Code part
void SAVE_FOR_ALGORITM_body__(SAVE_FOR_ALGORITM *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,NOT2_OUT,,!(__GET_VAR(data__->PYTRIGGER,)));
  __SET_VAR(data__->,PYTRIGGER,,__GET_VAR(data__->NOT2_OUT,));
  __SET_VAR(data__->,CALL_METHOD8_OUT,,CALL_METHOD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->ID_NODE,),
    (STRING)__GET_VAR(data__->NAMEFUNCTION,),
    (INT)__GET_VAR(data__->ID_OBJ,),
    (INT)__GET_VAR(data__->ID_SUBOBJ,),
    (REAL)__GET_VAR(data__->D_VALUE,)));
  __SET_VAR(data__->PYTHON_EVAL0.,TRIG,,__GET_VAR(data__->NOT2_OUT,));
  __SET_VAR(data__->PYTHON_EVAL0.,CODE,,__GET_VAR(data__->CALL_METHOD8_OUT,));
  PYTHON_EVAL_body__(&data__->PYTHON_EVAL0);

  goto __end;

__end:
  return;
} // SAVE_FOR_ALGORITM_body__() 





void LOAD_SOCKET_NODE_init__(LOAD_SOCKET_NODE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PYTRIGGER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->NAMEFUNCTION,__STRING_LITERAL(17,"load_socket_node("),retain)
  __INIT_VAR(data__->ID_NODE,1,retain)
  __INIT_VAR(data__->ID_OBJ,4096,retain)
  __INIT_VAR(data__->ID_SUBOBJ,0,retain)
  PYTHON_EVAL_init__(&data__->PYTHON_EVAL0,retain);
  __INIT_VAR(data__->D_VALUE,0,retain)
  __INIT_VAR(data__->NOT2_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CALL_METHOD8_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STRING_TO_REAL12_OUT,0,retain)
}

// Code part
void LOAD_SOCKET_NODE_body__(LOAD_SOCKET_NODE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,NOT2_OUT,,!(__GET_VAR(data__->PYTRIGGER,)));
  __SET_VAR(data__->,PYTRIGGER,,__GET_VAR(data__->NOT2_OUT,));
  __SET_VAR(data__->,CALL_METHOD8_OUT,,CALL_METHOD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->ID_NODE,),
    (STRING)__GET_VAR(data__->NAMEFUNCTION,),
    (INT)__GET_VAR(data__->ID_OBJ,),
    (INT)__GET_VAR(data__->ID_SUBOBJ,),
    (REAL)0.0));
  __SET_VAR(data__->PYTHON_EVAL0.,TRIG,,__GET_VAR(data__->NOT2_OUT,));
  __SET_VAR(data__->PYTHON_EVAL0.,CODE,,__GET_VAR(data__->CALL_METHOD8_OUT,));
  PYTHON_EVAL_body__(&data__->PYTHON_EVAL0);
  __SET_VAR(data__->,STRING_TO_REAL12_OUT,,STRING_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (STRING)__GET_VAR(data__->PYTHON_EVAL0.RESULT,)));
  __SET_VAR(data__->,D_VALUE,,__GET_VAR(data__->STRING_TO_REAL12_OUT,));

  goto __end;

__end:
  return;
} // LOAD_SOCKET_NODE_body__() 





void TEST_3_init__(TEST_3 *data__, BOOL retain) {
  __INIT_VAR(data__->ID_NODE,1,retain)
  __INIT_VAR(data__->ID_NODE_ALGORITM,2,retain)
  __INIT_VAR(data__->I_OBJ,4096,retain)
  __INIT_VAR(data__->I_SUBOBJ,0,retain)
  __INIT_VAR(data__->TRIGGER0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->S_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->D_VALUE,0,retain)
  __INIT_VAR(data__->D_VAL_OUT_1,0,retain)
  __INIT_VAR(data__->CYCLE,__STRING_LITERAL(5,"0:0:1"),retain)
  SAVE_FOR_ALGORITM_init__(&data__->SAVE_FOR_ALGORITM0,retain);
  LOAD_FOR_ALGORITM_init__(&data__->LOAD_FOR_ALGORITM0,retain);
  LOAD_SOCKET_NODE_init__(&data__->LOAD_SOCKET_NODE0,retain);
  __INIT_VAR(data__->EXPT37_OUT,0,retain)
}

// Code part
void TEST_3_body__(TEST_3 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->LOAD_SOCKET_NODE0.,ID_NODE,,__GET_VAR(data__->ID_NODE,));
  __SET_VAR(data__->LOAD_SOCKET_NODE0.,ID_OBJ,,__GET_VAR(data__->I_OBJ,));
  __SET_VAR(data__->LOAD_SOCKET_NODE0.,ID_SUBOBJ,,__GET_VAR(data__->I_SUBOBJ,));
  LOAD_SOCKET_NODE_body__(&data__->LOAD_SOCKET_NODE0);
  __SET_VAR(data__->SAVE_FOR_ALGORITM0.,ID_NODE,,__GET_VAR(data__->ID_NODE_ALGORITM,));
  __SET_VAR(data__->SAVE_FOR_ALGORITM0.,ID_OBJ,,__GET_VAR(data__->I_OBJ,));
  __SET_VAR(data__->SAVE_FOR_ALGORITM0.,ID_SUBOBJ,,__GET_VAR(data__->I_SUBOBJ,));
  __SET_VAR(data__->SAVE_FOR_ALGORITM0.,D_VALUE,,__GET_VAR(data__->EXPT37_OUT,));
  SAVE_FOR_ALGORITM_body__(&data__->SAVE_FOR_ALGORITM0);
  __SET_VAR(data__->LOAD_FOR_ALGORITM0.,ID_NODE,,__GET_VAR(data__->ID_NODE_ALGORITM,));
  __SET_VAR(data__->LOAD_FOR_ALGORITM0.,ID_OBJ,,__GET_VAR(data__->I_OBJ,));
  __SET_VAR(data__->LOAD_FOR_ALGORITM0.,ID_SUBOBJ,,__GET_VAR(data__->I_SUBOBJ,));
  LOAD_FOR_ALGORITM_body__(&data__->LOAD_FOR_ALGORITM0);
  __SET_VAR(data__->,D_VALUE,,__GET_VAR(data__->LOAD_SOCKET_NODE0.D_VALUE,));
  __SET_VAR(data__->,EXPT37_OUT,,EXPT__REAL__REAL__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->D_VALUE,),
    (SINT)2));
  __SET_VAR(data__->,D_VAL_OUT_1,,__GET_VAR(data__->EXPT37_OUT,));

  goto __end;

__end:
  return;
} // TEST_3_body__() 





void TEST_2_init__(TEST_2 *data__, BOOL retain) {
  __INIT_VAR(data__->ID_NODE,1,retain)
  __INIT_VAR(data__->I_OBJ,4096,retain)
  __INIT_VAR(data__->I_SUBOBJ,0,retain)
  __INIT_VAR(data__->D_VALUE,0,retain)
  LOAD_SOCKET_NODE_init__(&data__->LOAD_SOCKET_NODE0,retain);
}

// Code part
void TEST_2_body__(TEST_2 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->LOAD_SOCKET_NODE0.,ID_NODE,,__GET_VAR(data__->ID_NODE,));
  __SET_VAR(data__->LOAD_SOCKET_NODE0.,ID_OBJ,,__GET_VAR(data__->I_OBJ,));
  __SET_VAR(data__->LOAD_SOCKET_NODE0.,ID_SUBOBJ,,__GET_VAR(data__->I_SUBOBJ,));
  LOAD_SOCKET_NODE_body__(&data__->LOAD_SOCKET_NODE0);
  __SET_VAR(data__->,D_VALUE,,__GET_VAR(data__->LOAD_SOCKET_NODE0.D_VALUE,));

  goto __end;

__end:
  return;
} // TEST_2_body__() 





void SET_SOCKET_NODE_init__(SET_SOCKET_NODE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PYTRIGGER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->NAMEFUNCTION,__STRING_LITERAL(16,"set_socket_node("),retain)
  __INIT_VAR(data__->ID_NODE,1,retain)
  __INIT_VAR(data__->ID_OBJ,4097,retain)
  __INIT_VAR(data__->ID_SUBOBJ,0,retain)
  PYTHON_EVAL_init__(&data__->PYTHON_EVAL0,retain);
  __INIT_VAR(data__->D_VALUE,0,retain)
  __INIT_VAR(data__->NOT2_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CALL_METHOD8_OUT,__STRING_LITERAL(0,""),retain)
}

// Code part
void SET_SOCKET_NODE_body__(SET_SOCKET_NODE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,NOT2_OUT,,!(__GET_VAR(data__->PYTRIGGER,)));
  __SET_VAR(data__->,PYTRIGGER,,__GET_VAR(data__->NOT2_OUT,));
  __SET_VAR(data__->,CALL_METHOD8_OUT,,CALL_METHOD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->ID_NODE,),
    (STRING)__GET_VAR(data__->NAMEFUNCTION,),
    (INT)__GET_VAR(data__->ID_OBJ,),
    (INT)__GET_VAR(data__->ID_SUBOBJ,),
    (REAL)__GET_VAR(data__->D_VALUE,)));
  __SET_VAR(data__->PYTHON_EVAL0.,TRIG,,__GET_VAR(data__->NOT2_OUT,));
  __SET_VAR(data__->PYTHON_EVAL0.,CODE,,__GET_VAR(data__->CALL_METHOD8_OUT,));
  PYTHON_EVAL_body__(&data__->PYTHON_EVAL0);

  goto __end;

__end:
  return;
} // SET_SOCKET_NODE_body__() 





void TEST_1_init__(TEST_1 *data__, BOOL retain) {
  __INIT_VAR(data__->ID_NODE,1,retain)
  __INIT_VAR(data__->I_OBJ,4096,retain)
  __INIT_VAR(data__->I_OBJ_1,4097,retain)
  __INIT_VAR(data__->I_SUBOBJ,0,retain)
  __INIT_VAR(data__->TRIGGER0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->S_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->D_VALUE,0,retain)
  __INIT_VAR(data__->D_VAL_OUT_1,0,retain)
  LOAD_SOCKET_NODE_init__(&data__->LOAD_SOCKET_NODE0,retain);
  __INIT_VAR(data__->CYCLE,__STRING_LITERAL(5,"0:0:1"),retain)
  SET_SOCKET_NODE_init__(&data__->SET_SOCKET_NODE0,retain);
  __INIT_VAR(data__->EXPT31_OUT,0,retain)
}

// Code part
void TEST_1_body__(TEST_1 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->SET_SOCKET_NODE0.,ID_NODE,,__GET_VAR(data__->ID_NODE,));
  __SET_VAR(data__->SET_SOCKET_NODE0.,ID_OBJ,,__GET_VAR(data__->I_OBJ_1,));
  __SET_VAR(data__->SET_SOCKET_NODE0.,ID_SUBOBJ,,__GET_VAR(data__->I_SUBOBJ,));
  __SET_VAR(data__->SET_SOCKET_NODE0.,D_VALUE,,__GET_VAR(data__->EXPT31_OUT,));
  SET_SOCKET_NODE_body__(&data__->SET_SOCKET_NODE0);
  __SET_VAR(data__->LOAD_SOCKET_NODE0.,ID_NODE,,__GET_VAR(data__->ID_NODE,));
  __SET_VAR(data__->LOAD_SOCKET_NODE0.,ID_OBJ,,__GET_VAR(data__->I_OBJ,));
  __SET_VAR(data__->LOAD_SOCKET_NODE0.,ID_SUBOBJ,,__GET_VAR(data__->I_SUBOBJ,));
  LOAD_SOCKET_NODE_body__(&data__->LOAD_SOCKET_NODE0);
  __SET_VAR(data__->,D_VALUE,,__GET_VAR(data__->LOAD_SOCKET_NODE0.D_VALUE,));
  __SET_VAR(data__->,EXPT31_OUT,,EXPT__REAL__REAL__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->D_VALUE,),
    (SINT)2));
  __SET_VAR(data__->,D_VAL_OUT_1,,__GET_VAR(data__->EXPT31_OUT,));

  goto __end;

__end:
  return;
} // TEST_1_body__() 





void MAINSERVER_init__(MAINSERVER *data__, BOOL retain) {
  __INIT_VAR(data__->ID_NODE,1,retain)
  __INIT_VAR(data__->I_OBJ,4096,retain)
  __INIT_VAR(data__->I_OBJ_1,4097,retain)
  __INIT_VAR(data__->I_SUBOBJ,0,retain)
  __INIT_VAR(data__->TRIGGER0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->S_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->D_VALUE,0,retain)
  __INIT_VAR(data__->D_VAL_OUT_1,0,retain)
  LOAD_SOCKET_NODE_init__(&data__->LOAD_SOCKET_NODE0,retain);
  INTEGRAL_init__(&data__->INTEGRAL0,retain);
  __INIT_VAR(data__->CYCLE,__STRING_LITERAL(5,"0:0:1"),retain)
  SET_SOCKET_NODE_init__(&data__->SET_SOCKET_NODE0,retain);
  __INIT_VAR(data__->NOT14_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STRING_TO_TIME21_OUT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void MAINSERVER_body__(MAINSERVER *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->SET_SOCKET_NODE0.,ID_NODE,,__GET_VAR(data__->ID_NODE,));
  __SET_VAR(data__->SET_SOCKET_NODE0.,ID_OBJ,,__GET_VAR(data__->I_OBJ_1,));
  __SET_VAR(data__->SET_SOCKET_NODE0.,ID_SUBOBJ,,__GET_VAR(data__->I_SUBOBJ,));
  __SET_VAR(data__->SET_SOCKET_NODE0.,D_VALUE,,__GET_VAR(data__->D_VAL_OUT_1,));
  SET_SOCKET_NODE_body__(&data__->SET_SOCKET_NODE0);
  __SET_VAR(data__->LOAD_SOCKET_NODE0.,ID_NODE,,__GET_VAR(data__->ID_NODE,));
  __SET_VAR(data__->LOAD_SOCKET_NODE0.,ID_OBJ,,__GET_VAR(data__->I_OBJ,));
  __SET_VAR(data__->LOAD_SOCKET_NODE0.,ID_SUBOBJ,,__GET_VAR(data__->I_SUBOBJ,));
  LOAD_SOCKET_NODE_body__(&data__->LOAD_SOCKET_NODE0);
  __SET_VAR(data__->,D_VALUE,,__GET_VAR(data__->LOAD_SOCKET_NODE0.D_VALUE,));
  __SET_VAR(data__->,NOT14_OUT,,!(__GET_VAR(data__->TRIGGER0,)));
  __SET_VAR(data__->,STRING_TO_TIME21_OUT,,STRING_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (STRING)__GET_VAR(data__->CYCLE,)));
  __SET_VAR(data__->INTEGRAL0.,RUN,,__GET_VAR(data__->TRIGGER0,));
  __SET_VAR(data__->INTEGRAL0.,R1,,__GET_VAR(data__->NOT14_OUT,));
  __SET_VAR(data__->INTEGRAL0.,XIN,,__GET_VAR(data__->D_VALUE,));
  __SET_VAR(data__->INTEGRAL0.,X0,,0.1);
  __SET_VAR(data__->INTEGRAL0.,CYCLE,,__GET_VAR(data__->STRING_TO_TIME21_OUT,));
  INTEGRAL_body__(&data__->INTEGRAL0);
  __SET_VAR(data__->,D_VAL_OUT_1,,__GET_VAR(data__->INTEGRAL0.XOUT,));
  __SET_VAR(data__->,TRIGGER0,,__GET_VAR(data__->NOT14_OUT,));

  goto __end;

__end:
  return;
} // MAINSERVER_body__() 





