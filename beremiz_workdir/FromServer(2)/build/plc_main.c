/**
 * Head of code common to all C targets
 **/

#include "beremiz.h"
#include <string.h>
/*
 * Prototypes of functions provided by generated C softPLC
 **/
void config_run__(unsigned long tick);
void config_init__(void);

/*
 * Prototypes of functions provided by generated target C code
 * */
long long AtomicCompareExchange64(long long*, long long, long long);
void __init_debug(void);
void __cleanup_debug(void);
/*void __retrieve_debug(void);*/
void __publish_debug(void);

/*
 *  Variables used by generated C softPLC and plugins
 **/
IEC_TIME __CURRENT_TIME;
IEC_BOOL __DEBUG = 0;
unsigned long __tick = 0;
char *PLC_ID = NULL;

/*
 *  Variable generated by C softPLC and plugins
 **/
extern unsigned long greatest_tick_count__;

/* Help to quit cleanly when init fail at a certain level */
static int init_level = 0;

/*
 * Prototypes of functions exported by plugins
 **/
int __init_py_ext(int argc,char **argv);
void __cleanup_py_ext(void);
void __retrieve_py_ext(void);
void __publish_py_ext(void);
int __init_0(int argc,char **argv);
void __cleanup_0(void);
void __retrieve_0(void);
void __publish_0(void);
int __init_1(int argc,char **argv);
void __cleanup_1(void);
void __retrieve_1(void);
void __publish_1(void);

/*
 * Retrieve input variables, run PLC and publish output variables
 **/
void __run(void)
{
    __tick++;
    if (greatest_tick_count__)
        __tick %= greatest_tick_count__;

    __retrieve_py_ext();
    __retrieve_0();
    __retrieve_1();

    /*__retrieve_debug();*/

    config_run__(__tick);

    __publish_debug();

    __publish_1();
    __publish_0();
    __publish_py_ext();

}

/*
 * Initialize variables according to PLC's default values,
 * and then init plugins with that values
 **/
int __init(int argc,char **argv)
{
    int res = 0;
    init_level = 0;
    
    /* Effective tick time with 1ms default value */
    if(!common_ticktime__)
        common_ticktime__ = 1000000;

    config_init__();
    __init_debug();
    init_level=1; if((res = __init_py_ext(argc,argv))){return res;}
    init_level=2; if((res = __init_0(argc,argv))){return res;}
    init_level=3; if((res = __init_1(argc,argv))){return res;}
    return res;
}
/*
 * Calls plugin cleanup proc.
 **/
void __cleanup(void)
{
    if(init_level >= 3) __cleanup_1();
    if(init_level >= 2) __cleanup_0();
    if(init_level >= 1) __cleanup_py_ext();
    __cleanup_debug();
}

void PLC_GetTime(IEC_TIME *CURRENT_TIME);
void PLC_SetTimer(unsigned long long next, unsigned long long period);



/**
 * Win32 specific code
 **/

#include <stdio.h>
#include <sys/timeb.h>
#include <time.h>
#include <windows.h>
#include <locale.h>


long AtomicCompareExchange(long* atomicvar, long compared, long exchange)
{
    return InterlockedCompareExchange(atomicvar, exchange, compared);
}
CRITICAL_SECTION Atomic64CS; 
long long AtomicCompareExchange64(long long* atomicvar, long long compared, long long exchange)
{
    long long res;
    EnterCriticalSection(&Atomic64CS);
    res=*atomicvar;
    if(*atomicvar == compared){
        *atomicvar = exchange;
    }
    LeaveCriticalSection(&Atomic64CS);
    return res;
}

struct _timeb timetmp;
void PLC_GetTime(IEC_TIME *CURRENT_TIME)
{
	_ftime(&timetmp);

	(*CURRENT_TIME).tv_sec = timetmp.time;
	(*CURRENT_TIME).tv_nsec = timetmp.millitm * 1000000;
}

