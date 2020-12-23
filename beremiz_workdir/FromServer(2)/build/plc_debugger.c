/*
 * DEBUGGER code
 * 
 * On "publish", when buffer is free, debugger stores arbitrary variables 
 * content into, and mark this buffer as filled
 * 
 * 
 * Buffer content is read asynchronously, (from non real time part), 
 * and then buffer marked free again.
 *  
 * 
 * */
#include "iec_types_all.h"
#include "POUS.h"
/*for memcpy*/
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 2117

/* Atomically accessed variable for buffer state */
#define BUFFER_FREE 0
#define BUFFER_BUSY 1
static long buffer_state = BUFFER_FREE;

/* The buffer itself */
char debug_buffer[BUFFER_SIZE];

/* Buffer's cursor*/
static char* buffer_cursor = debug_buffer;
static unsigned int retain_offset = 0;
/***
 * Declare programs 
 **/
extern TEST_1 RESOURCE1__SRV;

/***
 * Declare global variables from resources and conf 
 **/
extern __IEC_INT_t CONFIG__DEBUG;
extern __IEC_STRING_t CONFIG__PATH;
extern __IEC_INT_t CONFIG__I_STATUS;
extern __IEC_STRING_t CONFIG__HOST;
extern __IEC_INT_t CONFIG__PORT;
extern __IEC_INT_t CONFIG__INFO;
extern __IEC_INT_t CONFIG__WARNING;
extern __IEC_INT_t CONFIG__ERROR;
extern       TEST_1   RESOURCE1__SRV;

typedef const struct {
    void *ptr;
    __IEC_types_enum type;
} dbgvardsc_t;

static dbgvardsc_t dbgvardsc[] = {
{&(CONFIG__DEBUG), INT_ENUM},
{&(CONFIG__PATH), STRING_ENUM},
{&(CONFIG__I_STATUS), INT_ENUM},
{&(CONFIG__HOST), STRING_ENUM},
{&(CONFIG__PORT), INT_ENUM},
{&(CONFIG__INFO), INT_ENUM},
{&(CONFIG__WARNING), INT_ENUM},
{&(CONFIG__ERROR), INT_ENUM},
{&(RESOURCE1__SRV.ID_NODE), INT_ENUM},
{&(RESOURCE1__SRV.I_OBJ), INT_ENUM},
{&(RESOURCE1__SRV.I_OBJ_1), INT_ENUM},
{&(RESOURCE1__SRV.I_SUBOBJ), INT_ENUM},
{&(RESOURCE1__SRV.TRIGGER0), BOOL_ENUM},
{&(RESOURCE1__SRV.S_OUT), STRING_ENUM},
{&(RESOURCE1__SRV.D_VALUE), REAL_ENUM},
{&(RESOURCE1__SRV.D_VAL_OUT_1), REAL_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.EN), BOOL_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.ENO), BOOL_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.PYTRIGGER), BOOL_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.NAMEFUNCTION), STRING_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.ID_NODE), INT_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.ID_OBJ), INT_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.ID_SUBOBJ), INT_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.PYTHON_EVAL0.EN), BOOL_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.PYTHON_EVAL0.ENO), BOOL_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.PYTHON_EVAL0.TRIG), BOOL_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.PYTHON_EVAL0.CODE), STRING_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.PYTHON_EVAL0.ACK), BOOL_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.PYTHON_EVAL0.RESULT), STRING_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.PYTHON_EVAL0.STATE), DWORD_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.PYTHON_EVAL0.BUFFER), STRING_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.PYTHON_EVAL0.PREBUFFER), STRING_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.PYTHON_EVAL0.TRIGM1), BOOL_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.PYTHON_EVAL0.TRIGGED), BOOL_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.D_VALUE), REAL_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.NOT2_OUT), BOOL_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.CALL_METHOD8_OUT), STRING_ENUM},
{&(RESOURCE1__SRV.LOAD_SOCKET_NODE0.STRING_TO_REAL12_OUT), REAL_ENUM},
{&(RESOURCE1__SRV.CYCLE), STRING_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.EN), BOOL_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.ENO), BOOL_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.PYTRIGGER), BOOL_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.NAMEFUNCTION), STRING_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.ID_NODE), INT_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.ID_OBJ), INT_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.ID_SUBOBJ), INT_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.PYTHON_EVAL0.EN), BOOL_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.PYTHON_EVAL0.ENO), BOOL_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.PYTHON_EVAL0.TRIG), BOOL_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.PYTHON_EVAL0.CODE), STRING_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.PYTHON_EVAL0.ACK), BOOL_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.PYTHON_EVAL0.RESULT), STRING_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.PYTHON_EVAL0.STATE), DWORD_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.PYTHON_EVAL0.BUFFER), STRING_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.PYTHON_EVAL0.PREBUFFER), STRING_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.PYTHON_EVAL0.TRIGM1), BOOL_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.PYTHON_EVAL0.TRIGGED), BOOL_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.D_VALUE), REAL_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.NOT2_OUT), BOOL_ENUM},
{&(RESOURCE1__SRV.SET_SOCKET_NODE0.CALL_METHOD8_OUT), STRING_ENUM},
{&(RESOURCE1__SRV.EXPT31_OUT), REAL_ENUM}
};

