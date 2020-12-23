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
STRING WRITESIGNALCSV(
  BOOL EN, 
  BOOL *__ENO, 
  STRING NAMEFILE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  STRING WRITESIGNALCSV = __STRING_LITERAL(0,"");

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return WRITESIGNALCSV;
  }
  WRITESIGNALCSV = CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)3,
    (STRING)__STRING_LITERAL(10,"writeCSV(\""),
    (STRING)NAMEFILE,
    (STRING)__STRING_LITERAL(2,"\")"));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return WRITESIGNALCSV;
}


// FUNCTION
STRING OPENCSV(
  BOOL EN, 
  BOOL *__ENO, 
  STRING ARG)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  STRING OPENCSV = __STRING_LITERAL(0,"");

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return OPENCSV;
  }
  OPENCSV = CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)3,
    (STRING)__STRING_LITERAL(9,"openCSV(\""),
    (STRING)ARG,
    (STRING)__STRING_LITERAL(2,"\")"));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return OPENCSV;
}


// FUNCTION
STRING READSIGNAL(
  BOOL EN, 
  BOOL *__ENO, 
  STRING ARG)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  STRING READSIGNAL = __STRING_LITERAL(0,"");

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return READSIGNAL;
  }
  READSIGNAL = CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)3,
    (STRING)__STRING_LITERAL(12,"readSignal(\""),
    (STRING)ARG,
    (STRING)__STRING_LITERAL(2,"\")"));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return READSIGNAL;
}


void SOURCEFROMFILE_init__(SOURCEFROMFILE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PYTRIGGER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->NAMEFILEFB,__STRING_LITERAL(14,"_1NJ20T001.csv"),retain)
  __INIT_VAR(data__->VALUE_OUTFB,0,retain)
  PYTHON_EVAL_init__(&data__->PYTHON_EVAL0,retain);
  __INIT_VAR(data__->STR_FUNC,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->NOT2_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->READSIGNAL11_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STRING_TO_REAL5_OUT,0,retain)
}

// Code part
void SOURCEFROMFILE_body__(SOURCEFROMFILE *data__) {
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
  __SET_VAR(data__->,READSIGNAL11_OUT,,READSIGNAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (STRING)__GET_VAR(data__->NAMEFILEFB,)));
  __SET_VAR(data__->PYTHON_EVAL0.,TRIG,,__GET_VAR(data__->NOT2_OUT,));
  __SET_VAR(data__->PYTHON_EVAL0.,CODE,,__GET_VAR(data__->READSIGNAL11_OUT,));
  PYTHON_EVAL_body__(&data__->PYTHON_EVAL0);
  __SET_VAR(data__->,STRING_TO_REAL5_OUT,,STRING_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (STRING)__GET_VAR(data__->PYTHON_EVAL0.RESULT,)));
  __SET_VAR(data__->,VALUE_OUTFB,,__GET_VAR(data__->STRING_TO_REAL5_OUT,));

  goto __end;

__end:
  return;
} // SOURCEFROMFILE_body__() 





void DG_init__(DG *data__, BOOL retain) {
  SOURCEFROMFILE_init__(&data__->SOURCEFROMFILE0,retain);
  SOURCEFROMFILE_init__(&data__->SOURCEFROMFILE1,retain);
  {
    static const DATATYPE0 temp = {__STRING_LITERAL(14,"_1NJ20T001.csv"),__STRING_LITERAL(14,"_1CV20T001.csv"),__STRING_LITERAL(12,"Rashod_1.csv"),__STRING_LITERAL(12,"Rashod_2.csv"),__STRING_LITERAL(9,"PID_1.csv"),__STRING_LITERAL(9,"PID_2.csv"),__STRING_LITERAL(9,"PID_3.csv"),__STRING_LITERAL(2,"IN"),__STRING_LITERAL(3,"OUT"),__STRING_LITERAL(7,"IBM.csv"),__STRING_LITERAL(5,"Amper"),__STRING_LITERAL(7,"Amper_A"),__STRING_LITERAL(7,"Amper_B"),__STRING_LITERAL(7,"Amper_C")};
    __SET_VAR(data__->,IN1,,temp);
  }
  {
    static const DATATYPE0 temp = {__STRING_LITERAL(14,"_1NJ20T001.csv"),__STRING_LITERAL(14,"_1CV20T001.csv"),__STRING_LITERAL(12,"Rashod_1.csv"),__STRING_LITERAL(12,"Rashod_2.csv"),__STRING_LITERAL(9,"PID_1.csv"),__STRING_LITERAL(9,"PID_2.csv"),__STRING_LITERAL(9,"PID_3.csv"),__STRING_LITERAL(2,"IN"),__STRING_LITERAL(3,"OUT"),__STRING_LITERAL(7,"IBM.csv"),__STRING_LITERAL(5,"Amper"),__STRING_LITERAL(7,"Amper_A"),__STRING_LITERAL(7,"Amper_B"),__STRING_LITERAL(7,"Amper_C")};
    __SET_VAR(data__->,IN2,,temp);
  }
  __INIT_VAR(data__->EXP_IN,3,retain)
  __INIT_VAR(data__->VAL_OUT,0,retain)
  __INIT_VAR(data__->RASHOD_1_IN,0,retain)
  __INIT_VAR(data__->RASHOD_2_IN,0,retain)
  __INIT_VAR(data__->SQRT5_OUT,0,retain)
  __INIT_VAR(data__->EXPT6_OUT,0,retain)
  __INIT_VAR(data__->ADD8_OUT,0,retain)
}

// Code part
void DG_body__(DG *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->SOURCEFROMFILE0.,NAMEFILEFB,,__GET_VAR(data__->IN1,.RASHOD_1));
  SOURCEFROMFILE_body__(&data__->SOURCEFROMFILE0);
  __SET_VAR(data__->,RASHOD_1_IN,,__GET_VAR(data__->SOURCEFROMFILE0.VALUE_OUTFB,));
  __SET_VAR(data__->,SQRT5_OUT,,SQRT__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->RASHOD_1_IN,)));
  __SET_VAR(data__->,EXPT6_OUT,,EXPT__REAL__REAL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->RASHOD_2_IN,),
    (INT)__GET_VAR(data__->EXP_IN,)));
  __SET_VAR(data__->,ADD8_OUT,,ADD__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->SQRT5_OUT,),
    (REAL)__GET_VAR(data__->EXPT6_OUT,)));
  __SET_VAR(data__->,VAL_OUT,,__GET_VAR(data__->ADD8_OUT,));
  __SET_VAR(data__->SOURCEFROMFILE1.,NAMEFILEFB,,__GET_VAR(data__->IN2,.RASHOD_2));
  SOURCEFROMFILE_body__(&data__->SOURCEFROMFILE1);
  __SET_VAR(data__->,RASHOD_2_IN,,__GET_VAR(data__->SOURCEFROMFILE1.VALUE_OUTFB,));

  goto __end;