void PLC_timer_notify()
{
    PLC_GetTime(&__CURRENT_TIME);
    __run();
}

HANDLE PLC_timer = NULL;
void PLC_SetTimer(unsigned long long next, unsigned long long period)
{
	LARGE_INTEGER liDueTime;
	/* arg 2 of SetWaitableTimer take 100 ns interval*/
	liDueTime.QuadPart =  next / (-100);

	if (!SetWaitableTimer(PLC_timer, &liDueTime, period<1000000?1:period/1000000, NULL, NULL, 0))
    {
        printf("SetWaitableTimer failed (%d)\n", GetLastError());
    }
}

/* Variable used to stop plcloop thread */
void PlcLoop()
{
    while(WaitForSingleObject(PLC_timer, INFINITE) == WAIT_OBJECT_0)
    {
        PLC_timer_notify();
    }
}

HANDLE PLC_thread;
HANDLE debug_sem;
HANDLE debug_wait_sem;
HANDLE python_sem;
HANDLE python_wait_sem;

#define maxval(a,b) ((a>b)?a:b)
int startPLC(int argc,char **argv)
{
	unsigned long thread_id = 0;
    BOOL tmp;
    setlocale(LC_NUMERIC, "C");

    debug_sem = CreateSemaphore(
                            NULL,           // default security attributes
                            1,  			// initial count
                            1,  			// maximum count
                            NULL);          // unnamed semaphore
    if (debug_sem == NULL)
    {
        printf("startPLC CreateSemaphore debug_sem error: %d\n", GetLastError());
        return 1;
    }

    debug_wait_sem = CreateSemaphore(
                            NULL,           // default security attributes
                            0,  			// initial count
                            1,  			// maximum count
                            NULL);          // unnamed semaphore

    if (debug_wait_sem == NULL)
    {
        printf("startPLC CreateSemaphore debug_wait_sem error: %d\n", GetLastError());
        return 1;
    }

    python_sem = CreateSemaphore(
                            NULL,           // default security attributes
                            1,  			// initial count
                            1,  			// maximum count
                            NULL);          // unnamed semaphore

    if (python_sem == NULL)
    {
        printf("startPLC CreateSemaphore python_sem error: %d\n", GetLastError());
        return 1;
    }
    python_wait_sem = CreateSemaphore(
                            NULL,           // default security attributes
                            0,  			// initial count
                            1,  			// maximum count
                            NULL);          // unnamed semaphore


    if (python_wait_sem == NULL)
    {
        printf("startPLC CreateSemaphore python_wait_sem error: %d\n", GetLastError());
        return 1;
    }


    /* Create a waitable timer */
    timeBeginPeriod(1);
    PLC_timer = CreateWaitableTimer(NULL, FALSE, "WaitableTimer");
    if(NULL == PLC_timer)
    {
        printf("CreateWaitableTimer failed (%d)\n", GetLastError());
        return 1;
    }
    if( __init(argc,argv) == 0 )
    {
        PLC_SetTimer(common_ticktime__,common_ticktime__);
        PLC_thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)PlcLoop, NULL, 0, &thread_id);
    }
    else{
        return 1;
    }
    return 0;
}
static unsigned long __debug_tick;

int TryEnterDebugSection(void)
{
	//printf("TryEnterDebugSection\n");
    if(WaitForSingleObject(debug_sem, 0) == WAIT_OBJECT_0){
        /* Only enter if debug active */
        if(__DEBUG){
            return 1;
        }
        ReleaseSemaphore(debug_sem, 1, NULL);
    }
    return 0;
}

void LeaveDebugSection(void)
{
	ReleaseSemaphore(debug_sem, 1, NULL);
    //printf("LeaveDebugSection\n");
}

int stopPLC()
{
    CloseHandle(PLC_timer);
    WaitForSingleObject(PLC_thread, INFINITE);
    __cleanup();
    CloseHandle(debug_wait_sem);
    CloseHandle(debug_sem);
    CloseHandle(python_wait_sem);
    CloseHandle(python_sem);
    CloseHandle(PLC_thread);
}

