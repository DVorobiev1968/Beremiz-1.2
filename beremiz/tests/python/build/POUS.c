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





void C_PRAGMA_init__(C_PRAGMA *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->IN,0,retain)
  {
    static const __ARRAY_OF_SINT_6 temp = {{54,55,56,57,58,59}};
    __SET_VAR(data__->,COORDS,,temp);
  }
  {
    static const CPLX_TYPE temp = {0,0};
    __SET_VAR(data__->,SMURF,,temp);
  }
  __INIT_EXTERNAL_FB(RS,GLOBAL_RS,data__->GLOBAL_RS,retain)
}

// Code part
void C_PRAGMA_body__(C_PRAGMA *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

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
  
  #undef GetFbVar
  #undef SetFbVar
;
  RS_body__(data__->GLOBAL_RS);

  goto __end;

__end:
  return;
} // C_PRAGMA_body__() 





// FUNCTION
DATATYPE0 FUNCTION0(
  BOOL EN, 
  BOOL *__ENO, 
  DATATYPE0 LOCALVAR0)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DATATYPE0 FUNCTION0 = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return FUNCTION0;
  }
  FUNCTION0 = LOCALVAR0;

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return FUNCTION0;
}


static inline UINT __MAIN_PYTEST_BCD_TO_UINT__UINT__WORD1(BOOL EN,
  WORD IN,
  MAIN_PYTEST *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->BCD_TO_UINT67_ENO,);
  __res = BCD_TO_UINT__UINT__WORD(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->BCD_TO_UINT67_ENO,,__TMP_ENO);
  return __res;
}