__end:
  return;
} // DG_body__() 





void TESTSOURCEFROMFILE_init__(TESTSOURCEFROMFILE *data__, BOOL retain) {
  __INIT_VAR(data__->NAMEFILE,__STRING_LITERAL(14,"_1NJ20T002.csv"),retain)
  {
    static const DATATYPE0 temp = {__STRING_LITERAL(14,"_1NJ20T001.csv"),__STRING_LITERAL(14,"_1CV20T001.csv"),__STRING_LITERAL(12,"Rashod_1.csv"),__STRING_LITERAL(12,"Rashod_2.csv"),__STRING_LITERAL(9,"PID_1.csv"),__STRING_LITERAL(9,"PID_2.csv"),__STRING_LITERAL(9,"PID_3.csv"),__STRING_LITERAL(2,"IN"),__STRING_LITERAL(3,"OUT"),__STRING_LITERAL(7,"IBM.csv"),__STRING_LITERAL(5,"Amper"),__STRING_LITERAL(7,"Amper_A"),__STRING_LITERAL(7,"Amper_B"),__STRING_LITERAL(7,"Amper_C")};
    __SET_VAR(data__->,NAMEFILEDATATYPE,,temp);
  }
  __INIT_EXTERNAL(REAL,VALUEOUT,data__->VALUEOUT,retain)
  __INIT_VAR(data__->VALUE_1,0,retain)
  SOURCEFROMFILE_init__(&data__->SOURCEFROMFILE0,retain);
  SOURCEFROMFILE_init__(&data__->SOURCEFROMFILE1,retain);
  SOURCEFROMFILE_init__(&data__->SOURCEFROMFILE2,retain);
  __INIT_VAR(data__->ADD7_OUT,0,retain)
}

// Code part
void TESTSOURCEFROMFILE_body__(TESTSOURCEFROMFILE *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->SOURCEFROMFILE0.,NAMEFILEFB,,__GET_VAR(data__->NAMEFILE,));
  SOURCEFROMFILE_body__(&data__->SOURCEFROMFILE0);
  __SET_VAR(data__->SOURCEFROMFILE1.,NAMEFILEFB,,__STRING_LITERAL(14,"_1NJ20T001.csv"));
  SOURCEFROMFILE_body__(&data__->SOURCEFROMFILE1);
  __SET_VAR(data__->,ADD7_OUT,,ADD__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->SOURCEFROMFILE0.VALUE_OUTFB,),
    (REAL)__GET_VAR(data__->SOURCEFROMFILE1.VALUE_OUTFB,)));
  __SET_EXTERNAL(data__->,VALUEOUT,,__GET_VAR(data__->ADD7_OUT,));
  __SET_VAR(data__->SOURCEFROMFILE2.,NAMEFILEFB,,__GET_VAR(data__->NAMEFILEDATATYPE,._1NJ20T001));
  SOURCEFROMFILE_body__(&data__->SOURCEFROMFILE2);
  __SET_VAR(data__->,VALUE_1,,__GET_VAR(data__->SOURCEFROMFILE2.VALUE_OUTFB,));

  goto __end;

__end:
  return;
} // TESTSOURCEFROMFILE_body__() 





// FUNCTION
STRING GET_VAL_ROW(
  BOOL EN, 
  BOOL *__ENO, 
  STRING NAMEFILE, 
  STRING NAMEFIELD)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  STRING GET_VAL_ROW = __STRING_LITERAL(0,"");

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return GET_VAL_ROW;
  }
  GET_VAL_ROW = CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)5,
    (STRING)__STRING_LITERAL(13,"get_val_row(\""),
    (STRING)NAMEFILE,
    (STRING)__STRING_LITERAL(3,"\",\""),
    (STRING)NAMEFIELD,
    (STRING)__STRING_LITERAL(2,"\")"));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return GET_VAL_ROW;
}


void GET_VALUE_CSV_init__(GET_VALUE_CSV *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PYTRIGGER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->NAMEFILE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->NAMEFIELD,__STRING_LITERAL(2,"IN"),retain)
  __INIT_VAR(data__->VALUE_OUTFB,0,retain)
  PYTHON_EVAL_init__(&data__->PYTHON_EVAL0,retain);
  __INIT_VAR(data__->NOT2_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GET_VAL_ROW15_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STRING_TO_REAL5_OUT,0,retain)
}

// Code part
void GET_VALUE_CSV_body__(GET_VALUE_CSV *data__) {
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
  __SET_VAR(data__->,GET_VAL_ROW15_OUT,,GET_VAL_ROW(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (STRING)__GET_VAR(data__->NAMEFILE,),
    (STRING)__GET_VAR(data__->NAMEFIELD,)));
  __SET_VAR(data__->PYTHON_EVAL0.,TRIG,,__GET_VAR(data__->NOT2_OUT,));
  __SET_VAR(data__->PYTHON_EVAL0.,CODE,,__GET_VAR(data__->GET_VAL_ROW15_OUT,));
  PYTHON_EVAL_body__(&data__->PYTHON_EVAL0);
  __SET_VAR(data__->,STRING_TO_REAL5_OUT,,STRING_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (STRING)__GET_VAR(data__->PYTHON_EVAL0.RESULT,)));
  __SET_VAR(data__->,VALUE_OUTFB,,__GET_VAR(data__->STRING_TO_REAL5_OUT,));

  goto __end;

__end:
  return;
} // GET_VALUE_CSV_body__() 





// FUNCTION
STRING READSIGNALCSV(
  BOOL EN, 
  BOOL *__ENO, 
  STRING NAMEFILE, 
  STRING I_STATUS)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  STRING READSIGNALCSV = __STRING_LITERAL(0,"");

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return READSIGNALCSV;
  }
  READSIGNALCSV = CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)5,
    (STRING)__STRING_LITERAL(15,"readSignalCSV(\""),
    (STRING)I_STATUS,
    (STRING)__STRING_LITERAL(3,"\",\""),
    (STRING)NAMEFILE,
    (STRING)__STRING_LITERAL(2,"\")"));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return READSIGNALCSV;
}


void SOURCEFROMFILECSV_init__(SOURCEFROMFILECSV *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PYTRIGGER,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PYTRIGGEROPENCSV,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->NAMEFILEFB,__STRING_LITERAL(10,"unknow.csv"),retain)
  __INIT_VAR(data__->I_STATUS_READSIGNAL_CSV,0,retain)
  __INIT_VAR(data__->I_STATUS_WRITESIGNAL_CSV,0,retain)
  PYTHON_EVAL_init__(&data__->PYTHON_EVAL0,retain);
  __INIT_VAR(data__->STR_FUNC,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PYTHON_EVAL1,retain);
  PYTHON_EVAL_init__(&data__->PYTHON_EVAL2,retain);
  __INIT_VAR(data__->CON_WRITECSV,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->NOT2_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPENCSV18_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->READSIGNALCSV24_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STRING_TO_INT21_OUT,0,retain)
  __INIT_VAR(data__->WRITESIGNALCSV26_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STRING_TO_INT29_OUT,0,retain)
}

