/*******************************************/
/*     FILE GENERATED BY iec2c             */
/* Editing this file is not recommended... */
/*******************************************/

#include "iec_std_lib.h"

#include "accessor.h"

#include "POUS.h"

// CONFIGURATION CONFIG
__DECLARE_GLOBAL(INT,CONFIG,TEST_PYTHON_VAR)
__DECLARE_GLOBAL(INT,CONFIG,SECOND_PYTHON_VAR)
__DECLARE_GLOBAL(INT,CONFIG,TEST)

void RESOURCE1_init__(void);

void config_init__(void) {
  BOOL retain;
  retain = 0;
  __INIT_GLOBAL(INT,TEST_PYTHON_VAR,__INITIAL_VALUE(4),retain)
  __INIT_GLOBAL(INT,SECOND_PYTHON_VAR,__INITIAL_VALUE(5),retain)
  __INIT_GLOBAL(INT,TEST,__INITIAL_VALUE(1),retain)
  RESOURCE1_init__();
}

void RESOURCE1_run__(unsigned long tick);

void config_run__(unsigned long tick) {
  RESOURCE1_run__(tick);
}
unsigned long long common_ticktime__ = 1000000000ULL; /*ns*/
unsigned long greatest_tick_count__ = (unsigned long)0UL; /*tick*/