void MAIN_PYTEST_init__(MAIN_PYTEST *data__, BOOL retain) {
  __INIT_VAR(data__->MUX1_SEL,3,retain)
  __INIT_VAR(data__->MUX2_SEL,3,retain)
  __INIT_VAR(data__->PYTEST_VAR1,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->FEFVSD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PYTEST_VAR2,__BOOL_LITERAL(FALSE),retain)
  PYTHON_EVAL_init__(&data__->PY1,retain);
  PYTHON_EVAL_init__(&data__->BLOCK1,retain);
  PYTHON_EVAL_init__(&data__->BLOCK2,retain);
  PYTHON_EVAL_init__(&data__->BLOCK3,retain);
  __INIT_VAR(data__->PYTEST_VAR3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FROMC,0,retain)
  C_PRAGMA_init__(&data__->C_PRAGMA0,retain);
  __INIT_EXTERNAL(SINT,TESTINPUT,data__->TESTINPUT,retain)
  __INIT_EXTERNAL(SINT,TESTOUTPUT,data__->TESTOUTPUT,retain)
  __INIT_VAR(data__->FROMINPUT,0,retain)
  __INIT_VAR(data__->TEST_BCD,151,retain)
  __INIT_VAR(data__->TEST_BCD_WRONG,154,retain)
  __INIT_VAR(data__->TEST_BCD_CONVERTED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TEST_BCD_RESULT,0,retain)
  __INIT_VAR(data__->TEST_BCD_WRONG_RESULT,0,retain)
  __INIT_VAR(data__->TEST_DT,__dt_to_timespec(46, 35, 22, 23, 2, 2013),retain)
  __INIT_VAR(data__->TEST_TOD,__tod_to_timespec(0, 0, 0),retain)
  __INIT_VAR(data__->TEST_TOD_STRING,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TEST_DATE,__date_to_timespec(1, 1, 1970),retain)
  __INIT_VAR(data__->TEST_STRING,__STRING_LITERAL(4,"test"),retain)
  __INIT_VAR(data__->TEST_BOOL,__BOOL_LITERAL(FALSE),retain)
  __INIT_EXTERNAL_FB(RS,GLOBAL_RS,data__->GLOBAL_RS,retain)
  __INIT_EXTERNAL(INT,TUTU,data__->TUTU,retain)
  __INIT_EXTERNAL(INT,TOTO,data__->TOTO,retain)
  __INIT_EXTERNAL(INT,TEST_PYTHON_VAR,data__->TEST_PYTHON_VAR,retain)
  __INIT_EXTERNAL(INT,SECOND_PYTHON_VAR,data__->SECOND_PYTHON_VAR,retain)
  __INIT_VAR(data__->NOT7_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MUX21_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MUX17_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->FUNCTION061_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BCD_TO_UINT35_OUT,0,retain)
  __INIT_VAR(data__->BCD_TO_UINT67_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BCD_TO_UINT67_OUT,0,retain)
  __INIT_VAR(data__->DATE_AND_TIME_TO_TIME_OF_DAY37_OUT,__tod_to_timespec(0, 0, 0),retain)
  __INIT_VAR(data__->TOD_TO_STRING55_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->DATE_AND_TIME_TO_DATE38_OUT,__date_to_timespec(1, 1, 1970),retain)
  __INIT_VAR(data__->INT_TO_STRING46_OUT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STRING_TO_BOOL44_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AND51_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OR41_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void MAIN_PYTEST_body__(MAIN_PYTEST *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,NOT7_OUT,,!(__GET_VAR(data__->PYTEST_VAR2,)));
  __SET_VAR(data__->PY1.,TRIG,,__GET_VAR(data__->NOT7_OUT,));
  __SET_VAR(data__->PY1.,CODE,,__STRING_LITERAL(13,"time.sleep(1)"));
  PYTHON_EVAL_body__(&data__->PY1);
  __SET_VAR(data__->BLOCK1.,TRIG,,__GET_VAR(data__->NOT7_OUT,));
  __SET_VAR(data__->BLOCK1.,CODE,,__STRING_LITERAL(41,"sys.stdout.write(\"FBID :\"+str(FBID)+\"\\n\")"));
  PYTHON_EVAL_body__(&data__->BLOCK1);
  __SET_VAR(data__->BLOCK2.,TRIG,,__GET_VAR(data__->NOT7_OUT,));
  __SET_VAR(data__->BLOCK2.,CODE,,__STRING_LITERAL(29,"PLCBinary.Simple_C_Call(5678)"));
  PYTHON_EVAL_body__(&data__->BLOCK2);
  __SET_VAR(data__->BLOCK3.,TRIG,,__GET_VAR(data__->NOT7_OUT,));
  __SET_VAR(data__->BLOCK3.,CODE,,__STRING_LITERAL(16,"MyPythonFunc(42)"));
  PYTHON_EVAL_body__(&data__->BLOCK3);
  __SET_VAR(data__->,MUX21_OUT,,MUX__BOOL__INT__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->MUX1_SEL,),
    (UINT)4,
    (BOOL)__GET_VAR(data__->PY1.ACK,),
    (BOOL)__GET_VAR(data__->BLOCK1.ACK,),
    (BOOL)__GET_VAR(data__->BLOCK2.ACK,),
    (BOOL)__GET_VAR(data__->BLOCK3.ACK,)));
  __SET_VAR(data__->,PYTEST_VAR3,,__GET_VAR(data__->MUX21_OUT,));
  __SET_VAR(data__->,PYTEST_VAR2,,__GET_VAR(data__->NOT7_OUT,));
  __SET_VAR(data__->,MUX17_OUT,,MUX__STRING__INT__STRING(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->MUX2_SEL,),
    (UINT)4,
    (STRING)__GET_VAR(data__->PY1.RESULT,),
    (STRING)__GET_VAR(data__->BLOCK1.RESULT,),
    (STRING)__GET_VAR(data__->BLOCK2.RESULT,),
    (STRING)__GET_VAR(data__->BLOCK3.RESULT,)));
  __SET_VAR(data__->,PYTEST_VAR1,,__GET_VAR(data__->MUX17_OUT,));
  __SET_VAR(data__->C_PRAGMA0.,IN,,23);
  C_PRAGMA_body__(&data__->C_PRAGMA0);
  __SET_VAR(data__->,FROMC,,__GET_VAR(data__->C_PRAGMA0.OUT,));
  __SET_EXTERNAL(data__->,TESTOUTPUT,,10);
  __SET_VAR(data__->,FROMINPUT,,__GET_EXTERNAL(data__->TESTINPUT,));
  __SET_VAR(data__->,FUNCTION061_OUT,,FUNCTION0(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DATATYPE0)__GET_VAR(data__->FEFVSD,)));
  __SET_VAR(data__->,FEFVSD,,__GET_VAR(data__->FUNCTION061_OUT,));
  __SET_EXTERNAL(data__->,TEST_PYTHON_VAR,,23);
  __SET_VAR(data__->,BCD_TO_UINT35_OUT,,BCD_TO_UINT__UINT__WORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (WORD)__GET_VAR(data__->TEST_BCD,)));
  __SET_VAR(data__->,TEST_BCD_RESULT,,__GET_VAR(data__->BCD_TO_UINT35_OUT,));
  __SET_VAR(data__->,BCD_TO_UINT67_OUT,,__MAIN_PYTEST_BCD_TO_UINT__UINT__WORD1(
    (BOOL)__BOOL_LITERAL(TRUE),
    (WORD)__GET_VAR(data__->TEST_BCD_WRONG,),
    data__));
  __SET_VAR(data__->,TEST_BCD_CONVERTED,,__GET_VAR(data__->BCD_TO_UINT67_ENO,));
  __SET_VAR(data__->,TEST_BCD_WRONG_RESULT,,__GET_VAR(data__->BCD_TO_UINT67_OUT,));
  __SET_VAR(data__->,DATE_AND_TIME_TO_TIME_OF_DAY37_OUT,,DATE_AND_TIME_TO_TIME_OF_DAY(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DT)__GET_VAR(data__->TEST_DT,)));
  __SET_VAR(data__->,TEST_TOD,,__GET_VAR(data__->DATE_AND_TIME_TO_TIME_OF_DAY37_OUT,));
  __SET_VAR(data__->,TOD_TO_STRING55_OUT,,TOD_TO_STRING(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TOD)__GET_VAR(data__->TEST_TOD,)));
  __SET_VAR(data__->,TEST_TOD_STRING,,__GET_VAR(data__->TOD_TO_STRING55_OUT,));
  __SET_VAR(data__->,DATE_AND_TIME_TO_DATE38_OUT,,DATE_AND_TIME_TO_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DT)__GET_VAR(data__->TEST_DT,)));
  __SET_VAR(data__->,TEST_DATE,,__GET_VAR(data__->DATE_AND_TIME_TO_DATE38_OUT,));
  __SET_VAR(data__->,INT_TO_STRING46_OUT,,INT_TO_STRING(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_EXTERNAL(data__->SECOND_PYTHON_VAR,)));
  __SET_VAR(data__->,TEST_STRING,,__GET_VAR(data__->INT_TO_STRING46_OUT,));
  __SET_VAR(data__->,STRING_TO_BOOL44_OUT,,STRING_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (STRING)__STRING_LITERAL(4,"True")));
  __SET_VAR(data__->,TEST_BOOL,,__GET_VAR(data__->STRING_TO_BOOL44_OUT,));
  __SET_VAR(data__->,AND51_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)!(__GET_VAR(data__->GLOBAL_RS->Q1,)),
    (BOOL)__BOOL_LITERAL(TRUE)));
  __SET_VAR(data__->,GLOBAL_RS->S,,__GET_VAR(data__->AND51_OUT,));
  __SET_VAR(data__->,OR41_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->GLOBAL_RS->Q1,),
    (BOOL)__BOOL_LITERAL(FALSE)));
  __SET_VAR(data__->,GLOBAL_RS->R1,,__GET_VAR(data__->OR41_OUT,));
  __SET_EXTERNAL(data__->,TOTO,,42);
  __SET_EXTERNAL(data__->,TUTU,,42);

  goto __end;

__end:
  return;
} // MAIN_PYTEST_body__() 





// FUNCTION
REAL NORM(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN1, 
  REAL IN2)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL NORM = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return NORM;
  }
  NORM = SQRT__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)((IN1 * IN1) + (IN2 * IN2)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return NORM;
}