/* from plc_debugger.c */
int WaitDebugData(unsigned long *tick)
{
	DWORD res;
	res = WaitForSingleObject(debug_wait_sem, INFINITE);
    *tick = __debug_tick;
    /* Wait signal from PLC thread */
	return res != WAIT_OBJECT_0;
}

/* Called by PLC thread when debug_publish finished
 * This is supposed to unlock debugger thread in WaitDebugData*/
void InitiateDebugTransfer()
{
    /* remember tick */
    __debug_tick = __tick;
    /* signal debugger thread it can read data */
    ReleaseSemaphore(debug_wait_sem, 1, NULL);
}

int suspendDebug(int disable)
{
    /* Prevent PLC to enter debug code */
    WaitForSingleObject(debug_sem, INFINITE);
    __DEBUG = !disable;
    if(disable)
        ReleaseSemaphore(debug_sem, 1, NULL);
    return 0;
}

void resumeDebug()
{
	__DEBUG = 1;
    /* Let PLC enter debug code */
	ReleaseSemaphore(debug_sem, 1, NULL);
}

/* from plc_python.c */
int WaitPythonCommands(void)
{
    /* Wait signal from PLC thread */
	return WaitForSingleObject(python_wait_sem, INFINITE);
}

/* Called by PLC thread on each new python command*/
void UnBlockPythonCommands(void)
{
    /* signal debugger thread it can read data */
	ReleaseSemaphore(python_wait_sem, 1, NULL);
}

int TryLockPython(void)
{
	return WaitForSingleObject(python_sem, 0) == WAIT_OBJECT_0;
}

void UnLockPython(void)
{
	ReleaseSemaphore(python_sem, 1, NULL);
}

void LockPython(void)
{
	WaitForSingleObject(python_sem, INFINITE);
}

void InitRetain(void)
{
}

void CleanupRetain(void)
{
}

int CheckRetainBuffer(void)
{
	return 1;
}

void ValidateRetainBuffer(void)
{
}

void InValidateRetainBuffer(void)
{
}

void Retain(unsigned int offset, unsigned int count, void * p)
{
    /*
    unsigned int position;
    for(position=0; position<count; position++ ){
        printf("%d : 0x%2.2x\n", offset+position, ((char*)p)[position]);
    }
    */
}

void Remind(unsigned int offset, unsigned int count, void *p)
{
}

static void __attribute__((constructor))
beremiz_dll_init(void)
{
    InitializeCriticalSection(&Atomic64CS);

}

static void __attribute__((destructor))
beremiz_dll_destroy(void)
{
    DeleteCriticalSection(&Atomic64CS);
}

/**
 * Tail of code common to all C targets
 **/

/** 
 * LOGGING
 **/

#ifndef LOG_BUFFER_SIZE
#define LOG_BUFFER_SIZE (1<<14) /*16Ko*/
#endif
#ifndef LOG_BUFFER_ATTRS
#define LOG_BUFFER_ATTRS
#endif

#define LOG_BUFFER_MASK (LOG_BUFFER_SIZE-1)

static char LogBuff[LOG_LEVELS][LOG_BUFFER_SIZE] LOG_BUFFER_ATTRS;
static void inline copy_to_log(uint8_t level, uint32_t buffpos, void* buf, uint32_t size){
    if(buffpos + size < LOG_BUFFER_SIZE){
        memcpy(&LogBuff[level][buffpos], buf, size);
    }else{
        uint32_t remaining = LOG_BUFFER_SIZE - buffpos; 
        memcpy(&LogBuff[level][buffpos], buf, remaining);
        memcpy(LogBuff[level], (char*)buf + remaining, size - remaining);
    }
}
static void inline copy_from_log(uint8_t level, uint32_t buffpos, void* buf, uint32_t size){
    if(buffpos + size < LOG_BUFFER_SIZE){
        memcpy(buf, &LogBuff[level][buffpos], size);
    }else{
        uint32_t remaining = LOG_BUFFER_SIZE - buffpos; 
        memcpy(buf, &LogBuff[level][buffpos], remaining);
        memcpy((char*)buf + remaining, LogBuff[level], size - remaining);
    }
}