// Code part
void SOURCEFROMFILECSV_body__(SOURCEFROMFILECSV *data__) {
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
  __SET_VAR(data__->,OPENCSV18_OUT,,OPENCSV(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (STRING)__GET_VAR(data__->NAMEFILEFB,)));
  __SET_VAR(data__->PYTHON_EVAL1.,TRIG,,__GET_VAR(data__->PYTRIGGEROPENCSV,));
  __SET_VAR(data__->PYTHON_EVAL1.,CODE,,__GET_VAR(data__->OPENCSV18_OUT,));
  PYTHON_EVAL_body__(&data__->PYTHON_EVAL1);
  __SET_VAR(data__->,READSIGNALCSV24_OUT,,READSIGNALCSV(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (STRING)__GET_VAR(data__->NAMEFILEFB,),
    (STRING)__GET_VAR(data__->PYTHON_EVAL1.RESULT,)));
  __SET_VAR(data__->PYTHON_EVAL0.,TRIG,,__GET_VAR(data__->NOT2_OUT,));
  __SET_VAR(data__->PYTHON_EVAL0.,CODE,,__GET_VAR(data__->READSIGNALCSV24_OUT,));
  PYTHON_EVAL_body__(&data__->PYTHON_EVAL0);
  __SET_VAR(data__->,STRING_TO_INT21_OUT,,STRING_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (STRING)__GET_VAR(data__->PYTHON_EVAL0.RESULT,)));
  __SET_VAR(data__->,I_STATUS_READSIGNAL_CSV,,__GET_VAR(data__->STRING_TO_INT21_OUT,));
  __SET_VAR(data__->,WRITESIGNALCSV26_OUT,,WRITESIGNALCSV(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (STRING)__GET_VAR(data__->NAMEFILEFB,)));
  __SET_VAR(data__->PYTHON_EVAL2.,TRIG,,__GET_VAR(data__->NOT2_OUT,));
  __SET_VAR(data__->PYTHON_EVAL2.,CODE,,__GET_VAR(data__->WRITESIGNALCSV26_OUT,));
  PYTHON_EVAL_body__(&data__->PYTHON_EVAL2);
  __SET_VAR(data__->,STRING_TO_INT29_OUT,,STRING_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (STRING)__GET_VAR(data__->PYTHON_EVAL2.RESULT,)));
  __SET_VAR(data__->,I_STATUS_WRITESIGNAL_CSV,,__GET_VAR(data__->STRING_TO_INT29_OUT,));

  goto __end;

__end:
  return;
} // SOURCEFROMFILECSV_body__() 





// FUNCTION
STRING SET_VAL_ROW(
  BOOL EN, 
  BOOL *__ENO, 
  STRING NAMEFILE, 
  STRING NAMEFIELD, 
  REAL VALUE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  STRING STR_TEMP = __STRING_LITERAL(0,"");
  STRING SET_VAL_ROW = __STRING_LITERAL(0,"");

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SET_VAL_ROW;
  }
  SET_VAL_ROW = CONCAT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)5,
    (STRING)__STRING_LITERAL(13,"set_val_row(\""),
    (STRING)CONCAT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)3,
      (STRING)NAMEFILE,
      (STRING)__STRING_LITERAL(3,"\",\""),
      (STRING)NAMEFIELD),
    (STRING)__STRING_LITERAL(3,"\",\""),
    (STRING)REAL_TO_STRING(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)VALUE),
    (STRING)__STRING_LITERAL(2,"\")"));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SET_VAL_ROW;
}


void SET_VALUE_CSV_init__(SET_VALUE_CSV *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PYTRIGGER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->NAMEFILE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->NAMEFIELD,__STRING_LITERAL(2,"IN"),retain)
  __INIT_VAR(data__->I_STATUS,0,retain)
  PYTHON_EVAL_init__(&data__->PYTHON_EVAL0,retain);
  __INIT_VAR(data__->VALUE_IN,0,retain)
  __INIT_VAR(data__->NOT2_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SET_VAL_ROW17_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STRING_TO_INT19_OUT,0,retain)
}

// Code part
void SET_VALUE_CSV_body__(SET_VALUE_CSV *data__) {
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
  __SET_VAR(data__->,SET_VAL_ROW17_OUT,,SET_VAL_ROW(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (STRING)__GET_VAR(data__->NAMEFILE,),
    (STRING)__GET_VAR(data__->NAMEFIELD,),
    (REAL)__GET_VAR(data__->VALUE_IN,)));
  __SET_VAR(data__->PYTHON_EVAL0.,TRIG,,__GET_VAR(data__->NOT2_OUT,));
  __SET_VAR(data__->PYTHON_EVAL0.,CODE,,__GET_VAR(data__->SET_VAL_ROW17_OUT,));
  PYTHON_EVAL_body__(&data__->PYTHON_EVAL0);
  __SET_VAR(data__->,STRING_TO_INT19_OUT,,STRING_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (STRING)__GET_VAR(data__->PYTHON_EVAL0.RESULT,)));
  __SET_VAR(data__->,I_STATUS,,__GET_VAR(data__->STRING_TO_INT19_OUT,));

  goto __end;

__end:
  return;
} // SET_VALUE_CSV_body__() 





