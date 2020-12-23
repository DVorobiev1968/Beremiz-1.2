/*
 * Code generated by Beremiz py_ext confnode
 * for safe global variables access
 */
#include "iec_types_all.h"
#include "POUS.h"
#include "config.h"
#include "beremiz.h"

/* User variables reference */
extern  __IEC_INT_t CONFIG__DEBUG;
IEC_INT __debug_rbuffer = __INIT_INT;
IEC_INT __debug_wbuffer;
long __debug_rlock = 0;
long __debug_wlock = 0;
int __debug_wbuffer_written = 0;
void __SafeGetPLCGlob_debug(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__debug_rlock, 0, 1));
    *pvalue = __debug_rbuffer;
    AtomicCompareExchange((long*)&__debug_rlock, 1, 0);
}
void __SafeSetPLCGlob_debug(IEC_INT *value){
    while(AtomicCompareExchange(&__debug_wlock, 0, 1));
    __debug_wbuffer = *value;
    __debug_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__debug_wlock, 1, 0);
}


extern  __IEC_STRING_t CONFIG__PATH;
IEC_STRING __PATH_rbuffer = __INIT_STRING;
IEC_STRING __PATH_wbuffer;
long __PATH_rlock = 0;
long __PATH_wlock = 0;
int __PATH_wbuffer_written = 0;
void __SafeGetPLCGlob_PATH(IEC_STRING *pvalue){
    while(AtomicCompareExchange(&__PATH_rlock, 0, 1));
    *pvalue = __PATH_rbuffer;
    AtomicCompareExchange((long*)&__PATH_rlock, 1, 0);
}
void __SafeSetPLCGlob_PATH(IEC_STRING *value){
    while(AtomicCompareExchange(&__PATH_wlock, 0, 1));
    __PATH_wbuffer = *value;
    __PATH_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__PATH_wlock, 1, 0);
}


extern  __IEC_STRING_t CONFIG__GRUMPF;
IEC_STRING __Grumpf_rbuffer = __INIT_STRING;
IEC_STRING __Grumpf_wbuffer;
long __Grumpf_rlock = 0;
long __Grumpf_wlock = 0;
int __Grumpf_wbuffer_written = 0;
void __SafeGetPLCGlob_Grumpf(IEC_STRING *pvalue){
    while(AtomicCompareExchange(&__Grumpf_rlock, 0, 1));
    *pvalue = __Grumpf_rbuffer;
    AtomicCompareExchange((long*)&__Grumpf_rlock, 1, 0);
}
void __SafeSetPLCGlob_Grumpf(IEC_STRING *value){
    while(AtomicCompareExchange(&__Grumpf_wlock, 0, 1));
    __Grumpf_wbuffer = *value;
    __Grumpf_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__Grumpf_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__I_STATUS;
IEC_INT __i_status_rbuffer = __INIT_INT;
IEC_INT __i_status_wbuffer;
long __i_status_rlock = 0;
long __i_status_wlock = 0;
int __i_status_wbuffer_written = 0;
void __SafeGetPLCGlob_i_status(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__i_status_rlock, 0, 1));
    *pvalue = __i_status_rbuffer;
    AtomicCompareExchange((long*)&__i_status_rlock, 1, 0);
}
void __SafeSetPLCGlob_i_status(IEC_INT *value){
    while(AtomicCompareExchange(&__i_status_wlock, 0, 1));
    __i_status_wbuffer = *value;
    __i_status_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__i_status_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__I_STATUS_CSV;
IEC_INT __i_status_CSV_rbuffer = __INIT_INT;
IEC_INT __i_status_CSV_wbuffer;
long __i_status_CSV_rlock = 0;
long __i_status_CSV_wlock = 0;
int __i_status_CSV_wbuffer_written = 0;
void __SafeGetPLCGlob_i_status_CSV(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__i_status_CSV_rlock, 0, 1));
    *pvalue = __i_status_CSV_rbuffer;
    AtomicCompareExchange((long*)&__i_status_CSV_rlock, 1, 0);
}
void __SafeSetPLCGlob_i_status_CSV(IEC_INT *value){
    while(AtomicCompareExchange(&__i_status_CSV_wlock, 0, 1));
    __i_status_CSV_wbuffer = *value;
    __i_status_CSV_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__i_status_CSV_wlock, 1, 0);
}


extern  __IEC_STRING_t CONFIG__NAMEFILE;
IEC_STRING __NameFile_rbuffer = __INIT_STRING;
IEC_STRING __NameFile_wbuffer;
long __NameFile_rlock = 0;
long __NameFile_wlock = 0;
int __NameFile_wbuffer_written = 0;
void __SafeGetPLCGlob_NameFile(IEC_STRING *pvalue){
    while(AtomicCompareExchange(&__NameFile_rlock, 0, 1));
    *pvalue = __NameFile_rbuffer;
    AtomicCompareExchange((long*)&__NameFile_rlock, 1, 0);
}
void __SafeSetPLCGlob_NameFile(IEC_STRING *value){
    while(AtomicCompareExchange(&__NameFile_wlock, 0, 1));
    __NameFile_wbuffer = *value;
    __NameFile_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__NameFile_wlock, 1, 0);
}