/* Log buffer structure

 |<-Tail1.msgsize->|<-sizeof(mTail)->|<--Tail2.msgsize-->|<-sizeof(mTail)->|...
 |  Message1 Body  |      Tail1      |   Message2 Body   |      Tail2      |

*/
typedef struct {
    uint32_t msgidx;
    uint32_t msgsize;
    unsigned long tick;
    IEC_TIME time;
} mTail;

/* Log cursor : 64b
   |63 ... 32|31 ... 0|
   | Message | Buffer |
   | counter | Index  | */
static uint64_t LogCursor[LOG_LEVELS] LOG_BUFFER_ATTRS = {0x0,0x0,0x0,0x0};

void ResetLogCount(void) {
	uint8_t level;
	for(level=0;level<LOG_LEVELS;level++){
		LogCursor[level] = 0;
	}
}

/* Store one log message of give size */
int LogMessage(uint8_t level, char* buf, uint32_t size){
    if(size < LOG_BUFFER_SIZE - sizeof(mTail)){
        uint32_t buffpos;
        uint64_t new_cursor, old_cursor;

        mTail tail;
        tail.msgsize = size;
        tail.tick = __tick;
        PLC_GetTime(&tail.time);

        /* We cannot increment both msg index and string pointer 
           in a single atomic operation but we can detect having been interrupted.
           So we can try with atomic compare and swap in a loop until operation
           succeeds non interrupted */
        do{
            old_cursor = LogCursor[level];
            buffpos = (uint32_t)old_cursor;
            tail.msgidx = (old_cursor >> 32); 
            new_cursor = ((uint64_t)(tail.msgidx + 1)<<32) 
                         | (uint64_t)((buffpos + size + sizeof(mTail)) & LOG_BUFFER_MASK);
        }while(AtomicCompareExchange64(
            (long long*)&LogCursor[level],
            (long long)old_cursor,
            (long long)new_cursor)!=(long long)old_cursor);

        copy_to_log(level, buffpos, buf, size);
        copy_to_log(level, (buffpos + size) & LOG_BUFFER_MASK, &tail, sizeof(mTail));

        return 1; /* Success */
    }else{
    	char mstr[] = "Logging error : message too big";
        LogMessage(LOG_CRITICAL, mstr, sizeof(mstr));
    }
    return 0;
}

uint32_t GetLogCount(uint8_t level){
    return (uint64_t)LogCursor[level] >> 32;
}

/* Return message size and content */
uint32_t GetLogMessage(uint8_t level, uint32_t msgidx, char* buf, uint32_t max_size, uint32_t* tick, uint32_t* tv_sec, uint32_t* tv_nsec){
    uint64_t cursor = LogCursor[level];
    if(cursor){
        /* seach cursor */
        uint32_t stailpos = (uint32_t)cursor; 
        uint32_t smsgidx;
        mTail tail;
        tail.msgidx = cursor >> 32;
        tail.msgsize = 0;

        /* Message search loop */
        do {
            smsgidx = tail.msgidx;
            stailpos = (stailpos - sizeof(mTail) - tail.msgsize ) & LOG_BUFFER_MASK;
            copy_from_log(level, stailpos, &tail, sizeof(mTail));
        }while((tail.msgidx == smsgidx - 1) && (tail.msgidx > msgidx));

        if(tail.msgidx == msgidx){
            uint32_t sbuffpos = (stailpos - tail.msgsize ) & LOG_BUFFER_MASK; 
            uint32_t totalsize = tail.msgsize;
            *tick = tail.tick; 
            *tv_sec = tail.time.tv_sec; 
            *tv_nsec = tail.time.tv_nsec; 
            copy_from_log(level, sbuffpos, buf, 
                          totalsize > max_size ? max_size : totalsize);
            return totalsize;
        }
    }
    return 0;
}