void TESTCSV_init__(TESTCSV *data__, BOOL retain) {
  __INIT_VAR(data__->PYTRIGER,__BOOL_LITERAL(FALSE),retain)
  {
    static const DATATYPE0 temp = {__STRING_LITERAL(14,"_1NJ20T001.csv"),__STRING_LITERAL(14,"_1CV20T001.csv"),__STRING_LITERAL(12,"Rashod_1.csv"),__STRING_LITERAL(12,"Rashod_2.csv"),__STRING_LITERAL(9,"PID_1.csv"),__STRING_LITERAL(9,"PID_2.csv"),__STRING_LITERAL(9,"PID_3.csv"),__STRING_LITERAL(2,"IN"),__STRING_LITERAL(3,"OUT"),__STRING_LITERAL(7,"IBM.csv"),__STRING_LITERAL(5,"Amper"),__STRING_LITERAL(7,"Amper_A"),__STRING_LITERAL(7,"Amper_B"),__STRING_LITERAL(7,"Amper_C")};
    __SET_VAR(data__->,TAGS,,temp);
  }
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->I_STATUS_READ_CSV,0,retain)
  __INIT_VAR(data__->I_STATUS_READ_CSV1,0,retain)
  __INIT_VAR(data__->I_STATUS_WRITE_CSV,0,retain)
  __INIT_VAR(data__->I_STATUS_OPEN_CSV,0,retain)
  __INIT_VAR(data__->VAL_OUT_1,0,retain)
  __INIT_VAR(data__->VAL_OUT_2,0,retain)
  __INIT_VAR(data__->VAL_OUT_3,0,retain)
  __INIT_VAR(data__->VAL_OUT_4,0,retain)
  __INIT_VAR(data__->VAL_OUT_5,0,retain)
  __INIT_VAR(data__->VAL_OUT_6,0,retain)
  __INIT_VAR(data__->VAL_OUT_7,0,retain)
  __INIT_VAR(data__->VAL_OUT_8,0,retain)
  __INIT_VAR(data__->VAL_OUT_9,0,retain)
  __INIT_VAR(data__->VAL_OUT_10,0,retain)
  __INIT_VAR(data__->VAL_OUT_12,0,retain)
  {
    static const DATATYPE0 temp = {__STRING_LITERAL(14,"_1NJ20T001.csv"),__STRING_LITERAL(14,"_1CV20T001.csv"),__STRING_LITERAL(12,"Rashod_1.csv"),__STRING_LITERAL(12,"Rashod_2.csv"),__STRING_LITERAL(9,"PID_1.csv"),__STRING_LITERAL(9,"PID_2.csv"),__STRING_LITERAL(9,"PID_3.csv"),__STRING_LITERAL(2,"IN"),__STRING_LITERAL(3,"OUT"),__STRING_LITERAL(7,"IBM.csv"),__STRING_LITERAL(5,"Amper"),__STRING_LITERAL(7,"Amper_A"),__STRING_LITERAL(7,"Amper_B"),__STRING_LITERAL(7,"Amper_C")};
    __SET_VAR(data__->,VAL_IN,,temp);
  }
  GET_VALUE_CSV_init__(&data__->GET_VALUE_CSV0,retain);
  GET_VALUE_CSV_init__(&data__->GET_VALUE_CSV1,retain);
  SOURCEFROMFILECSV_init__(&data__->SOURCEFROMFILECSV0,retain);
  SOURCEFROMFILECSV_init__(&data__->SOURCEFROMFILECSV1,retain);
  GET_VALUE_CSV_init__(&data__->GET_VALUE_CSV2,retain);
  GET_VALUE_CSV_init__(&data__->GET_VALUE_CSV3,retain);
  SET_VALUE_CSV_init__(&data__->SET_VALUE_CSV0,retain);
  SET_VALUE_CSV_init__(&data__->SET_VALUE_CSV1,retain);
  SET_VALUE_CSV_init__(&data__->SET_VALUE_CSV2,retain);
  SET_VALUE_CSV_init__(&data__->SET_VALUE_CSV3,retain);
  __INIT_VAR(data__->MUL31_OUT,0,retain)
  __INIT_VAR(data__->ADD29_OUT,0,retain)
}

// Code part
void TESTCSV_body__(TESTCSV *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->SET_VALUE_CSV0.,NAMEFILE,,__GET_VAR(data__->TAGS,.PID_1));
  __SET_VAR(data__->SET_VALUE_CSV0.,NAMEFIELD,,__STRING_LITERAL(9,"val_out_1"));
  __SET_VAR(data__->SET_VALUE_CSV0.,VALUE_IN,,__GET_VAR(data__->VAL_OUT_1,));
  SET_VALUE_CSV_body__(&data__->SET_VALUE_CSV0);
  __SET_VAR(data__->,I_STATUS_WRITE_CSV,,__GET_VAR(data__->SET_VALUE_CSV0.I_STATUS,));
  __SET_VAR(data__->SOURCEFROMFILECSV0.,NAMEFILEFB,,__GET_VAR(data__->TAGS,.PID_1));
  SOURCEFROMFILECSV_body__(&data__->SOURCEFROMFILECSV0);
  __SET_VAR(data__->,I_STATUS_READ_CSV,,__GET_VAR(data__->SOURCEFROMFILECSV0.I_STATUS_READSIGNAL_CSV,));
  __SET_VAR(data__->GET_VALUE_CSV0.,NAMEFILE,,__GET_VAR(data__->TAGS,.PID_1));
  __SET_VAR(data__->GET_VALUE_CSV0.,NAMEFIELD,,__GET_VAR(data__->VAL_IN,.IN));
  GET_VALUE_CSV_body__(&data__->GET_VALUE_CSV0);
  __SET_VAR(data__->,VAL_OUT_1,,__GET_VAR(data__->GET_VALUE_CSV0.VALUE_OUTFB,));
  __SET_VAR(data__->,MUL31_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->VAL_OUT_1,),
    (REAL)__GET_VAR(data__->VAL_OUT_2,)));
  __SET_VAR(data__->,VAL_OUT_6,,__GET_VAR(data__->MUL31_OUT,));
  __SET_VAR(data__->GET_VALUE_CSV1.,NAMEFILE,,__GET_VAR(data__->TAGS,.PID_1));
  __SET_VAR(data__->GET_VALUE_CSV1.,NAMEFIELD,,__GET_VAR(data__->VAL_IN,.OUT));
  GET_VALUE_CSV_body__(&data__->GET_VALUE_CSV1);
  __SET_VAR(data__->,VAL_OUT_2,,__GET_VAR(data__->GET_VALUE_CSV1.VALUE_OUTFB,));
  __SET_VAR(data__->SOURCEFROMFILECSV1.,NAMEFILEFB,,__GET_VAR(data__->TAGS,.PID_2));
  SOURCEFROMFILECSV_body__(&data__->SOURCEFROMFILECSV1);
  __SET_VAR(data__->,I_STATUS_READ_CSV1,,__GET_VAR(data__->SOURCEFROMFILECSV1.I_STATUS_READSIGNAL_CSV,));
  __SET_VAR(data__->GET_VALUE_CSV2.,NAMEFILE,,__GET_VAR(data__->TAGS,.PID_2));
  __SET_VAR(data__->GET_VALUE_CSV2.,NAMEFIELD,,__STRING_LITERAL(4,"IN_1"));
  GET_VALUE_CSV_body__(&data__->GET_VALUE_CSV2);
  __SET_VAR(data__->,VAL_OUT_3,,__GET_VAR(data__->GET_VALUE_CSV2.VALUE_OUTFB,));
  __SET_VAR(data__->,ADD29_OUT,,ADD__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->VAL_OUT_3,),
    (REAL)__GET_VAR(data__->VAL_OUT_4,)));
  __SET_VAR(data__->,VAL_OUT_5,,__GET_VAR(data__->ADD29_OUT,));
  __SET_VAR(data__->GET_VALUE_CSV3.,NAMEFILE,,__GET_VAR(data__->TAGS,.PID_2));
  __SET_VAR(data__->GET_VALUE_CSV3.,NAMEFIELD,,__STRING_LITERAL(4,"IN_2"));
  GET_VALUE_CSV_body__(&data__->GET_VALUE_CSV3);
  __SET_VAR(data__->,VAL_OUT_4,,__GET_VAR(data__->GET_VALUE_CSV3.VALUE_OUTFB,));
  __SET_VAR(data__->SET_VALUE_CSV1.,NAMEFILE,,__GET_VAR(data__->TAGS,.PID_1));
  __SET_VAR(data__->SET_VALUE_CSV1.,NAMEFIELD,,__STRING_LITERAL(9,"val_out_2"));
  __SET_VAR(data__->SET_VALUE_CSV1.,VALUE_IN,,__GET_VAR(data__->VAL_OUT_2,));
  SET_VALUE_CSV_body__(&data__->SET_VALUE_CSV1);
  __SET_VAR(data__->SET_VALUE_CSV2.,NAMEFILE,,__GET_VAR(data__->TAGS,.PID_1));
  __SET_VAR(data__->SET_VALUE_CSV2.,NAMEFIELD,,__STRING_LITERAL(9,"val_out_6"));
  __SET_VAR(data__->SET_VALUE_CSV2.,VALUE_IN,,__GET_VAR(data__->VAL_OUT_6,));
  SET_VALUE_CSV_body__(&data__->SET_VALUE_CSV2);
  __SET_VAR(data__->SET_VALUE_CSV3.,NAMEFILE,,__GET_VAR(data__->TAGS,.PID_1));
  __SET_VAR(data__->SET_VALUE_CSV3.,NAMEFIELD,,__STRING_LITERAL(5,"VAL_5"));
  __SET_VAR(data__->SET_VALUE_CSV3.,VALUE_IN,,__GET_VAR(data__->VAL_OUT_5,));
  SET_VALUE_CSV_body__(&data__->SET_VALUE_CSV3);

  goto __end;

