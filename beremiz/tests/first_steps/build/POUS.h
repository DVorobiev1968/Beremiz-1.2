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
// FUNCTION_BLOCK COUNTERSFC
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,RESET)
  __DECLARE_VAR(INT,OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,CNT)
  __DECLARE_EXTERNAL(INT,RESETCOUNTERVALUE)
  STEP __step_list[3];
  UINT __nb_steps;
  ACTION __action_list[4];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[4];
  __IEC_BOOL_t __debug_transition_list[4];
  UINT __nb_transitions;
  TIME __lasttick_time;

} COUNTERSFC;

void COUNTERSFC_init__(COUNTERSFC *data__, BOOL retain);
// Code part
void COUNTERSFC_body__(COUNTERSFC *data__);
// FUNCTION_BLOCK COUNTERFBD
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,RESET)
  __DECLARE_VAR(INT,OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,CNT)
  __DECLARE_EXTERNAL(INT,RESETCOUNTERVALUE)
  __DECLARE_VAR(INT,ADD4_OUT)
  __DECLARE_VAR(INT,SEL7_OUT)

} COUNTERFBD;

void COUNTERFBD_init__(COUNTERFBD *data__, BOOL retain);
// Code part
void COUNTERFBD_body__(COUNTERFBD *data__);
// FUNCTION_BLOCK COUNTERIL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,RESET)
  __DECLARE_VAR(INT,OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,CNT)
  __DECLARE_EXTERNAL(INT,RESETCOUNTERVALUE)

} COUNTERIL;

void COUNTERIL_init__(COUNTERIL *data__, BOOL retain);
// Code part
void COUNTERIL_body__(COUNTERIL *data__);
// FUNCTION_BLOCK COUNTERST
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,RESET)
  __DECLARE_VAR(INT,OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,CNT)
  __DECLARE_EXTERNAL(INT,RESETCOUNTERVALUE)

} COUNTERST;

void COUNTERST_init__(COUNTERST *data__, BOOL retain);
// Code part
void COUNTERST_body__(COUNTERST *data__);
// FUNCTION_BLOCK COUNTERLD
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,RESET)
  __DECLARE_VAR(INT,OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,CNT)
  __DECLARE_EXTERNAL(INT,RESETCOUNTERVALUE)
  __DECLARE_VAR(INT,ADD4_OUT)
  __DECLARE_VAR(INT,SEL7_OUT)

} COUNTERLD;

void COUNTERLD_init__(COUNTERLD *data__, BOOL retain);
// Code part
void COUNTERLD_body__(COUNTERLD *data__);
// PROGRAM PLC_PRG
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,RESET)
  __DECLARE_VAR(INT,CNT1)
  __DECLARE_VAR(INT,CNT2)
  __DECLARE_VAR(INT,CNT3)
  __DECLARE_VAR(INT,CNT4)
  __DECLARE_VAR(INT,CNT5)

  // PROGRAM private variables - TEMP, private and located variables
  COUNTERST COUNTERST0;
  COUNTERFBD COUNTERFBD0;
  COUNTERSFC COUNTERSFC0;
  COUNTERIL COUNTERIL0;
  COUNTERLD COUNTERLD0;

} PLC_PRG;

void PLC_PRG_init__(PLC_PRG *data__, BOOL retain);
// Code part
void PLC_PRG_body__(PLC_PRG *data__);
#endif //__POUS_H