extern  __IEC_STRING_t CONFIG__NAMEFILECSV;
IEC_STRING __NameFileCSV_rbuffer = __INIT_STRING;
IEC_STRING __NameFileCSV_wbuffer;
long __NameFileCSV_rlock = 0;
long __NameFileCSV_wlock = 0;
int __NameFileCSV_wbuffer_written = 0;
void __SafeGetPLCGlob_NameFileCSV(IEC_STRING *pvalue){
    while(AtomicCompareExchange(&__NameFileCSV_rlock, 0, 1));
    *pvalue = __NameFileCSV_rbuffer;
    AtomicCompareExchange((long*)&__NameFileCSV_rlock, 1, 0);
}
void __SafeSetPLCGlob_NameFileCSV(IEC_STRING *value){
    while(AtomicCompareExchange(&__NameFileCSV_wlock, 0, 1));
    __NameFileCSV_wbuffer = *value;
    __NameFileCSV_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__NameFileCSV_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__WRITE_OK;
IEC_INT __WRITE_OK_rbuffer = __INIT_INT;
IEC_INT __WRITE_OK_wbuffer;
long __WRITE_OK_rlock = 0;
long __WRITE_OK_wlock = 0;
int __WRITE_OK_wbuffer_written = 0;
void __SafeGetPLCGlob_WRITE_OK(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__WRITE_OK_rlock, 0, 1));
    *pvalue = __WRITE_OK_rbuffer;
    AtomicCompareExchange((long*)&__WRITE_OK_rlock, 1, 0);
}
void __SafeSetPLCGlob_WRITE_OK(IEC_INT *value){
    while(AtomicCompareExchange(&__WRITE_OK_wlock, 0, 1));
    __WRITE_OK_wbuffer = *value;
    __WRITE_OK_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__WRITE_OK_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__WRITE_FAIL;
IEC_INT __WRITE_FAIL_rbuffer = __INIT_INT;
IEC_INT __WRITE_FAIL_wbuffer;
long __WRITE_FAIL_rlock = 0;
long __WRITE_FAIL_wlock = 0;
int __WRITE_FAIL_wbuffer_written = 0;
void __SafeGetPLCGlob_WRITE_FAIL(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__WRITE_FAIL_rlock, 0, 1));
    *pvalue = __WRITE_FAIL_rbuffer;
    AtomicCompareExchange((long*)&__WRITE_FAIL_rlock, 1, 0);
}
void __SafeSetPLCGlob_WRITE_FAIL(IEC_INT *value){
    while(AtomicCompareExchange(&__WRITE_FAIL_wlock, 0, 1));
    __WRITE_FAIL_wbuffer = *value;
    __WRITE_FAIL_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__WRITE_FAIL_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__READ_OK;
IEC_INT __READ_OK_rbuffer = __INIT_INT;
IEC_INT __READ_OK_wbuffer;
long __READ_OK_rlock = 0;
long __READ_OK_wlock = 0;
int __READ_OK_wbuffer_written = 0;
void __SafeGetPLCGlob_READ_OK(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__READ_OK_rlock, 0, 1));
    *pvalue = __READ_OK_rbuffer;
    AtomicCompareExchange((long*)&__READ_OK_rlock, 1, 0);
}
void __SafeSetPLCGlob_READ_OK(IEC_INT *value){
    while(AtomicCompareExchange(&__READ_OK_wlock, 0, 1));
    __READ_OK_wbuffer = *value;
    __READ_OK_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__READ_OK_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__READ_FAIL;
IEC_INT __READ_FAIL_rbuffer = __INIT_INT;
IEC_INT __READ_FAIL_wbuffer;
long __READ_FAIL_rlock = 0;
long __READ_FAIL_wlock = 0;
int __READ_FAIL_wbuffer_written = 0;
void __SafeGetPLCGlob_READ_FAIL(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__READ_FAIL_rlock, 0, 1));
    *pvalue = __READ_FAIL_rbuffer;
    AtomicCompareExchange((long*)&__READ_FAIL_rlock, 1, 0);
}
void __SafeSetPLCGlob_READ_FAIL(IEC_INT *value){
    while(AtomicCompareExchange(&__READ_FAIL_wlock, 0, 1));
    __READ_FAIL_wbuffer = *value;
    __READ_FAIL_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__READ_FAIL_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__NEXT_OK;
IEC_INT __NEXT_OK_rbuffer = __INIT_INT;
IEC_INT __NEXT_OK_wbuffer;
long __NEXT_OK_rlock = 0;
long __NEXT_OK_wlock = 0;
int __NEXT_OK_wbuffer_written = 0;
void __SafeGetPLCGlob_NEXT_OK(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__NEXT_OK_rlock, 0, 1));
    *pvalue = __NEXT_OK_rbuffer;
    AtomicCompareExchange((long*)&__NEXT_OK_rlock, 1, 0);
}
void __SafeSetPLCGlob_NEXT_OK(IEC_INT *value){
    while(AtomicCompareExchange(&__NEXT_OK_wlock, 0, 1));
    __NEXT_OK_wbuffer = *value;
    __NEXT_OK_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__NEXT_OK_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__NEXT_FAIL;
IEC_INT __NEXT_FAIL_rbuffer = __INIT_INT;
IEC_INT __NEXT_FAIL_wbuffer;
long __NEXT_FAIL_rlock = 0;
long __NEXT_FAIL_wlock = 0;
int __NEXT_FAIL_wbuffer_written = 0;
void __SafeGetPLCGlob_NEXT_FAIL(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__NEXT_FAIL_rlock, 0, 1));
    *pvalue = __NEXT_FAIL_rbuffer;
    AtomicCompareExchange((long*)&__NEXT_FAIL_rlock, 1, 0);
}
void __SafeSetPLCGlob_NEXT_FAIL(IEC_INT *value){
    while(AtomicCompareExchange(&__NEXT_FAIL_wlock, 0, 1));
    __NEXT_FAIL_wbuffer = *value;
    __NEXT_FAIL_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__NEXT_FAIL_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__OPEN_DICT_OK;
IEC_INT __OPEN_DICT_OK_rbuffer = __INIT_INT;
IEC_INT __OPEN_DICT_OK_wbuffer;
long __OPEN_DICT_OK_rlock = 0;
long __OPEN_DICT_OK_wlock = 0;
int __OPEN_DICT_OK_wbuffer_written = 0;
void __SafeGetPLCGlob_OPEN_DICT_OK(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__OPEN_DICT_OK_rlock, 0, 1));
    *pvalue = __OPEN_DICT_OK_rbuffer;
    AtomicCompareExchange((long*)&__OPEN_DICT_OK_rlock, 1, 0);
}
void __SafeSetPLCGlob_OPEN_DICT_OK(IEC_INT *value){
    while(AtomicCompareExchange(&__OPEN_DICT_OK_wlock, 0, 1));
    __OPEN_DICT_OK_wbuffer = *value;
    __OPEN_DICT_OK_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__OPEN_DICT_OK_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__OPEN_DICT_FAIL;
IEC_INT __OPEN_DICT_FAIL_rbuffer = __INIT_INT;
IEC_INT __OPEN_DICT_FAIL_wbuffer;
long __OPEN_DICT_FAIL_rlock = 0;
long __OPEN_DICT_FAIL_wlock = 0;
int __OPEN_DICT_FAIL_wbuffer_written = 0;
void __SafeGetPLCGlob_OPEN_DICT_FAIL(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__OPEN_DICT_FAIL_rlock, 0, 1));
    *pvalue = __OPEN_DICT_FAIL_rbuffer;
    AtomicCompareExchange((long*)&__OPEN_DICT_FAIL_rlock, 1, 0);
}
void __SafeSetPLCGlob_OPEN_DICT_FAIL(IEC_INT *value){
    while(AtomicCompareExchange(&__OPEN_DICT_FAIL_wlock, 0, 1));
    __OPEN_DICT_FAIL_wbuffer = *value;
    __OPEN_DICT_FAIL_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__OPEN_DICT_FAIL_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__OPEN_CSV_OK;
IEC_INT __OPEN_CSV_OK_rbuffer = __INIT_INT;
IEC_INT __OPEN_CSV_OK_wbuffer;
long __OPEN_CSV_OK_rlock = 0;
long __OPEN_CSV_OK_wlock = 0;
int __OPEN_CSV_OK_wbuffer_written = 0;
void __SafeGetPLCGlob_OPEN_CSV_OK(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__OPEN_CSV_OK_rlock, 0, 1));
    *pvalue = __OPEN_CSV_OK_rbuffer;
    AtomicCompareExchange((long*)&__OPEN_CSV_OK_rlock, 1, 0);
}
void __SafeSetPLCGlob_OPEN_CSV_OK(IEC_INT *value){
    while(AtomicCompareExchange(&__OPEN_CSV_OK_wlock, 0, 1));
    __OPEN_CSV_OK_wbuffer = *value;
    __OPEN_CSV_OK_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__OPEN_CSV_OK_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__OPEN_CSV_FAIL;
IEC_INT __OPEN_CSV_FAIL_rbuffer = __INIT_INT;
IEC_INT __OPEN_CSV_FAIL_wbuffer;
long __OPEN_CSV_FAIL_rlock = 0;
long __OPEN_CSV_FAIL_wlock = 0;
int __OPEN_CSV_FAIL_wbuffer_written = 0;
void __SafeGetPLCGlob_OPEN_CSV_FAIL(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__OPEN_CSV_FAIL_rlock, 0, 1));
    *pvalue = __OPEN_CSV_FAIL_rbuffer;
    AtomicCompareExchange((long*)&__OPEN_CSV_FAIL_rlock, 1, 0);
}
void __SafeSetPLCGlob_OPEN_CSV_FAIL(IEC_INT *value){
    while(AtomicCompareExchange(&__OPEN_CSV_FAIL_wlock, 0, 1));
    __OPEN_CSV_FAIL_wbuffer = *value;
    __OPEN_CSV_FAIL_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__OPEN_CSV_FAIL_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__UPDATE_OK;
IEC_INT __UPDATE_OK_rbuffer = __INIT_INT;
IEC_INT __UPDATE_OK_wbuffer;
long __UPDATE_OK_rlock = 0;
long __UPDATE_OK_wlock = 0;
int __UPDATE_OK_wbuffer_written = 0;
void __SafeGetPLCGlob_UPDATE_OK(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__UPDATE_OK_rlock, 0, 1));
    *pvalue = __UPDATE_OK_rbuffer;
    AtomicCompareExchange((long*)&__UPDATE_OK_rlock, 1, 0);
}
void __SafeSetPLCGlob_UPDATE_OK(IEC_INT *value){
    while(AtomicCompareExchange(&__UPDATE_OK_wlock, 0, 1));
    __UPDATE_OK_wbuffer = *value;
    __UPDATE_OK_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__UPDATE_OK_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__FILE_EOF;
IEC_INT __FILE_EOF_rbuffer = __INIT_INT;
IEC_INT __FILE_EOF_wbuffer;
long __FILE_EOF_rlock = 0;
long __FILE_EOF_wlock = 0;
int __FILE_EOF_wbuffer_written = 0;
void __SafeGetPLCGlob_FILE_EOF(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__FILE_EOF_rlock, 0, 1));
    *pvalue = __FILE_EOF_rbuffer;
    AtomicCompareExchange((long*)&__FILE_EOF_rlock, 1, 0);
}
void __SafeSetPLCGlob_FILE_EOF(IEC_INT *value){
    while(AtomicCompareExchange(&__FILE_EOF_wlock, 0, 1));
    __FILE_EOF_wbuffer = *value;
    __FILE_EOF_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__FILE_EOF_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__UPDATE_FAIL;
IEC_INT __UPDATE_FAIL_rbuffer = __INIT_INT;
IEC_INT __UPDATE_FAIL_wbuffer;
long __UPDATE_FAIL_rlock = 0;
long __UPDATE_FAIL_wlock = 0;
int __UPDATE_FAIL_wbuffer_written = 0;
void __SafeGetPLCGlob_UPDATE_FAIL(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__UPDATE_FAIL_rlock, 0, 1));
    *pvalue = __UPDATE_FAIL_rbuffer;
    AtomicCompareExchange((long*)&__UPDATE_FAIL_rlock, 1, 0);
}
void __SafeSetPLCGlob_UPDATE_FAIL(IEC_INT *value){
    while(AtomicCompareExchange(&__UPDATE_FAIL_wlock, 0, 1));
    __UPDATE_FAIL_wbuffer = *value;
    __UPDATE_FAIL_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__UPDATE_FAIL_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__SET_VAL_OK;
IEC_INT __SET_VAL_OK_rbuffer = __INIT_INT;
IEC_INT __SET_VAL_OK_wbuffer;
long __SET_VAL_OK_rlock = 0;
long __SET_VAL_OK_wlock = 0;
int __SET_VAL_OK_wbuffer_written = 0;
void __SafeGetPLCGlob_SET_VAL_OK(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__SET_VAL_OK_rlock, 0, 1));
    *pvalue = __SET_VAL_OK_rbuffer;
    AtomicCompareExchange((long*)&__SET_VAL_OK_rlock, 1, 0);
}
void __SafeSetPLCGlob_SET_VAL_OK(IEC_INT *value){
    while(AtomicCompareExchange(&__SET_VAL_OK_wlock, 0, 1));
    __SET_VAL_OK_wbuffer = *value;
    __SET_VAL_OK_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__SET_VAL_OK_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__SET_VAL_FAIL;
IEC_INT __SET_VAL_FAIL_rbuffer = __INIT_INT;
IEC_INT __SET_VAL_FAIL_wbuffer;
long __SET_VAL_FAIL_rlock = 0;
long __SET_VAL_FAIL_wlock = 0;
int __SET_VAL_FAIL_wbuffer_written = 0;
void __SafeGetPLCGlob_SET_VAL_FAIL(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__SET_VAL_FAIL_rlock, 0, 1));
    *pvalue = __SET_VAL_FAIL_rbuffer;
    AtomicCompareExchange((long*)&__SET_VAL_FAIL_rlock, 1, 0);
}
void __SafeSetPLCGlob_SET_VAL_FAIL(IEC_INT *value){
    while(AtomicCompareExchange(&__SET_VAL_FAIL_wlock, 0, 1));
    __SET_VAL_FAIL_wbuffer = *value;
    __SET_VAL_FAIL_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__SET_VAL_FAIL_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__FILE_NOT_FOUND;
IEC_INT __FILE_NOT_FOUND_rbuffer = __INIT_INT;
IEC_INT __FILE_NOT_FOUND_wbuffer;
long __FILE_NOT_FOUND_rlock = 0;
long __FILE_NOT_FOUND_wlock = 0;
int __FILE_NOT_FOUND_wbuffer_written = 0;
void __SafeGetPLCGlob_FILE_NOT_FOUND(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__FILE_NOT_FOUND_rlock, 0, 1));
    *pvalue = __FILE_NOT_FOUND_rbuffer;
    AtomicCompareExchange((long*)&__FILE_NOT_FOUND_rlock, 1, 0);
}
void __SafeSetPLCGlob_FILE_NOT_FOUND(IEC_INT *value){
    while(AtomicCompareExchange(&__FILE_NOT_FOUND_wlock, 0, 1));
    __FILE_NOT_FOUND_wbuffer = *value;
    __FILE_NOT_FOUND_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__FILE_NOT_FOUND_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__CLOSE_CSV_OK;
IEC_INT __CLOSE_CSV_OK_rbuffer = __INIT_INT;
IEC_INT __CLOSE_CSV_OK_wbuffer;
long __CLOSE_CSV_OK_rlock = 0;
long __CLOSE_CSV_OK_wlock = 0;
int __CLOSE_CSV_OK_wbuffer_written = 0;
void __SafeGetPLCGlob_CLOSE_CSV_OK(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__CLOSE_CSV_OK_rlock, 0, 1));
    *pvalue = __CLOSE_CSV_OK_rbuffer;
    AtomicCompareExchange((long*)&__CLOSE_CSV_OK_rlock, 1, 0);
}
void __SafeSetPLCGlob_CLOSE_CSV_OK(IEC_INT *value){
    while(AtomicCompareExchange(&__CLOSE_CSV_OK_wlock, 0, 1));
    __CLOSE_CSV_OK_wbuffer = *value;
    __CLOSE_CSV_OK_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__CLOSE_CSV_OK_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__CLOSE_CSV_FAIL;
IEC_INT __CLOSE_CSV_FAIL_rbuffer = __INIT_INT;
IEC_INT __CLOSE_CSV_FAIL_wbuffer;
long __CLOSE_CSV_FAIL_rlock = 0;
long __CLOSE_CSV_FAIL_wlock = 0;
int __CLOSE_CSV_FAIL_wbuffer_written = 0;
void __SafeGetPLCGlob_CLOSE_CSV_FAIL(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__CLOSE_CSV_FAIL_rlock, 0, 1));
    *pvalue = __CLOSE_CSV_FAIL_rbuffer;
    AtomicCompareExchange((long*)&__CLOSE_CSV_FAIL_rlock, 1, 0);
}
void __SafeSetPLCGlob_CLOSE_CSV_FAIL(IEC_INT *value){
    while(AtomicCompareExchange(&__CLOSE_CSV_FAIL_wlock, 0, 1));
    __CLOSE_CSV_FAIL_wbuffer = *value;
    __CLOSE_CSV_FAIL_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__CLOSE_CSV_FAIL_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__SAVE_CSV_OK;
IEC_INT __SAVE_CSV_OK_rbuffer = __INIT_INT;
IEC_INT __SAVE_CSV_OK_wbuffer;
long __SAVE_CSV_OK_rlock = 0;
long __SAVE_CSV_OK_wlock = 0;
int __SAVE_CSV_OK_wbuffer_written = 0;
void __SafeGetPLCGlob_SAVE_CSV_OK(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__SAVE_CSV_OK_rlock, 0, 1));
    *pvalue = __SAVE_CSV_OK_rbuffer;
    AtomicCompareExchange((long*)&__SAVE_CSV_OK_rlock, 1, 0);
}
void __SafeSetPLCGlob_SAVE_CSV_OK(IEC_INT *value){
    while(AtomicCompareExchange(&__SAVE_CSV_OK_wlock, 0, 1));
    __SAVE_CSV_OK_wbuffer = *value;
    __SAVE_CSV_OK_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__SAVE_CSV_OK_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__SAVE_CSV_FAIL;
IEC_INT __SAVE_CSV_FAIL_rbuffer = __INIT_INT;
IEC_INT __SAVE_CSV_FAIL_wbuffer;
long __SAVE_CSV_FAIL_rlock = 0;
long __SAVE_CSV_FAIL_wlock = 0;
int __SAVE_CSV_FAIL_wbuffer_written = 0;
void __SafeGetPLCGlob_SAVE_CSV_FAIL(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__SAVE_CSV_FAIL_rlock, 0, 1));
    *pvalue = __SAVE_CSV_FAIL_rbuffer;
    AtomicCompareExchange((long*)&__SAVE_CSV_FAIL_rlock, 1, 0);
}
void __SafeSetPLCGlob_SAVE_CSV_FAIL(IEC_INT *value){
    while(AtomicCompareExchange(&__SAVE_CSV_FAIL_wlock, 0, 1));
    __SAVE_CSV_FAIL_wbuffer = *value;
    __SAVE_CSV_FAIL_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__SAVE_CSV_FAIL_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__SIGNAL_NOT_CONNECT;
IEC_INT __SIGNAL_NOT_CONNECT_rbuffer = __INIT_INT;
IEC_INT __SIGNAL_NOT_CONNECT_wbuffer;
long __SIGNAL_NOT_CONNECT_rlock = 0;
long __SIGNAL_NOT_CONNECT_wlock = 0;
int __SIGNAL_NOT_CONNECT_wbuffer_written = 0;
void __SafeGetPLCGlob_SIGNAL_NOT_CONNECT(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__SIGNAL_NOT_CONNECT_rlock, 0, 1));
    *pvalue = __SIGNAL_NOT_CONNECT_rbuffer;
    AtomicCompareExchange((long*)&__SIGNAL_NOT_CONNECT_rlock, 1, 0);
}
void __SafeSetPLCGlob_SIGNAL_NOT_CONNECT(IEC_INT *value){
    while(AtomicCompareExchange(&__SIGNAL_NOT_CONNECT_wlock, 0, 1));
    __SIGNAL_NOT_CONNECT_wbuffer = *value;
    __SIGNAL_NOT_CONNECT_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__SIGNAL_NOT_CONNECT_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__INFO;
IEC_INT __INFO_rbuffer = __INIT_INT;
IEC_INT __INFO_wbuffer;
long __INFO_rlock = 0;
long __INFO_wlock = 0;
int __INFO_wbuffer_written = 0;
void __SafeGetPLCGlob_INFO(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__INFO_rlock, 0, 1));
    *pvalue = __INFO_rbuffer;
    AtomicCompareExchange((long*)&__INFO_rlock, 1, 0);
}
void __SafeSetPLCGlob_INFO(IEC_INT *value){
    while(AtomicCompareExchange(&__INFO_wlock, 0, 1));
    __INFO_wbuffer = *value;
    __INFO_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__INFO_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__WARNING;
IEC_INT __WARNING_rbuffer = __INIT_INT;
IEC_INT __WARNING_wbuffer;
long __WARNING_rlock = 0;
long __WARNING_wlock = 0;
int __WARNING_wbuffer_written = 0;
void __SafeGetPLCGlob_WARNING(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__WARNING_rlock, 0, 1));
    *pvalue = __WARNING_rbuffer;
    AtomicCompareExchange((long*)&__WARNING_rlock, 1, 0);
}
void __SafeSetPLCGlob_WARNING(IEC_INT *value){
    while(AtomicCompareExchange(&__WARNING_wlock, 0, 1));
    __WARNING_wbuffer = *value;
    __WARNING_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__WARNING_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__ERROR;
IEC_INT __ERROR_rbuffer = __INIT_INT;
IEC_INT __ERROR_wbuffer;
long __ERROR_rlock = 0;
long __ERROR_wlock = 0;
int __ERROR_wbuffer_written = 0;
void __SafeGetPLCGlob_ERROR(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__ERROR_rlock, 0, 1));
    *pvalue = __ERROR_rbuffer;
    AtomicCompareExchange((long*)&__ERROR_rlock, 1, 0);
}
void __SafeSetPLCGlob_ERROR(IEC_INT *value){
    while(AtomicCompareExchange(&__ERROR_wlock, 0, 1));
    __ERROR_wbuffer = *value;
    __ERROR_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__ERROR_wlock, 1, 0);
}



