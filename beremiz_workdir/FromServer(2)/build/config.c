/*******************************************/
/*     FILE GENERATED BY iec2c             */
/* Editing this file is not recommended... */
/*******************************************/

#include "iec_std_lib.h"

#include "accessor.h"

#include "POUS.h"

// CONFIGURATION CONFIG
__DECLARE_GLOBAL(INT,CONFIG,DEBUG)
__DECLARE_GLOBAL(STRING,CONFIG,PATH)
__DECLARE_GLOBAL(INT,CONFIG,I_STATUS)
__DECLARE_GLOBAL(STRING,CONFIG,HOST)
__DECLARE_GLOBAL(INT,CONFIG,PORT)
__DECLARE_GLOBAL(INT,CONFIG,INFO)
__DECLARE_GLOBAL(INT,CONFIG,WARNING)
__DECLARE_GLOBAL(INT,CONFIG,ERROR)

void RESOURCE1_init__(void);

void config_init__(void) {
  BOOL retain;
  retain = 0;
  __INIT_GLOBAL(INT,DEBUG,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(STRING,PATH,__INITIAL_VALUE(__STRING_LITERAL(43,"C:\\\\users\\\\user\\\\Beremiz\\\\beremiz_workdir\\\\")),retain)
  __INIT_GLOBAL(INT,I_STATUS,__INITIAL_VALUE(1),retain)
  __INIT_GLOBAL(STRING,HOST,__INITIAL_VALUE(__STRING_LITERAL(9,"localhost")),retain)
  __INIT_GLOBAL(INT,PORT,__INITIAL_VALUE(8889),retain)
  __INIT_GLOBAL(INT,INFO,__INITIAL_VALUE(1),retain)
  __INIT_GLOBAL(INT,WARNING,__INITIAL_VALUE(2),retain)
  __INIT_GLOBAL(INT,ERROR,__INITIAL_VALUE(3),retain)
  RESOURCE1_init__();
}

void RESOURCE1_run__(unsigned long tick);

void config_run__(unsigned long tick) {
  RESOURCE1_run__(tick);
}
unsigned long long common_ticktime__ = 50000000ULL; /*ns*/
unsigned long greatest_tick_count__ = (unsigned long)0UL; /*tick*/