typedef void(*__for_each_variable_do_fp)(dbgvardsc_t*);
void __for_each_variable_do(__for_each_variable_do_fp fp)
{
    int i;
    for(i = 0; i < sizeof(dbgvardsc)/sizeof(dbgvardsc_t); i++){
        dbgvardsc_t *dsc = &dbgvardsc[i];
        if(dsc->type != UNKNOWN_ENUM) 
            (*fp)(dsc);
    }
}

#define __Unpack_case_t(TYPENAME) \
        case TYPENAME##_ENUM :\
            *flags = ((__IEC_##TYPENAME##_t *)varp)->flags;\
            forced_value_p = *real_value_p = &((__IEC_##TYPENAME##_t *)varp)->value;\
            break;

#define __Unpack_case_p(TYPENAME)\
        case TYPENAME##_O_ENUM :\
            *flags = __IEC_OUTPUT_FLAG;\
        case TYPENAME##_P_ENUM :\
            *flags |= ((__IEC_##TYPENAME##_p *)varp)->flags;\
            *real_value_p = ((__IEC_##TYPENAME##_p *)varp)->value;\
            forced_value_p = &((__IEC_##TYPENAME##_p *)varp)->fvalue;\
            break;

void* UnpackVar(dbgvardsc_t *dsc, void **real_value_p, char *flags)
{
    void *varp = dsc->ptr;
    void *forced_value_p = NULL;
    *flags = 0;
    /* find data to copy*/
    switch(dsc->type){
        __ANY(__Unpack_case_t)
        __ANY(__Unpack_case_p)
    default:
        break;
    }
    if (*flags & __IEC_FORCE_FLAG)
        return forced_value_p;
    return *real_value_p;
}

void Remind(unsigned int offset, unsigned int count, void * p);

void RemindIterator(dbgvardsc_t *dsc)
{
    void *real_value_p = NULL;
    char flags = 0;
    UnpackVar(dsc, &real_value_p, &flags);

    if(flags & __IEC_RETAIN_FLAG){
        USINT size = __get_type_enum_size(dsc->type);
        /* compute next cursor positon*/
        unsigned int next_retain_offset = retain_offset + size;
        /* if buffer not full */
        Remind(retain_offset, size, real_value_p);
        /* increment cursor according size*/
        retain_offset = next_retain_offset;
    }
}

extern int CheckRetainBuffer(void);
extern void InitRetain(void);

void __init_debug(void)
{
    /* init local static vars */
    buffer_cursor = debug_buffer;
    retain_offset = 0;
    buffer_state = BUFFER_FREE;
    InitRetain();
    /* Iterate over all variables to fill debug buffer */
    if(CheckRetainBuffer()){
    	__for_each_variable_do(RemindIterator);
    }else{
    	char mstr[] = "RETAIN memory invalid - defaults used";
        LogMessage(LOG_WARNING, mstr, sizeof(mstr));
    }
    retain_offset = 0;
}

extern void InitiateDebugTransfer(void);
extern void CleanupRetain(void);

extern unsigned long __tick;

void __cleanup_debug(void)
{
    buffer_cursor = debug_buffer;
    InitiateDebugTransfer();
    CleanupRetain();
}

void __retrieve_debug(void)
{
}


void Retain(unsigned int offset, unsigned int count, void * p);

static inline void BufferIterator(dbgvardsc_t *dsc, int do_debug)
{
    void *real_value_p = NULL;
    void *visible_value_p = NULL;
    char flags = 0;

    visible_value_p = UnpackVar(dsc, &real_value_p, &flags);

    if(flags & ( __IEC_DEBUG_FLAG | __IEC_RETAIN_FLAG)){
        USINT size = __get_type_enum_size(dsc->type);
        if(flags & __IEC_DEBUG_FLAG){
            /* copy visible variable to buffer */;
            if(do_debug){
                /* compute next cursor positon.
                   No need to check overflow, as BUFFER_SIZE
                   is computed large enough */
		if((dsc->type == STRING_ENUM)   ||
		   (dsc->type == STRING_P_ENUM) ||
		   (dsc->type == STRING_O_ENUM)){
                    /* optimization for strings */
                    size = ((STRING*)visible_value_p)->len + 1;
                }
                char* next_cursor = buffer_cursor + size;
                /* copy data to the buffer */
                memcpy(buffer_cursor, visible_value_p, size);
                /* increment cursor according size*/
                buffer_cursor = next_cursor;
            }
            /* re-force real value of outputs (M and Q)*/
            if((flags & __IEC_FORCE_FLAG) && (flags & __IEC_OUTPUT_FLAG)){
                memcpy(real_value_p, visible_value_p, size);
            }
        }
        if(flags & __IEC_RETAIN_FLAG){
            /* compute next cursor positon*/
            unsigned int next_retain_offset = retain_offset + size;
            /* if buffer not full */
            Retain(retain_offset, size, real_value_p);
            /* increment cursor according size*/
            retain_offset = next_retain_offset;
        }
    }
}

void DebugIterator(dbgvardsc_t *dsc){
    BufferIterator(dsc, 1);
}

void RetainIterator(dbgvardsc_t *dsc){
    BufferIterator(dsc, 0);
}

extern void PLC_GetTime(IEC_TIME*);
extern int TryEnterDebugSection(void);
extern long AtomicCompareExchange(long*, long, long);
extern long long AtomicCompareExchange64(long long* , long long , long long);
extern void LeaveDebugSection(void);
extern void ValidateRetainBuffer(void);
extern void InValidateRetainBuffer(void);

void __publish_debug(void)
{
    retain_offset = 0;
    InValidateRetainBuffer();
    /* Check there is no running debugger re-configuration */
    if(TryEnterDebugSection()){
        /* Lock buffer */
        long latest_state = AtomicCompareExchange(
            &buffer_state,
            BUFFER_FREE,
            BUFFER_BUSY);
            
        /* If buffer was free */
        if(latest_state == BUFFER_FREE)
        {
            /* Reset buffer cursor */
            buffer_cursor = debug_buffer;
            /* Iterate over all variables to fill debug buffer */
            __for_each_variable_do(DebugIterator);
            
            /* Leave debug section,
             * Trigger asynchronous transmission 
             * (returns immediately) */
            InitiateDebugTransfer(); /* size */
        }else{
            /* when not debugging, do only retain */
            __for_each_variable_do(RetainIterator);
        }
        LeaveDebugSection();
    }else{
        /* when not debugging, do only retain */
        __for_each_variable_do(RetainIterator);
    }
    ValidateRetainBuffer();
}

#define __RegisterDebugVariable_case_t(TYPENAME) \
        case TYPENAME##_ENUM :\
            ((__IEC_##TYPENAME##_t *)varp)->flags |= flags;\
            if(force)\
             ((__IEC_##TYPENAME##_t *)varp)->value = *((TYPENAME *)force);\
            break;
#define __RegisterDebugVariable_case_p(TYPENAME)\
        case TYPENAME##_P_ENUM :\
            ((__IEC_##TYPENAME##_p *)varp)->flags |= flags;\
            if(force)\
             ((__IEC_##TYPENAME##_p *)varp)->fvalue = *((TYPENAME *)force);\
            break;\
        case TYPENAME##_O_ENUM :\
            ((__IEC_##TYPENAME##_p *)varp)->flags |= flags;\
            if(force){\
             ((__IEC_##TYPENAME##_p *)varp)->fvalue = *((TYPENAME *)force);\
             *(((__IEC_##TYPENAME##_p *)varp)->value) = *((TYPENAME *)force);\
            }\
            break;
void RegisterDebugVariable(int idx, void* force)
{
    if(idx  < sizeof(dbgvardsc)/sizeof(dbgvardsc_t)){
        unsigned char flags = force ?
            __IEC_DEBUG_FLAG | __IEC_FORCE_FLAG :
            __IEC_DEBUG_FLAG;
        dbgvardsc_t *dsc = &dbgvardsc[idx];
        void *varp = dsc->ptr;
        switch(dsc->type){
            __ANY(__RegisterDebugVariable_case_t)
            __ANY(__RegisterDebugVariable_case_p)
        default:
            break;
        }
    }
}

#define __ResetDebugVariablesIterator_case_t(TYPENAME) \
        case TYPENAME##_ENUM :\
            ((__IEC_##TYPENAME##_t *)varp)->flags &= ~(__IEC_DEBUG_FLAG|__IEC_FORCE_FLAG);\
            break;

#define __ResetDebugVariablesIterator_case_p(TYPENAME)\
        case TYPENAME##_P_ENUM :\
        case TYPENAME##_O_ENUM :\
            ((__IEC_##TYPENAME##_p *)varp)->flags &= ~(__IEC_DEBUG_FLAG|__IEC_FORCE_FLAG);\
            break;

void ResetDebugVariablesIterator(dbgvardsc_t *dsc)
{
    /* force debug flag to 0*/
    void *varp = dsc->ptr;
    switch(dsc->type){
        __ANY(__ResetDebugVariablesIterator_case_t)
        __ANY(__ResetDebugVariablesIterator_case_p)
    default:
        break;
    }
}

void ResetDebugVariables(void)
{
    __for_each_variable_do(ResetDebugVariablesIterator);
}

void FreeDebugData(void)
{
    /* atomically mark buffer as free */
    AtomicCompareExchange(
        &buffer_state,
        BUFFER_BUSY,
        BUFFER_FREE);
}
int WaitDebugData(unsigned long *tick);
/* Wait until debug data ready and return pointer to it */
int GetDebugData(unsigned long *tick, unsigned long *size, void **buffer){
    int wait_error = WaitDebugData(tick);
    if(!wait_error){
        *size = buffer_cursor - debug_buffer;
        *buffer = debug_buffer;
    }
    return wait_error;
}