/* Beremiz confnode functions */
int __init_1(int argc,char **argv){

    return 0;
}

void __cleanup_1(void){
}

void __retrieve_1(void){
    if(!AtomicCompareExchange(&__debug_wlock, 0, 1)){
        if(__debug_wbuffer_written == 1){
            CONFIG__DEBUG.value = __debug_wbuffer;
            __debug_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__debug_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__PATH_wlock, 0, 1)){
        if(__PATH_wbuffer_written == 1){
            CONFIG__PATH.value = __PATH_wbuffer;
            __PATH_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__PATH_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__Grumpf_wlock, 0, 1)){
        if(__Grumpf_wbuffer_written == 1){
            CONFIG__GRUMPF.value = __Grumpf_wbuffer;
            __Grumpf_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__Grumpf_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__i_status_wlock, 0, 1)){
        if(__i_status_wbuffer_written == 1){
            CONFIG__I_STATUS.value = __i_status_wbuffer;
            __i_status_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__i_status_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__i_status_CSV_wlock, 0, 1)){
        if(__i_status_CSV_wbuffer_written == 1){
            CONFIG__I_STATUS_CSV.value = __i_status_CSV_wbuffer;
            __i_status_CSV_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__i_status_CSV_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__NameFile_wlock, 0, 1)){
        if(__NameFile_wbuffer_written == 1){
            CONFIG__NAMEFILE.value = __NameFile_wbuffer;
            __NameFile_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__NameFile_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__NameFileCSV_wlock, 0, 1)){
        if(__NameFileCSV_wbuffer_written == 1){
            CONFIG__NAMEFILECSV.value = __NameFileCSV_wbuffer;
            __NameFileCSV_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__NameFileCSV_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__WRITE_OK_wlock, 0, 1)){
        if(__WRITE_OK_wbuffer_written == 1){
            CONFIG__WRITE_OK.value = __WRITE_OK_wbuffer;
            __WRITE_OK_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__WRITE_OK_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__WRITE_FAIL_wlock, 0, 1)){
        if(__WRITE_FAIL_wbuffer_written == 1){
            CONFIG__WRITE_FAIL.value = __WRITE_FAIL_wbuffer;
            __WRITE_FAIL_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__WRITE_FAIL_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__READ_OK_wlock, 0, 1)){
        if(__READ_OK_wbuffer_written == 1){
            CONFIG__READ_OK.value = __READ_OK_wbuffer;
            __READ_OK_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__READ_OK_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__READ_FAIL_wlock, 0, 1)){
        if(__READ_FAIL_wbuffer_written == 1){
            CONFIG__READ_FAIL.value = __READ_FAIL_wbuffer;
            __READ_FAIL_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__READ_FAIL_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__NEXT_OK_wlock, 0, 1)){
        if(__NEXT_OK_wbuffer_written == 1){
            CONFIG__NEXT_OK.value = __NEXT_OK_wbuffer;
            __NEXT_OK_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__NEXT_OK_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__NEXT_FAIL_wlock, 0, 1)){
        if(__NEXT_FAIL_wbuffer_written == 1){
            CONFIG__NEXT_FAIL.value = __NEXT_FAIL_wbuffer;
            __NEXT_FAIL_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__NEXT_FAIL_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__OPEN_DICT_OK_wlock, 0, 1)){
        if(__OPEN_DICT_OK_wbuffer_written == 1){
            CONFIG__OPEN_DICT_OK.value = __OPEN_DICT_OK_wbuffer;
            __OPEN_DICT_OK_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__OPEN_DICT_OK_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__OPEN_DICT_FAIL_wlock, 0, 1)){
        if(__OPEN_DICT_FAIL_wbuffer_written == 1){
            CONFIG__OPEN_DICT_FAIL.value = __OPEN_DICT_FAIL_wbuffer;
            __OPEN_DICT_FAIL_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__OPEN_DICT_FAIL_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__OPEN_CSV_OK_wlock, 0, 1)){
        if(__OPEN_CSV_OK_wbuffer_written == 1){
            CONFIG__OPEN_CSV_OK.value = __OPEN_CSV_OK_wbuffer;
            __OPEN_CSV_OK_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__OPEN_CSV_OK_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__OPEN_CSV_FAIL_wlock, 0, 1)){
        if(__OPEN_CSV_FAIL_wbuffer_written == 1){
            CONFIG__OPEN_CSV_FAIL.value = __OPEN_CSV_FAIL_wbuffer;
            __OPEN_CSV_FAIL_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__OPEN_CSV_FAIL_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__UPDATE_OK_wlock, 0, 1)){
        if(__UPDATE_OK_wbuffer_written == 1){
            CONFIG__UPDATE_OK.value = __UPDATE_OK_wbuffer;
            __UPDATE_OK_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__UPDATE_OK_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__FILE_EOF_wlock, 0, 1)){
        if(__FILE_EOF_wbuffer_written == 1){
            CONFIG__FILE_EOF.value = __FILE_EOF_wbuffer;
            __FILE_EOF_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__FILE_EOF_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__UPDATE_FAIL_wlock, 0, 1)){
        if(__UPDATE_FAIL_wbuffer_written == 1){
            CONFIG__UPDATE_FAIL.value = __UPDATE_FAIL_wbuffer;
            __UPDATE_FAIL_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__UPDATE_FAIL_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__SET_VAL_OK_wlock, 0, 1)){
        if(__SET_VAL_OK_wbuffer_written == 1){
            CONFIG__SET_VAL_OK.value = __SET_VAL_OK_wbuffer;
            __SET_VAL_OK_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__SET_VAL_OK_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__SET_VAL_FAIL_wlock, 0, 1)){
        if(__SET_VAL_FAIL_wbuffer_written == 1){
            CONFIG__SET_VAL_FAIL.value = __SET_VAL_FAIL_wbuffer;
            __SET_VAL_FAIL_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__SET_VAL_FAIL_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__FILE_NOT_FOUND_wlock, 0, 1)){
        if(__FILE_NOT_FOUND_wbuffer_written == 1){
            CONFIG__FILE_NOT_FOUND.value = __FILE_NOT_FOUND_wbuffer;
            __FILE_NOT_FOUND_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__FILE_NOT_FOUND_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__CLOSE_CSV_OK_wlock, 0, 1)){
        if(__CLOSE_CSV_OK_wbuffer_written == 1){
            CONFIG__CLOSE_CSV_OK.value = __CLOSE_CSV_OK_wbuffer;
            __CLOSE_CSV_OK_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__CLOSE_CSV_OK_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__CLOSE_CSV_FAIL_wlock, 0, 1)){
        if(__CLOSE_CSV_FAIL_wbuffer_written == 1){
            CONFIG__CLOSE_CSV_FAIL.value = __CLOSE_CSV_FAIL_wbuffer;
            __CLOSE_CSV_FAIL_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__CLOSE_CSV_FAIL_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__SAVE_CSV_OK_wlock, 0, 1)){
        if(__SAVE_CSV_OK_wbuffer_written == 1){
            CONFIG__SAVE_CSV_OK.value = __SAVE_CSV_OK_wbuffer;
            __SAVE_CSV_OK_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__SAVE_CSV_OK_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__SAVE_CSV_FAIL_wlock, 0, 1)){
        if(__SAVE_CSV_FAIL_wbuffer_written == 1){
            CONFIG__SAVE_CSV_FAIL.value = __SAVE_CSV_FAIL_wbuffer;
            __SAVE_CSV_FAIL_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__SAVE_CSV_FAIL_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__SIGNAL_NOT_CONNECT_wlock, 0, 1)){
        if(__SIGNAL_NOT_CONNECT_wbuffer_written == 1){
            CONFIG__SIGNAL_NOT_CONNECT.value = __SIGNAL_NOT_CONNECT_wbuffer;
            __SIGNAL_NOT_CONNECT_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__SIGNAL_NOT_CONNECT_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__INFO_wlock, 0, 1)){
        if(__INFO_wbuffer_written == 1){
            CONFIG__INFO.value = __INFO_wbuffer;
            __INFO_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__INFO_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__WARNING_wlock, 0, 1)){
        if(__WARNING_wbuffer_written == 1){
            CONFIG__WARNING.value = __WARNING_wbuffer;
            __WARNING_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__WARNING_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__ERROR_wlock, 0, 1)){
        if(__ERROR_wbuffer_written == 1){
            CONFIG__ERROR.value = __ERROR_wbuffer;
            __ERROR_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__ERROR_wlock, 1, 0);
    }

}

