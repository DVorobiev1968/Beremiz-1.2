/*******************************************/
/*     FILE GENERATED BY iec2c             */
/* Editing this file is not recommended... */
/*******************************************/

#include "iec_std_lib.h"

// RESOURCE RES_PYTEST

extern unsigned long long common_ticktime__;

#include "accessor.h"
#include "POUS.h"

#include "config.h"
__DECLARE_GLOBAL(REAL,RES_PYTEST,VALUEOUT)

#include "POUS.c"

BOOL PYTEST_TASK;
TESTCSV_V_3 RES_PYTEST__MYPROG;
#define MYPROG RES_PYTEST__MYPROG

void RES_PYTEST_init__(void) {
  BOOL retain;
  retain = 0;
  __INIT_GLOBAL(REAL,VALUEOUT,__INITIAL_VALUE(0),retain)
  PYTEST_TASK = __BOOL_LITERAL(FALSE);
  TESTCSV_V_3_init__(&MYPROG,retain);
}

void RES_PYTEST_run__(unsigned long tick) {
  PYTEST_TASK = !(tick % 1);
  TESTCSV_V_3_body__(&MYPROG);
}