__end:
  return;
} // TESTCSV_body__() 





void TESTCSV_V_1_init__(TESTCSV_V_1 *data__, BOOL retain) {
  __INIT_VAR(data__->PYTRIGER,__BOOL_LITERAL(FALSE),retain)
  {
    static const DATATYPE0 temp = {__STRING_LITERAL(14,"_1NJ20T001.csv"),__STRING_LITERAL(14,"_1CV20T001.csv"),__STRING_LITERAL(12,"Rashod_1.csv"),__STRING_LITERAL(12,"Rashod_2.csv"),__STRING_LITERAL(9,"PID_1.csv"),__STRING_LITERAL(9,"PID_2.csv"),__STRING_LITERAL(9,"PID_3.csv"),__STRING_LITERAL(2,"IN"),__STRING_LITERAL(3,"OUT"),__STRING_LITERAL(7,"IBM.csv"),__STRING_LITERAL(5,"Amper"),__STRING_LITERAL(7,"Amper_A"),__STRING_LITERAL(7,"Amper_B"),__STRING_LITERAL(7,"Amper_C")};
    __SET_VAR(data__->,TAGS,,temp);
  }
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->I_STATUS_READ_CSV,0,retain)
  __INIT_VAR(data__->I_STATUS_READ_CSV1,0,retain)
  __INIT_VAR(data__->I_STATUS_WRITE_CSV,0,retain)
  __INIT_VAR(data__->I_STATUS_OPEN_CSV,0,retain)
  __INIT_VAR(data__->VAL_OUT_1,0,retain)
  __INIT_VAR(data__->VAL_OUT_2,0,retain)
  __INIT_VAR(data__->VAL_OUT_3,0,retain)
  __INIT_VAR(data__->VAL_OUT_4,0,retain)
  __INIT_VAR(data__->VAL_OUT_5,0,retain)
  __INIT_VAR(data__->VAL_OUT_6,0,retain)
  __INIT_VAR(data__->VAL_OUT_7,0,retain)
  __INIT_VAR(data__->VAL_OUT_8,0,retain)
  __INIT_VAR(data__->VAL_OUT_9,0,retain)
  __INIT_VAR(data__->VAL_OUT_10,0,retain)
  {
    static const DATATYPE0 temp = {__STRING_LITERAL(14,"_1NJ20T001.csv"),__STRING_LITERAL(14,"_1CV20T001.csv"),__STRING_LITERAL(12,"Rashod_1.csv"),__STRING_LITERAL(12,"Rashod_2.csv"),__STRING_LITERAL(9,"PID_1.csv"),__STRING_LITERAL(9,"PID_2.csv"),__STRING_LITERAL(9,"PID_3.csv"),__STRING_LITERAL(2,"IN"),__STRING_LITERAL(3,"OUT"),__STRING_LITERAL(7,"IBM.csv"),__STRING_LITERAL(5,"Amper"),__STRING_LITERAL(7,"Amper_A"),__STRING_LITERAL(7,"Amper_B"),__STRING_LITERAL(7,"Amper_C")};
    __SET_VAR(data__->,VAL_IN,,temp);
  }
  GET_VALUE_CSV_init__(&data__->GET_VALUE_CSV0,retain);
  GET_VALUE_CSV_init__(&data__->GET_VALUE_CSV1,retain);
  SOURCEFROMFILECSV_init__(&data__->SOURCEFROMFILECSV0,retain);
  SOURCEFROMFILECSV_init__(&data__->SOURCEFROMFILECSV1,retain);
  GET_VALUE_CSV_init__(&data__->GET_VALUE_CSV2,retain);
  GET_VALUE_CSV_init__(&data__->GET_VALUE_CSV3,retain);
  SET_VALUE_CSV_init__(&data__->SET_VALUE_CSV0,retain);
  SET_VALUE_CSV_init__(&data__->SET_VALUE_CSV1,retain);
  SET_VALUE_CSV_init__(&data__->SET_VALUE_CSV2,retain);
  SET_VALUE_CSV_init__(&data__->SET_VALUE_CSV3,retain);
  SET_VALUE_CSV_init__(&data__->SET_VALUE_CSV4,retain);
  SET_VALUE_CSV_init__(&data__->SET_VALUE_CSV5,retain);
  __INIT_VAR(data__->MUL31_OUT,0,retain)
  __INIT_VAR(data__->ADD29_OUT,0,retain)
}

