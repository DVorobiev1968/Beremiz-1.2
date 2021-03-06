#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// FUNCTION_BLOCK PYTHON_EVAL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,CODE)
  __DECLARE_VAR(BOOL,ACK)
  __DECLARE_VAR(STRING,RESULT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(DWORD,STATE)
  __DECLARE_VAR(STRING,BUFFER)
  __DECLARE_VAR(STRING,PREBUFFER)
  __DECLARE_VAR(BOOL,TRIGM1)
  __DECLARE_VAR(BOOL,TRIGGED)

} PYTHON_EVAL;

void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain);
// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__);
// FUNCTION_BLOCK PYTHON_POLL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,CODE)
  __DECLARE_VAR(BOOL,ACK)
  __DECLARE_VAR(STRING,RESULT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(DWORD,STATE)
  __DECLARE_VAR(STRING,BUFFER)
  __DECLARE_VAR(STRING,PREBUFFER)
  __DECLARE_VAR(BOOL,TRIGM1)
  __DECLARE_VAR(BOOL,TRIGGED)

} PYTHON_POLL;

void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain);
// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__);
// FUNCTION_BLOCK PYTHON_GEAR
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(UINT,N)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,CODE)
  __DECLARE_VAR(BOOL,ACK)
  __DECLARE_VAR(STRING,RESULT)

  // FB private variables - TEMP, private and located variables
  PYTHON_EVAL PY_EVAL;
  __DECLARE_VAR(UINT,COUNTER)
  __DECLARE_VAR(UINT,ADD10_OUT)
  __DECLARE_VAR(BOOL,EQ13_OUT)
  __DECLARE_VAR(UINT,SEL15_OUT)
  __DECLARE_VAR(BOOL,AND7_OUT)

} PYTHON_GEAR;

void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain);
// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__);
// FUNCTION_BLOCK GETBOOLSTRING
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,VALUE)
  __DECLARE_VAR(STRING,CODE)

  // FB private variables - TEMP, private and located variables

} GETBOOLSTRING;

void GETBOOLSTRING_init__(GETBOOLSTRING *data__, BOOL retain);
// Code part
void GETBOOLSTRING_body__(GETBOOLSTRING *data__);
// FUNCTION_BLOCK BUTTON
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(STRING,BACK_ID)
  __DECLARE_VAR(STRING,SELE_ID)
  __DECLARE_VAR(BOOL,TOGGLE)
  __DECLARE_VAR(BOOL,SET_STATE)
  __DECLARE_VAR(BOOL,STATE_IN)
  __DECLARE_VAR(BOOL,STATE_OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(STRING,ID)
  PYTHON_EVAL INIT_COMMAND;
  GETBOOLSTRING GETBUTTONSTATE;
  PYTHON_EVAL SETSTATE_COMMAND;
  PYTHON_POLL GETSTATE_COMMAND;
  GETBOOLSTRING GETBUTTONTOGGLE;
  __DECLARE_VAR(STRING,CONCAT2_OUT)
  __DECLARE_VAR(STRING,CONCAT22_OUT)
  __DECLARE_VAR(INT,STRING_TO_INT25_OUT)
  __DECLARE_VAR(BOOL,INT_TO_BOOL26_OUT)
  __DECLARE_VAR(BOOL,AND31_OUT)
  __DECLARE_VAR(STRING,CONCAT7_OUT)

} BUTTON;

void BUTTON_init__(BUTTON *data__, BOOL retain);
// Code part
void BUTTON_body__(BUTTON *data__);
// FUNCTION_BLOCK LED
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(STRING,BACK_ID)
  __DECLARE_VAR(STRING,SELE_ID)
  __DECLARE_VAR(BOOL,STATE_IN)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(STRING,ID)
  PYTHON_EVAL INIT_COMMAND;
  PYTHON_POLL SETSTATE_COMMAND;
  GETBOOLSTRING GETLEDSTATE;
  __DECLARE_VAR(STRING,CONCAT2_OUT)
  __DECLARE_VAR(STRING,CONCAT7_OUT)

} LED;

void LED_init__(LED *data__, BOOL retain);
// Code part
void LED_body__(LED *data__);
// FUNCTION_BLOCK TEXTCTRL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(STRING,BACK_ID)
  __DECLARE_VAR(BOOL,SET_TEXT)
  __DECLARE_VAR(STRING,TEXT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(STRING,ID)
  PYTHON_EVAL SVGUI_TEXTCTRL;
  PYTHON_EVAL SETSTATE_COMMAND;
  __DECLARE_VAR(STRING,CONCAT1_OUT)
  __DECLARE_VAR(BOOL,AND31_OUT)
  __DECLARE_VAR(STRING,CONCAT12_OUT)

} TEXTCTRL;

void TEXTCTRL_init__(TEXTCTRL *data__, BOOL retain);
// Code part
void TEXTCTRL_body__(TEXTCTRL *data__);
// PROGRAM MAIN
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,IN)
  __DECLARE_VAR(INT,OUT)
  __DECLARE_VAR(BOOL,B_TRIGER)
  PYTHON_EVAL PYTHON_EVAL0;
  __DECLARE_VAR(BOOL,NOT2_OUT)
  __DECLARE_VAR(INT,STRING_TO_INT5_OUT)

} MAIN;

void MAIN_init__(MAIN *data__, BOOL retain);
// Code part
void MAIN_body__(MAIN *data__);
#endif //__POUS_H