void __publish_1(void){
    if(!AtomicCompareExchange(&__debug_rlock, 0, 1)){
        __debug_rbuffer = __GET_VAR(CONFIG__DEBUG);
        AtomicCompareExchange((long*)&__debug_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__PATH_rlock, 0, 1)){
        __PATH_rbuffer = __GET_VAR(CONFIG__PATH);
        AtomicCompareExchange((long*)&__PATH_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__Grumpf_rlock, 0, 1)){
        __Grumpf_rbuffer = __GET_VAR(CONFIG__GRUMPF);
        AtomicCompareExchange((long*)&__Grumpf_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__i_status_rlock, 0, 1)){
        __i_status_rbuffer = __GET_VAR(CONFIG__I_STATUS);
        AtomicCompareExchange((long*)&__i_status_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__i_status_CSV_rlock, 0, 1)){
        __i_status_CSV_rbuffer = __GET_VAR(CONFIG__I_STATUS_CSV);
        AtomicCompareExchange((long*)&__i_status_CSV_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__NameFile_rlock, 0, 1)){
        __NameFile_rbuffer = __GET_VAR(CONFIG__NAMEFILE);
        AtomicCompareExchange((long*)&__NameFile_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__NameFileCSV_rlock, 0, 1)){
        __NameFileCSV_rbuffer = __GET_VAR(CONFIG__NAMEFILECSV);
        AtomicCompareExchange((long*)&__NameFileCSV_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__WRITE_OK_rlock, 0, 1)){
        __WRITE_OK_rbuffer = __GET_VAR(CONFIG__WRITE_OK);
        AtomicCompareExchange((long*)&__WRITE_OK_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__WRITE_FAIL_rlock, 0, 1)){
        __WRITE_FAIL_rbuffer = __GET_VAR(CONFIG__WRITE_FAIL);
        AtomicCompareExchange((long*)&__WRITE_FAIL_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__READ_OK_rlock, 0, 1)){
        __READ_OK_rbuffer = __GET_VAR(CONFIG__READ_OK);
        AtomicCompareExchange((long*)&__READ_OK_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__READ_FAIL_rlock, 0, 1)){
        __READ_FAIL_rbuffer = __GET_VAR(CONFIG__READ_FAIL);
        AtomicCompareExchange((long*)&__READ_FAIL_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__NEXT_OK_rlock, 0, 1)){
        __NEXT_OK_rbuffer = __GET_VAR(CONFIG__NEXT_OK);
        AtomicCompareExchange((long*)&__NEXT_OK_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__NEXT_FAIL_rlock, 0, 1)){
        __NEXT_FAIL_rbuffer = __GET_VAR(CONFIG__NEXT_FAIL);
        AtomicCompareExchange((long*)&__NEXT_FAIL_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__OPEN_DICT_OK_rlock, 0, 1)){
        __OPEN_DICT_OK_rbuffer = __GET_VAR(CONFIG__OPEN_DICT_OK);
        AtomicCompareExchange((long*)&__OPEN_DICT_OK_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__OPEN_DICT_FAIL_rlock, 0, 1)){
        __OPEN_DICT_FAIL_rbuffer = __GET_VAR(CONFIG__OPEN_DICT_FAIL);
        AtomicCompareExchange((long*)&__OPEN_DICT_FAIL_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__OPEN_CSV_OK_rlock, 0, 1)){
        __OPEN_CSV_OK_rbuffer = __GET_VAR(CONFIG__OPEN_CSV_OK);
        AtomicCompareExchange((long*)&__OPEN_CSV_OK_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__OPEN_CSV_FAIL_rlock, 0, 1)){
        __OPEN_CSV_FAIL_rbuffer = __GET_VAR(CONFIG__OPEN_CSV_FAIL);
        AtomicCompareExchange((long*)&__OPEN_CSV_FAIL_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__UPDATE_OK_rlock, 0, 1)){
        __UPDATE_OK_rbuffer = __GET_VAR(CONFIG__UPDATE_OK);
        AtomicCompareExchange((long*)&__UPDATE_OK_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__FILE_EOF_rlock, 0, 1)){
        __FILE_EOF_rbuffer = __GET_VAR(CONFIG__FILE_EOF);
        AtomicCompareExchange((long*)&__FILE_EOF_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__UPDATE_FAIL_rlock, 0, 1)){
        __UPDATE_FAIL_rbuffer = __GET_VAR(CONFIG__UPDATE_FAIL);
        AtomicCompareExchange((long*)&__UPDATE_FAIL_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__SET_VAL_OK_rlock, 0, 1)){
        __SET_VAL_OK_rbuffer = __GET_VAR(CONFIG__SET_VAL_OK);
        AtomicCompareExchange((long*)&__SET_VAL_OK_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__SET_VAL_FAIL_rlock, 0, 1)){
        __SET_VAL_FAIL_rbuffer = __GET_VAR(CONFIG__SET_VAL_FAIL);
        AtomicCompareExchange((long*)&__SET_VAL_FAIL_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__FILE_NOT_FOUND_rlock, 0, 1)){
        __FILE_NOT_FOUND_rbuffer = __GET_VAR(CONFIG__FILE_NOT_FOUND);
        AtomicCompareExchange((long*)&__FILE_NOT_FOUND_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__CLOSE_CSV_OK_rlock, 0, 1)){
        __CLOSE_CSV_OK_rbuffer = __GET_VAR(CONFIG__CLOSE_CSV_OK);
        AtomicCompareExchange((long*)&__CLOSE_CSV_OK_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__CLOSE_CSV_FAIL_rlock, 0, 1)){
        __CLOSE_CSV_FAIL_rbuffer = __GET_VAR(CONFIG__CLOSE_CSV_FAIL);
        AtomicCompareExchange((long*)&__CLOSE_CSV_FAIL_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__SAVE_CSV_OK_rlock, 0, 1)){
        __SAVE_CSV_OK_rbuffer = __GET_VAR(CONFIG__SAVE_CSV_OK);
        AtomicCompareExchange((long*)&__SAVE_CSV_OK_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__SAVE_CSV_FAIL_rlock, 0, 1)){
        __SAVE_CSV_FAIL_rbuffer = __GET_VAR(CONFIG__SAVE_CSV_FAIL);
        AtomicCompareExchange((long*)&__SAVE_CSV_FAIL_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__SIGNAL_NOT_CONNECT_rlock, 0, 1)){
        __SIGNAL_NOT_CONNECT_rbuffer = __GET_VAR(CONFIG__SIGNAL_NOT_CONNECT);
        AtomicCompareExchange((long*)&__SIGNAL_NOT_CONNECT_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__INFO_rlock, 0, 1)){
        __INFO_rbuffer = __GET_VAR(CONFIG__INFO);
        AtomicCompareExchange((long*)&__INFO_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__WARNING_rlock, 0, 1)){
        __WARNING_rbuffer = __GET_VAR(CONFIG__WARNING);
        AtomicCompareExchange((long*)&__WARNING_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__ERROR_rlock, 0, 1)){
        __ERROR_rbuffer = __GET_VAR(CONFIG__ERROR);
        AtomicCompareExchange((long*)&__ERROR_rlock, 1, 0);
    }

}