// Code part
void TESTCSV_V_1_body__(TESTCSV_V_1 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->SET_VALUE_CSV4.,NAMEFILE,,__GET_VAR(data__->TAGS,.PID_2));
  __SET_VAR(data__->SET_VALUE_CSV4.,NAMEFIELD,,__STRING_LITERAL(9,"val_out_3"));
  __SET_VAR(data__->SET_VALUE_CSV4.,VALUE_IN,,__GET_VAR(data__->VAL_OUT_3,));
  SET_VALUE_CSV_body__(&data__->SET_VALUE_CSV4);
  __SET_VAR(data__->GET_VALUE_CSV0.,NAMEFILE,,__GET_VAR(data__->TAGS,.PID_1));
  __SET_VAR(data__->GET_VALUE_CSV0.,NAMEFIELD,,__GET_VAR(data__->VAL_IN,.IN));
  GET_VALUE_CSV_body__(&data__->GET_VALUE_CSV0);
  __SET_VAR(data__->,VAL_OUT_1,,__GET_VAR(data__->GET_VALUE_CSV0.VALUE_OUTFB,));
  __SET_VAR(data__->,MUL31_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->VAL_OUT_1,),
    (REAL)__GET_VAR(data__->VAL_OUT_2,)));
  __SET_VAR(data__->,VAL_OUT_6,,__GET_VAR(data__->MUL31_OUT,));
  __SET_VAR(data__->GET_VALUE_CSV1.,NAMEFILE,,__GET_VAR(data__->TAGS,.PID_1));
  __SET_VAR(data__->GET_VALUE_CSV1.,NAMEFIELD,,__GET_VAR(data__->VAL_IN,.OUT));
  GET_VALUE_CSV_body__(&data__->GET_VALUE_CSV1);
  __SET_VAR(data__->,VAL_OUT_2,,__GET_VAR(data__->GET_VALUE_CSV1.VALUE_OUTFB,));
  __SET_VAR(data__->GET_VALUE_CSV2.,NAMEFILE,,__GET_VAR(data__->TAGS,.PID_2));
  __SET_VAR(data__->GET_VALUE_CSV2.,NAMEFIELD,,__STRING_LITERAL(4,"IN_1"));
  GET_VALUE_CSV_body__(&data__->GET_VALUE_CSV2);
  __SET_VAR(data__->,VAL_OUT_3,,__GET_VAR(data__->GET_VALUE_CSV2.VALUE_OUTFB,));
  __SET_VAR(data__->,ADD29_OUT,,ADD__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->VAL_OUT_3,),
    (REAL)__GET_VAR(data__->VAL_OUT_4,)));
  __SET_VAR(data__->,VAL_OUT_5,,__GET_VAR(data__->ADD29_OUT,));
  __SET_VAR(data__->GET_VALUE_CSV3.,NAMEFILE,,__GET_VAR(data__->TAGS,.PID_2));
  __SET_VAR(data__->GET_VALUE_CSV3.,NAMEFIELD,,__STRING_LITERAL(4,"IN_2"));
  GET_VALUE_CSV_body__(&data__->GET_VALUE_CSV3);
  __SET_VAR(data__->,VAL_OUT_4,,__GET_VAR(data__->GET_VALUE_CSV3.VALUE_OUTFB,));
  __SET_VAR(data__->SET_VALUE_CSV0.,NAMEFILE,,__GET_VAR(data__->TAGS,.PID_1));
  __SET_VAR(data__->SET_VALUE_CSV0.,NAMEFIELD,,__STRING_LITERAL(9,"val_out_1"));
  __SET_VAR(data__->SET_VALUE_CSV0.,VALUE_IN,,__GET_VAR(data__->VAL_OUT_1,));
  SET_VALUE_CSV_body__(&data__->SET_VALUE_CSV0);
  __SET_VAR(data__->SOURCEFROMFILECSV0.,NAMEFILEFB,,__GET_VAR(data__->TAGS,.PID_1));
  SOURCEFROMFILECSV_body__(&data__->SOURCEFROMFILECSV0);
  __SET_VAR(data__->SET_VALUE_CSV1.,NAMEFILE,,__GET_VAR(data__->TAGS,.PID_1));
  __SET_VAR(data__->SET_VALUE_CSV1.,NAMEFIELD,,__STRING_LITERAL(9,"val_out_2"));
  __SET_VAR(data__->SET_VALUE_CSV1.,VALUE_IN,,__GET_VAR(data__->VAL_OUT_2,));
  SET_VALUE_CSV_body__(&data__->SET_VALUE_CSV1);
  __SET_VAR(data__->SET_VALUE_CSV2.,NAMEFILE,,__GET_VAR(data__->TAGS,.PID_1));
  __SET_VAR(data__->SET_VALUE_CSV2.,NAMEFIELD,,__STRING_LITERAL(9,"val_out_6"));
  __SET_VAR(data__->SET_VALUE_CSV2.,VALUE_IN,,__GET_VAR(data__->VAL_OUT_6,));
  SET_VALUE_CSV_body__(&data__->SET_VALUE_CSV2);
  __SET_VAR(data__->SOURCEFROMFILECSV1.,NAMEFILEFB,,__GET_VAR(data__->TAGS,.PID_2));
  SOURCEFROMFILECSV_body__(&data__->SOURCEFROMFILECSV1);
  __SET_VAR(data__->SET_VALUE_CSV3.,NAMEFILE,,__GET_VAR(data__->TAGS,.PID_1));
  __SET_VAR(data__->SET_VALUE_CSV3.,NAMEFIELD,,__STRING_LITERAL(5,"VAL_5"));
  __SET_VAR(data__->SET_VALUE_CSV3.,VALUE_IN,,__GET_VAR(data__->VAL_OUT_5,));
  SET_VALUE_CSV_body__(&data__->SET_VALUE_CSV3);
  __SET_VAR(data__->SET_VALUE_CSV5.,NAMEFILE,,__GET_VAR(data__->TAGS,.PID_2));
  __SET_VAR(data__->SET_VALUE_CSV5.,NAMEFIELD,,__STRING_LITERAL(9,"val_out_4"));
  __SET_VAR(data__->SET_VALUE_CSV5.,VALUE_IN,,__GET_VAR(data__->VAL_OUT_4,));
  SET_VALUE_CSV_body__(&data__->SET_VALUE_CSV5);

  goto __end;

__end:
  return;
} // TESTCSV_V_1_body__() 





