/*******************************************/
/*     FILE GENERATED BY iec2c             */
/* Editing this file is not recommended... */
/*******************************************/

#include "iec_std_lib.h"

// RESOURCE RESOURCE1

extern unsigned long long common_ticktime__;

#include "accessor.h"
#include "POUS.h"

#include "config.h"

#include "POUS.c"

BOOL TASKSERVER;
TEST_1 RESOURCE1__SRV;
#define SRV RESOURCE1__SRV

void RESOURCE1_init__(void) {
  BOOL retain;
  retain = 0;
  
  TASKSERVER = __BOOL_LITERAL(FALSE);
  TEST_1_init__(&SRV,retain);
}

void RESOURCE1_run__(unsigned long tick) {
  TASKSERVER = !(tick % 1);
  if (TASKSERVER) {
    TEST_1_body__(&SRV);
  }
}