#define CALIBRATED -2
#define NOT_CALIBRATED -1
static int calibration_count = NOT_CALIBRATED;
static IEC_TIME cal_begin;
static long long Tsync = 0;
static long long FreqCorr = 0;
static int Nticks = 0;
static unsigned long last_tick = 0;

/*
 * Called on each external periodic sync event
 * make PLC tick synchronous with external sync
 * ratio defines when PLC tick occurs between two external sync
 * @param sync_align_ratio 
 *          0->100 : align ratio
 *          < 0 : no align, calibrate period
 **/
void align_tick(int sync_align_ratio)
{
	/*
	printf("align_tick(%d)\n", calibrate);
	*/
	if(sync_align_ratio < 0){ /* Calibration */
		if(calibration_count == CALIBRATED)
			/* Re-calibration*/
			calibration_count = NOT_CALIBRATED;
		if(calibration_count == NOT_CALIBRATED)
			/* Calibration start, get time*/
			PLC_GetTime(&cal_begin);
		calibration_count++;
	}else{ /* do alignment (if possible) */
		if(calibration_count >= 0){
			/* End of calibration */
			/* Get final time */
			IEC_TIME cal_end;
			PLC_GetTime(&cal_end);
			/*adjust calibration_count*/
			calibration_count++;
			/* compute mean of Tsync, over calibration period */
			Tsync = ((long long)(cal_end.tv_sec - cal_begin.tv_sec) * (long long)1000000000 +
					(cal_end.tv_nsec - cal_begin.tv_nsec)) / calibration_count;
			if( (Nticks = (Tsync / common_ticktime__)) > 0){
				FreqCorr = (Tsync % common_ticktime__); /* to be divided by Nticks */
			}else{
				FreqCorr = Tsync - (common_ticktime__ % Tsync);
			}
			/*
			printf("Tsync = %ld\n", Tsync);
			printf("calibration_count = %d\n", calibration_count);
			printf("Nticks = %d\n", Nticks);
			*/
			calibration_count = CALIBRATED;
		}
		if(calibration_count == CALIBRATED){
			/* Get Elapsed time since last PLC tick (__CURRENT_TIME) */
			IEC_TIME now;
			long long elapsed;
			long long Tcorr;
			long long PhaseCorr;
			long long PeriodicTcorr;
			PLC_GetTime(&now);
			elapsed = (now.tv_sec - __CURRENT_TIME.tv_sec) * 1000000000 + now.tv_nsec - __CURRENT_TIME.tv_nsec;
			if(Nticks > 0){
				PhaseCorr = elapsed - (common_ticktime__ + FreqCorr/Nticks)*sync_align_ratio/100; /* to be divided by Nticks */
				Tcorr = common_ticktime__ + (PhaseCorr + FreqCorr) / Nticks;
				if(Nticks < 2){
					/* When Sync source period is near Tick time */
					/* PhaseCorr may not be applied to Periodic time given to timer */
					PeriodicTcorr = common_ticktime__ + FreqCorr / Nticks;
				}else{
					PeriodicTcorr = Tcorr;
				}
			}else if(__tick > last_tick){
				last_tick = __tick;
				PhaseCorr = elapsed - (Tsync*sync_align_ratio/100);
				PeriodicTcorr = Tcorr = common_ticktime__ + PhaseCorr + FreqCorr;
			}else{
				/*PLC did not run meanwhile. Nothing to do*/
				return;
			}
			/* DO ALIGNEMENT */
			PLC_SetTimer(Tcorr - elapsed, PeriodicTcorr);
		}
	}
}