void TESTCSV_V_3_init__(TESTCSV_V_3 *data__, BOOL retain) {
  __INIT_VAR(data__->PYTRIGER,__BOOL_LITERAL(FALSE),retain)
  {
    static const DATATYPE0 temp = {__STRING_LITERAL(14,"_1NJ20T001.csv"),__STRING_LITERAL(14,"_1CV20T001.csv"),__STRING_LITERAL(12,"Rashod_1.csv"),__STRING_LITERAL(12,"Rashod_2.csv"),__STRING_LITERAL(9,"PID_1.csv"),__STRING_LITERAL(9,"PID_2.csv"),__STRING_LITERAL(9,"PID_3.csv"),__STRING_LITERAL(2,"IN"),__STRING_LITERAL(3,"OUT"),__STRING_LITERAL(7,"IBM.csv"),__STRING_LITERAL(5,"Amper"),__STRING_LITERAL(7,"Amper_A"),__STRING_LITERAL(7,"Amper_B"),__STRING_LITERAL(7,"Amper_C")};
    __SET_VAR(data__->,TAGS,,temp);
  }
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(14,"Initial String"),retain)
  __INIT_VAR(data__->I_STATUS_READ_CSV,0,retain)
  __INIT_VAR(data__->I_STATUS_READ_CSV1,0,retain)
  __INIT_VAR(data__->I_STATUS_WRITE_CSV,0,retain)
  __INIT_VAR(data__->I_STATUS_OPEN_CSV,0,retain)
  __INIT_VAR(data__->VAL_OUT_1,0.0,retain)
  __INIT_VAR(data__->VAL_OUT_2,0.0,retain)
  __INIT_VAR(data__->VAL_OUT_3,0.0,retain)
  {
    static const DATATYPE0 temp = {__STRING_LITERAL(14,"_1NJ20T001.csv"),__STRING_LITERAL(14,"_1CV20T001.csv"),__STRING_LITERAL(12,"Rashod_1.csv"),__STRING_LITERAL(12,"Rashod_2.csv"),__STRING_LITERAL(9,"PID_1.csv"),__STRING_LITERAL(9,"PID_2.csv"),__STRING_LITERAL(9,"PID_3.csv"),__STRING_LITERAL(2,"IN"),__STRING_LITERAL(3,"OUT"),__STRING_LITERAL(7,"IBM.csv"),__STRING_LITERAL(5,"Amper"),__STRING_LITERAL(7,"Amper_A"),__STRING_LITERAL(7,"Amper_B"),__STRING_LITERAL(7,"Amper_C")};
    __SET_VAR(data__->,VAL_IN,,temp);
  }
  SOURCEFROMFILECSV_init__(&data__->SOURCEFROMFILECSV0,retain);
  GET_VALUE_CSV_init__(&data__->GET_VALUE_CSV0,retain);
  GET_VALUE_CSV_init__(&data__->GET_VALUE_CSV1,retain);
  SET_VALUE_CSV_init__(&data__->SET_VALUE_CSV0,retain);
  SET_VALUE_CSV_init__(&data__->SET_VALUE_CSV1,retain);
  SET_VALUE_CSV_init__(&data__->SET_VALUE_CSV2,retain);
  INTEGRAL_init__(&data__->INTEGRAL0,retain);
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->CYCLE,__STRING_LITERAL(5,"0:0:1"),retain)
  __INIT_VAR(data__->TRIGER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->NOT22_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STRING_TO_TIME23_OUT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void TESTCSV_V_3_body__(TESTCSV_V_3 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->GET_VALUE_CSV0.,NAMEFILE,,__STRING_LITERAL(6,"dg.csv"));
  __SET_VAR(data__->GET_VALUE_CSV0.,NAMEFIELD,,__STRING_LITERAL(11,"consumption"));
  GET_VALUE_CSV_body__(&data__->GET_VALUE_CSV0);
  __SET_VAR(data__->,VAL_OUT_1,,__GET_VAR(data__->GET_VALUE_CSV0.VALUE_OUTFB,));
  __SET_VAR(data__->,NOT22_OUT,,!(__GET_VAR(data__->TRIGER,)));
  __SET_VAR(data__->,STRING_TO_TIME23_OUT,,STRING_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (STRING)__GET_VAR(data__->CYCLE,)));
  __SET_VAR(data__->INTEGRAL0.,RUN,,__GET_VAR(data__->RUN,));
  __SET_VAR(data__->INTEGRAL0.,R1,,__GET_VAR(data__->NOT22_OUT,));
  __SET_VAR(data__->INTEGRAL0.,XIN,,__GET_VAR(data__->VAL_OUT_1,));
  __SET_VAR(data__->INTEGRAL0.,X0,,__GET_VAR(data__->VAL_OUT_2,));
  __SET_VAR(data__->INTEGRAL0.,CYCLE,,__GET_VAR(data__->STRING_TO_TIME23_OUT,));
  INTEGRAL_body__(&data__->INTEGRAL0);
  __SET_VAR(data__->,VAL_OUT_3,,__GET_VAR(data__->INTEGRAL0.XOUT,));
  __SET_VAR(data__->GET_VALUE_CSV1.,NAMEFILE,,__STRING_LITERAL(6,"dg.csv"));
  __SET_VAR(data__->GET_VALUE_CSV1.,NAMEFIELD,,__STRING_LITERAL(5,"angle"));
  GET_VALUE_CSV_body__(&data__->GET_VALUE_CSV1);
  __SET_VAR(data__->,VAL_OUT_2,,__GET_VAR(data__->GET_VALUE_CSV1.VALUE_OUTFB,));
  __SET_VAR(data__->,TRIGER,,__GET_VAR(data__->NOT22_OUT,));
  __SET_VAR(data__->SOURCEFROMFILECSV0.,NAMEFILEFB,,__STRING_LITERAL(6,"dg.csv"));
  SOURCEFROMFILECSV_body__(&data__->SOURCEFROMFILECSV0);
  __SET_VAR(data__->SET_VALUE_CSV0.,NAMEFILE,,__STRING_LITERAL(6,"dg.csv"));
  __SET_VAR(data__->SET_VALUE_CSV0.,NAMEFIELD,,__STRING_LITERAL(9,"val_out_3"));
  __SET_VAR(data__->SET_VALUE_CSV0.,VALUE_IN,,__GET_VAR(data__->VAL_OUT_3,));
  SET_VALUE_CSV_body__(&data__->SET_VALUE_CSV0);
  __SET_VAR(data__->SET_VALUE_CSV1.,NAMEFILE,,__STRING_LITERAL(6,"dg.csv"));
  __SET_VAR(data__->SET_VALUE_CSV1.,NAMEFIELD,,__STRING_LITERAL(9,"val_out_1"));
  __SET_VAR(data__->SET_VALUE_CSV1.,VALUE_IN,,__GET_VAR(data__->VAL_OUT_1,));
  SET_VALUE_CSV_body__(&data__->SET_VALUE_CSV1);
  __SET_VAR(data__->SET_VALUE_CSV2.,NAMEFILE,,__STRING_LITERAL(6,"dg.csv"));
  __SET_VAR(data__->SET_VALUE_CSV2.,NAMEFIELD,,__STRING_LITERAL(9,"val_out_2"));
  __SET_VAR(data__->SET_VALUE_CSV2.,VALUE_IN,,__GET_VAR(data__->VAL_OUT_2,));
  SET_VALUE_CSV_body__(&data__->SET_VALUE_CSV2);

  goto __end;

__end:
  return;
} // TESTCSV_V_3_body__() 





