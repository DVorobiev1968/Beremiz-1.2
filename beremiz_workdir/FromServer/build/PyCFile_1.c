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


extern  __IEC_STRING_t CONFIG__HOST;
IEC_STRING __host_rbuffer = __INIT_STRING;
IEC_STRING __host_wbuffer;
long __host_rlock = 0;
long __host_wlock = 0;
int __host_wbuffer_written = 0;
void __SafeGetPLCGlob_host(IEC_STRING *pvalue){
    while(AtomicCompareExchange(&__host_rlock, 0, 1));
    *pvalue = __host_rbuffer;
    AtomicCompareExchange((long*)&__host_rlock, 1, 0);
}
void __SafeSetPLCGlob_host(IEC_STRING *value){
    while(AtomicCompareExchange(&__host_wlock, 0, 1));
    __host_wbuffer = *value;
    __host_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__host_wlock, 1, 0);
}


extern  __IEC_INT_t CONFIG__PORT;
IEC_INT __PORT_rbuffer = __INIT_INT;
IEC_INT __PORT_wbuffer;
long __PORT_rlock = 0;
long __PORT_wlock = 0;
int __PORT_wbuffer_written = 0;
void __SafeGetPLCGlob_PORT(IEC_INT *pvalue){
    while(AtomicCompareExchange(&__PORT_rlock, 0, 1));
    *pvalue = __PORT_rbuffer;
    AtomicCompareExchange((long*)&__PORT_rlock, 1, 0);
}
void __SafeSetPLCGlob_PORT(IEC_INT *value){
    while(AtomicCompareExchange(&__PORT_wlock, 0, 1));
    __PORT_wbuffer = *value;
    __PORT_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__PORT_wlock, 1, 0);
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

    if(!AtomicCompareExchange(&__i_status_wlock, 0, 1)){
        if(__i_status_wbuffer_written == 1){
            CONFIG__I_STATUS.value = __i_status_wbuffer;
            __i_status_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__i_status_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__host_wlock, 0, 1)){
        if(__host_wbuffer_written == 1){
            CONFIG__HOST.value = __host_wbuffer;
            __host_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__host_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__PORT_wlock, 0, 1)){
        if(__PORT_wbuffer_written == 1){
            CONFIG__PORT.value = __PORT_wbuffer;
            __PORT_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__PORT_wlock, 1, 0);
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

    if(!AtomicCompareExchange(&__i_status_rlock, 0, 1)){
        __i_status_rbuffer = __GET_VAR(CONFIG__I_STATUS);
        AtomicCompareExchange((long*)&__i_status_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__host_rlock, 0, 1)){
        __host_rbuffer = __GET_VAR(CONFIG__HOST);
        AtomicCompareExchange((long*)&__host_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__PORT_rlock, 0, 1)){
        __PORT_rbuffer = __GET_VAR(CONFIG__PORT);
        AtomicCompareExchange((long*)&__PORT_rlock, 1, 0);
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