/*
 * Code generated by Beremiz py_ext confnode
 * for safe global variables access
 */
#include "iec_types_all.h"
#include "POUS.h"
#include "config.h"
#include "beremiz.h"

/* User variables reference */
extern  __IEC_DINT_t CONF_PYTEST__SOMEVARNAME;
IEC_DINT __SomeVarName_rbuffer = __INIT_DINT;
IEC_DINT __SomeVarName_wbuffer;
long __SomeVarName_rlock = 0;
long __SomeVarName_wlock = 0;
int __SomeVarName_wbuffer_written = 0;
void __SafeGetPLCGlob_SomeVarName(IEC_DINT *pvalue){
    while(AtomicCompareExchange(&__SomeVarName_rlock, 0, 1));
    *pvalue = __SomeVarName_rbuffer;
    AtomicCompareExchange((long*)&__SomeVarName_rlock, 1, 0);
}
void __SafeSetPLCGlob_SomeVarName(IEC_DINT *value){
    while(AtomicCompareExchange(&__SomeVarName_wlock, 0, 1));
    __SomeVarName_wbuffer = *value;
    __SomeVarName_wbuffer_written = 1;
    AtomicCompareExchange((long*)&__SomeVarName_wlock, 1, 0);
}


extern  __IEC_STRING_t CONF_PYTEST__GRUMPF;
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



/* Beremiz confnode functions */
int __init_2(int argc,char **argv){

    return 0;
}

void __cleanup_2(void){
}

void __retrieve_2(void){
    if(!AtomicCompareExchange(&__SomeVarName_wlock, 0, 1)){
        if(__SomeVarName_wbuffer_written == 1){
            CONF_PYTEST__SOMEVARNAME.value = __SomeVarName_wbuffer;
            __SomeVarName_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__SomeVarName_wlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__Grumpf_wlock, 0, 1)){
        if(__Grumpf_wbuffer_written == 1){
            CONF_PYTEST__GRUMPF.value = __Grumpf_wbuffer;
            __Grumpf_wbuffer_written = 0;
        }
        AtomicCompareExchange((long*)&__Grumpf_wlock, 1, 0);
    }

}

void __publish_2(void){
    if(!AtomicCompareExchange(&__SomeVarName_rlock, 0, 1)){
        __SomeVarName_rbuffer = __GET_VAR(CONF_PYTEST__SOMEVARNAME);
        AtomicCompareExchange((long*)&__SomeVarName_rlock, 1, 0);
    }

    if(!AtomicCompareExchange(&__Grumpf_rlock, 0, 1)){
        __Grumpf_rbuffer = __GET_VAR(CONF_PYTEST__GRUMPF);
        AtomicCompareExchange((long*)&__Grumpf_rlock, 1, 0);
    }

}