void TESTCSV_V_2_init__(TESTCSV_V_2 *data__, BOOL retain) {
  __INIT_VAR(data__->PYTRIGER,__BOOL_LITERAL(FALSE),retain)
  {
    static const DATATYPE0 temp = {__STRING_LITERAL(14,"_1NJ20T001.csv"),__STRING_LITERAL(14,"_1CV20T001.csv"),__STRING_LITERAL(12,"Rashod_1.csv"),__STRING_LITERAL(12,"Rashod_2.csv"),__STRING_LITERAL(9,"PID_1.csv"),__STRING_LITERAL(9,"PID_2.csv"),__STRING_LITERAL(9,"PID_3.csv"),__STRING_LITERAL(2,"IN"),__STRING_LITERAL(3,"OUT"),__STRING_LITERAL(7,"IBM.csv"),__STRING_LITERAL(5,"Amper"),__STRING_LITERAL(7,"Amper_A"),__STRING_LITERAL(7,"Amper_B"),__STRING_LITERAL(7,"Amper_C")};
    __SET_VAR(data__->,TAGS,,temp);
  }
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(14,"Initial String"),retain)
  __INIT_VAR(data__->I_STATUS_READ_CSV,0,retain)
  __INIT_VAR(data__->I_STATUS_READ_CSV1,0,retain)
  __INIT_VAR(data__->I_STATUS_WRITE_CSV,0,retain)
  __INIT_VAR(data__->I_STATUS_OPEN_CSV,0,retain)
  __INIT_VAR(data__->VAL_OUT_1,0.0,retain)
  __INIT_VAR(data__->VAL_OUT_2,0.0,retain)
  __INIT_VAR(data__->VAL_OUT_3,0.0,retain)
  __INIT_VAR(data__->VAL_OUT_4,0.0,retain)
  __INIT_VAR(data__->VAL_OUT_5,0.0,retain)
  __INIT_VAR(data__->VAL_OUT_6,0.0,retain)
  __INIT_VAR(data__->VAL_OUT_7,0.0,retain)
  __INIT_VAR(data__->VAL_OUT_8,0.0,retain)
  __INIT_VAR(data__->VAL_OUT_9,0.0,retain)
  __INIT_VAR(data__->VAL_OUT_10,0.0,retain)
  __INIT_VAR(data__->VAL_OUT_11,10.0,retain)
  {
    static const DATATYPE0 temp = {__STRING_LITERAL(14,"_1NJ20T001.csv"),__STRING_LITERAL(14,"_1CV20T001.csv"),__STRING_LITERAL(12,"Rashod_1.csv"),__STRING_LITERAL(12,"Rashod_2.csv"),__STRING_LITERAL(9,"PID_1.csv"),__STRING_LITERAL(9,"PID_2.csv"),__STRING_LITERAL(9,"PID_3.csv"),__STRING_LITERAL(2,"IN"),__STRING_LITERAL(3,"OUT"),__STRING_LITERAL(7,"IBM.csv"),__STRING_LITERAL(5,"Amper"),__STRING_LITERAL(7,"Amper_A"),__STRING_LITERAL(7,"Amper_B"),__STRING_LITERAL(7,"Amper_C")};
    __SET_VAR(data__->,VAL_IN,,temp);
  }
  SOURCEFROMFILECSV_init__(&data__->SOURCEFROMFILECSV0,retain);
  GET_VALUE_CSV_init__(&data__->GET_VALUE_CSV0,retain);
  GET_VALUE_CSV_init__(&data__->GET_VALUE_CSV1,retain);
  SET_VALUE_CSV_init__(&data__->SET_VALUE_CSV0,retain);
  SET_VALUE_CSV_init__(&data__->SET_VALUE_CSV1,retain);
  SET_VALUE_CSV_init__(&data__->SET_VALUE_CSV2,retain);
  __INIT_VAR(data__->ADD9_OUT,0,retain)
}

// Code part
void TESTCSV_V_2_body__(TESTCSV_V_2 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->GET_VALUE_CSV0.,NAMEFILE,,__STRING_LITERAL(9,"PID_1.csv"));
  __SET_VAR(data__->GET_VALUE_CSV0.,NAMEFIELD,,__STRING_LITERAL(4,"IN_1"));
  GET_VALUE_CSV_body__(&data__->GET_VALUE_CSV0);
  __SET_VAR(data__->,VAL_OUT_1,,__GET_VAR(data__->GET_VALUE_CSV0.VALUE_OUTFB,));
  __SET_VAR(data__->,ADD9_OUT,,ADD__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->VAL_OUT_1,),
    (REAL)__GET_VAR(data__->VAL_OUT_2,)));
  __SET_VAR(data__->,VAL_OUT_3,,__GET_VAR(data__->ADD9_OUT,));
  __SET_VAR(data__->GET_VALUE_CSV1.,NAMEFILE,,__STRING_LITERAL(9,"PID_1.csv"));
  __SET_VAR(data__->GET_VALUE_CSV1.,NAMEFIELD,,__STRING_LITERAL(4,"IN_2"));
  GET_VALUE_CSV_body__(&data__->GET_VALUE_CSV1);
  __SET_VAR(data__->,VAL_OUT_2,,__GET_VAR(data__->GET_VALUE_CSV1.VALUE_OUTFB,));
  __SET_VAR(data__->SOURCEFROMFILECSV0.,NAMEFILEFB,,__STRING_LITERAL(9,"PID_1.csv"));
  SOURCEFROMFILECSV_body__(&data__->SOURCEFROMFILECSV0);
  __SET_VAR(data__->SET_VALUE_CSV0.,NAMEFILE,,__STRING_LITERAL(9,"PID_1.csv"));
  __SET_VAR(data__->SET_VALUE_CSV0.,NAMEFIELD,,__STRING_LITERAL(9,"val_out_3"));
  __SET_VAR(data__->SET_VALUE_CSV0.,VALUE_IN,,__GET_VAR(data__->VAL_OUT_3,));
  SET_VALUE_CSV_body__(&data__->SET_VALUE_CSV0);
  __SET_VAR(data__->SET_VALUE_CSV1.,NAMEFILE,,__STRING_LITERAL(9,"PID_1.csv"));
  __SET_VAR(data__->SET_VALUE_CSV1.,NAMEFIELD,,__STRING_LITERAL(9,"val_out_1"));
  __SET_VAR(data__->SET_VALUE_CSV1.,VALUE_IN,,__GET_VAR(data__->VAL_OUT_1,));
  SET_VALUE_CSV_body__(&data__->SET_VALUE_CSV1);
  __SET_VAR(data__->SET_VALUE_CSV2.,NAMEFILE,,__STRING_LITERAL(9,"PID_1.csv"));
  __SET_VAR(data__->SET_VALUE_CSV2.,NAMEFIELD,,__STRING_LITERAL(9,"val_out_2"));
  __SET_VAR(data__->SET_VALUE_CSV2.,VALUE_IN,,__GET_VAR(data__->VAL_OUT_2,));
  SET_VALUE_CSV_body__(&data__->SET_VALUE_CSV2);

  goto __end;

__end:
  return;
} // TESTCSV_V_2_body__() 





