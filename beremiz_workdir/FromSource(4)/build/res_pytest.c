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

BOOL MAINTASK;
TESTCSV_V_3 RES_PYTEST__MAINPRG;
#define MAINPRG RES_PYTEST__MAINPRG

void RES_PYTEST_init__(void) {
  BOOL retain;
  retain = 0;
  __INIT_GLOBAL(REAL,VALUEOUT,__INITIAL_VALUE(0),retain)
  MAINTASK = __BOOL_LITERAL(FALSE);
  TESTCSV_V_3_init__(&MAINPRG,retain);
}

void RES_PYTEST_run__(unsigned long tick) {
  MAINTASK = !(tick % 1);
  TESTCSV_V_3_body__(&MAINPRG);
}
