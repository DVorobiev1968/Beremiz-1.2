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
__DECLARE_STRUCT_TYPE(CPLX_TYPE,
  SINT FIRSTBYTE;
    SINT SECONDBYTE;
  )
__DECLARE_ENUMERATED_TYPE(STATEMACHINE,
  STATEMACHINE__STANDBY,
  STATEMACHINE__START,
  STATEMACHINE__STOP
)
__DECLARE_ARRAY_TYPE(__ARRAY_OF_SINT_6,SINT,[6])
// FUNCTION_BLOCK C_PRAGMA
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(SINT,OUT)
  __DECLARE_VAR(SINT,IN)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(__ARRAY_OF_SINT_6,COORDS)
  __DECLARE_VAR(CPLX_TYPE,SMURF)
  __DECLARE_EXTERNAL_FB(RS,GLOBAL_RS)

} C_PRAGMA;

void C_PRAGMA_init__(C_PRAGMA *data__, BOOL retain);
// Code part
void C_PRAGMA_body__(C_PRAGMA *data__);
// PROGRAM MAIN_PYTEST
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(STRING,PYTEST_VAR1)
  __DECLARE_VAR(BOOL,PYTEST_VAR2)
  PYTHON_EVAL PY1;
  PYTHON_EVAL BLOCK1;
  PYTHON_EVAL BLOCK2;
  PYTHON_EVAL BLOCK3;
  __DECLARE_VAR(BOOL,PYTEST_VAR3)
  __DECLARE_VAR(SINT,FROMC)
  C_PRAGMA C_PRAGMA0;
  __DECLARE_LOCATED(SINT,TESTINPUT)
  __DECLARE_LOCATED(SINT,TESTOUTPUT)
  __DECLARE_VAR(SINT,FROMINPUT)
  __DECLARE_VAR(WORD,TEST_BCD)
  __DECLARE_VAR(UINT,TEST_BCD_RESULT)
  __DECLARE_VAR(BOOL,TEST_BCD_ENO)
  __DECLARE_VAR(DT,TEST_DT)
  __DECLARE_VAR(TOD,TEST_TOD)
  __DECLARE_VAR(STRING,TEST_TOD_STRING)
  __DECLARE_VAR(DATE,TEST_DATE)
  __DECLARE_VAR(STRING,TEST_STRING)
  __DECLARE_VAR(BOOL,TEST_BOOL)
  __DECLARE_EXTERNAL_FB(RS,GLOBAL_RS)
  __DECLARE_VAR(BOOL,NOT7_OUT)
  __DECLARE_VAR(BOOL,MUX21_OUT)
  __DECLARE_VAR(STRING,MUX17_OUT)
  __DECLARE_VAR(BOOL,BCD_TO_UINT35_ENO)
  __DECLARE_VAR(UINT,BCD_TO_UINT35_OUT)
  __DECLARE_VAR(TOD,DATE_AND_TIME_TO_TIME_OF_DAY37_OUT)
  __DECLARE_VAR(STRING,TOD_TO_STRING55_OUT)
  __DECLARE_VAR(DATE,DATE_AND_TIME_TO_DATE38_OUT)
  __DECLARE_VAR(STRING,BYTE_TO_STRING46_OUT)
  __DECLARE_VAR(BOOL,STRING_TO_BOOL44_OUT)
  __DECLARE_VAR(BOOL,AND51_OUT)
  __DECLARE_VAR(BOOL,OR41_OUT)

} MAIN_PYTEST;

void MAIN_PYTEST_init__(MAIN_PYTEST *data__, BOOL retain);
// Code part
void MAIN_PYTEST_body__(MAIN_PYTEST *data__);
// FUNCTION
REAL NORM(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN1, 
  REAL IN2);
#endif //__POUS_H
