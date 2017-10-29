#include <node_api.h>

#include <unistd.h>

#define NAMES_SIZE 127

int32_t defaultNames[NAMES_SIZE] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

napi_value createFalse(napi_env env){
        napi_value result;
        napi_get_boolean(env, false, &result);
        return result;
}

napi_value get(napi_env env, napi_callback_info info){
        size_t argsLength = 1;
        napi_value args[1];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        if(argsLength < 1) {
                return createFalse(env);
        }

        int32_t index;
        napi_get_value_int32(env, args[0], &index);

        if(index < 0 || index >= NAMES_SIZE){
                return createFalse(env);
        }

        int32_t name = defaultNames[index];
        if(name == -1) {
                return createFalse(env);
        }

        int64_t result = sysconf(name);
        napi_value resultValue;
        napi_create_int64(env, result, &resultValue);
        return resultValue;
}

napi_value Init (napi_env env, napi_value exports) {
        #ifdef _SC_AIO_LISTIO_MAX
        defaultNames[0] = _SC_AIO_LISTIO_MAX;
        #endif
        #ifdef _SC_AIO_MAX
        defaultNames[1] = _SC_AIO_MAX;
        #endif
        #ifdef _SC_AIO_PRIO_DELTA_MAX
        defaultNames[2] = _SC_AIO_PRIO_DELTA_MAX;
        #endif
        #ifdef _SC_ARG_MAX
        defaultNames[3] = _SC_ARG_MAX;
        #endif
        #ifdef _SC_ATEXIT_MAX
        defaultNames[4] = _SC_ATEXIT_MAX;
        #endif
        #ifdef _SC_BC_BASE_MAX
        defaultNames[5] = _SC_BC_BASE_MAX;
        #endif
        #ifdef _SC_BC_DIM_MAX
        defaultNames[6] = _SC_BC_DIM_MAX;
        #endif
        #ifdef _SC_BC_SCALE_MAX
        defaultNames[7] = _SC_BC_SCALE_MAX;
        #endif
        #ifdef _SC_BC_STRING_MAX
        defaultNames[8] = _SC_BC_STRING_MAX;
        #endif
        #ifdef _SC_CHILD_MAX
        defaultNames[9] = _SC_CHILD_MAX;
        #endif
        #ifdef _SC_CLK_TCK
        defaultNames[10] = _SC_CLK_TCK;
        #endif
        #ifdef _SC_COLL_WEIGHTS_MAX
        defaultNames[11] = _SC_COLL_WEIGHTS_MAX;
        #endif
        #ifdef _SC_DELAYTIMER_MAX
        defaultNames[12] = _SC_DELAYTIMER_MAX;
        #endif
        #ifdef _SC_EXPR_NEST_MAX
        defaultNames[13] = _SC_EXPR_NEST_MAX;
        #endif
        #ifdef _SC_HOST_NAME_MAX
        defaultNames[14] = _SC_HOST_NAME_MAX;
        #endif
        #ifdef _SC_IOV_MAX
        defaultNames[15] = _SC_IOV_MAX;
        #endif
        #ifdef _SC_LINE_MAX
        defaultNames[16] = _SC_LINE_MAX;
        #endif
        #ifdef _SC_LOGIN_NAME_MAX
        defaultNames[17] = _SC_LOGIN_NAME_MAX;
        #endif
        #ifdef _SC_NGROUPS_MAX
        defaultNames[18] = _SC_NGROUPS_MAX;
        #endif
        #ifdef _SC_GETGR_R_SIZE_MAX
        defaultNames[19] = _SC_GETGR_R_SIZE_MAX;
        #endif
        #ifdef _SC_GETPW_R_SIZE_MAX
        defaultNames[20] = _SC_GETPW_R_SIZE_MAX;
        #endif
        #ifdef _SC_MQ_OPEN_MAX
        defaultNames[21] = _SC_MQ_OPEN_MAX;
        #endif
        #ifdef _SC_MQ_PRIO_MAX
        defaultNames[22] = _SC_MQ_PRIO_MAX;
        #endif
        #ifdef _SC_OPEN_MAX
        defaultNames[23] = _SC_OPEN_MAX;
        #endif
        #ifdef _SC_ADVISORY_INFO
        defaultNames[24] = _SC_ADVISORY_INFO;
        #endif
        #ifdef _SC_BARRIERS
        defaultNames[25] = _SC_BARRIERS;
        #endif
        #ifdef _SC_ASYNCHRONOUS_IO
        defaultNames[26] = _SC_ASYNCHRONOUS_IO;
        #endif
        #ifdef _SC_CLOCK_SELECTION
        defaultNames[27] = _SC_CLOCK_SELECTION;
        #endif
        #ifdef _SC_CPUTIME
        defaultNames[28] = _SC_CPUTIME;
        #endif
        #ifdef _SC_FSYNC
        defaultNames[29] = _SC_FSYNC;
        #endif
        #ifdef _SC_IPV6
        defaultNames[30] = _SC_IPV6;
        #endif
        #ifdef _SC_JOB_CONTROL
        defaultNames[31] = _SC_JOB_CONTROL;
        #endif
        #ifdef _SC_MAPPED_FILES
        defaultNames[32] = _SC_MAPPED_FILES;
        #endif
        #ifdef _SC_MEMLOCK
        defaultNames[33] = _SC_MEMLOCK;
        #endif
        #ifdef _SC_MEMLOCK_RANGE
        defaultNames[34] = _SC_MEMLOCK_RANGE;
        #endif
        #ifdef _SC_MEMORY_PROTECTION
        defaultNames[35] = _SC_MEMORY_PROTECTION;
        #endif
        #ifdef _SC_MESSAGE_PASSING
        defaultNames[36] = _SC_MESSAGE_PASSING;
        #endif
        #ifdef _SC_MONOTONIC_CLOCK
        defaultNames[37] = _SC_MONOTONIC_CLOCK;
        #endif
        #ifdef _SC_PRIORITIZED_IO
        defaultNames[38] = _SC_PRIORITIZED_IO;
        #endif
        #ifdef _SC_PRIORITY_SCHEDULING
        defaultNames[39] = _SC_PRIORITY_SCHEDULING;
        #endif
        #ifdef _SC_RAW_SOCKETS
        defaultNames[40] = _SC_RAW_SOCKETS;
        #endif
        #ifdef _SC_READER_WRITER_LOCKS
        defaultNames[41] = _SC_READER_WRITER_LOCKS;
        #endif
        #ifdef _SC_REALTIME_SIGNALS
        defaultNames[42] = _SC_REALTIME_SIGNALS;
        #endif
        #ifdef _SC_REGEXP
        defaultNames[43] = _SC_REGEXP;
        #endif
        #ifdef _SC_SAVED_IDS
        defaultNames[44] = _SC_SAVED_IDS;
        #endif
        #ifdef _SC_SEMAPHORES
        defaultNames[45] = _SC_SEMAPHORES;
        #endif
        #ifdef _SC_SHARED_MEMORY_OBJECTS
        defaultNames[46] = _SC_SHARED_MEMORY_OBJECTS;
        #endif
        #ifdef _SC_SHELL
        defaultNames[47] = _SC_SHELL;
        #endif
        #ifdef _SC_SPAWN
        defaultNames[48] = _SC_SPAWN;
        #endif
        #ifdef _SC_SPIN_LOCKS
        defaultNames[49] = _SC_SPIN_LOCKS;
        #endif
        #ifdef _SC_SPORADIC_SERVER
        defaultNames[50] = _SC_SPORADIC_SERVER;
        #endif
        #ifdef _SC_SS_REPL_MAX
        defaultNames[51] = _SC_SS_REPL_MAX;
        #endif
        #ifdef _SC_SYNCHRONIZED_IO
        defaultNames[52] = _SC_SYNCHRONIZED_IO;
        #endif
        #ifdef _SC_THREAD_ATTR_STACKADDR
        defaultNames[53] = _SC_THREAD_ATTR_STACKADDR;
        #endif
        #ifdef _SC_THREAD_ATTR_STACKSIZE
        defaultNames[54] = _SC_THREAD_ATTR_STACKSIZE;
        #endif
        #ifdef _SC_THREAD_CPUTIME
        defaultNames[55] = _SC_THREAD_CPUTIME;
        #endif
        #ifdef _SC_THREAD_PRIO_INHERIT
        defaultNames[56] = _SC_THREAD_PRIO_INHERIT;
        #endif
        #ifdef _SC_THREAD_PRIO_PROTECT
        defaultNames[57] = _SC_THREAD_PRIO_PROTECT;
        #endif
        #ifdef _SC_THREAD_PRIORITY_SCHEDULING
        defaultNames[58] = _SC_THREAD_PRIORITY_SCHEDULING;
        #endif
        #ifdef _SC_THREAD_PROCESS_SHARED
        defaultNames[59] = _SC_THREAD_PROCESS_SHARED;
        #endif
        #ifdef _SC_THREAD_SAFE_FUNCTIONS
        defaultNames[60] = _SC_THREAD_SAFE_FUNCTIONS;
        #endif
        #ifdef _SC_THREAD_SPORADIC_SERVER
        defaultNames[61] = _SC_THREAD_SPORADIC_SERVER;
        #endif
        #ifdef _SC_THREADS
        defaultNames[62] = _SC_THREADS;
        #endif
        #ifdef _SC_TIMEOUTS
        defaultNames[63] = _SC_TIMEOUTS;
        #endif
        #ifdef _SC_TIMERS
        defaultNames[64] = _SC_TIMERS;
        #endif
        #ifdef _SC_TRACE
        defaultNames[65] = _SC_TRACE;
        #endif
        #ifdef _SC_TRACE_EVENT_FILTER
        defaultNames[66] = _SC_TRACE_EVENT_FILTER;
        #endif
        #ifdef _SC_TRACE_EVENT_NAME_MAX
        defaultNames[67] = _SC_TRACE_EVENT_NAME_MAX;
        #endif
        #ifdef _SC_TRACE_INHERIT
        defaultNames[68] = _SC_TRACE_INHERIT;
        #endif
        #ifdef _SC_TRACE_LOG
        defaultNames[69] = _SC_TRACE_LOG;
        #endif
        #ifdef _SC_TRACE_NAME_MAX
        defaultNames[70] = _SC_TRACE_NAME_MAX;
        #endif
        #ifdef _SC_TRACE_SYS_MAX
        defaultNames[71] = _SC_TRACE_SYS_MAX;
        #endif
        #ifdef _SC_TRACE_USER_EVENT_MAX
        defaultNames[72] = _SC_TRACE_USER_EVENT_MAX;
        #endif
        #ifdef _SC_TYPED_MEMORY_OBJECTS
        defaultNames[73] = _SC_TYPED_MEMORY_OBJECTS;
        #endif
        #ifdef _SC_VERSION
        defaultNames[74] = _SC_VERSION;
        #endif
        #ifdef _SC_V6_ILP32_OFF32
        defaultNames[75] = _SC_V6_ILP32_OFF32;
        #endif
        #ifdef _SC_V6_ILP32_OFFBIG
        defaultNames[76] = _SC_V6_ILP32_OFFBIG;
        #endif
        #ifdef _SC_V6_LP64_OFF64
        defaultNames[77] = _SC_V6_LP64_OFF64;
        #endif
        #ifdef _SC_V6_LPBIG_OFFBIG
        defaultNames[78] = _SC_V6_LPBIG_OFFBIG;
        #endif
        #ifdef _SC_2_C_BIND
        defaultNames[79] = _SC_2_C_BIND;
        #endif
        #ifdef _SC_2_C_DEV
        defaultNames[80] = _SC_2_C_DEV;
        #endif
        #ifdef _SC_2_CHAR_TERM
        defaultNames[81] = _SC_2_CHAR_TERM;
        #endif
        #ifdef _SC_2_FORT_DEV
        defaultNames[82] = _SC_2_FORT_DEV;
        #endif
        #ifdef _SC_2_FORT_RUN
        defaultNames[83] = _SC_2_FORT_RUN;
        #endif
        #ifdef _SC_2_LOCALEDEF
        defaultNames[84] = _SC_2_LOCALEDEF;
        #endif
        #ifdef _SC_2_PBS
        defaultNames[85] = _SC_2_PBS;
        #endif
        #ifdef _SC_2_PBS_ACCOUNTING
        defaultNames[86] = _SC_2_PBS_ACCOUNTING;
        #endif
        #ifdef _SC_2_PBS_CHECKPOINT
        defaultNames[87] = _SC_2_PBS_CHECKPOINT;
        #endif
        #ifdef _SC_2_PBS_LOCATE
        defaultNames[88] = _SC_2_PBS_LOCATE;
        #endif
        #ifdef _SC_2_PBS_MESSAGE
        defaultNames[89] = _SC_2_PBS_MESSAGE;
        #endif
        #ifdef _SC_2_PBS_TRACK
        defaultNames[90] = _SC_2_PBS_TRACK;
        #endif
        #ifdef _SC_2_SW_DEV
        defaultNames[91] = _SC_2_SW_DEV;
        #endif
        #ifdef _SC_2_UPE
        defaultNames[92] = _SC_2_UPE;
        #endif
        #ifdef _SC_2_VERSION
        defaultNames[93] = _SC_2_VERSION;
        #endif
        #ifdef _SC_PAGE_SIZE
        defaultNames[94] = _SC_PAGE_SIZE;
        #endif
        #ifdef _SC_PAGESIZE
        defaultNames[95] = _SC_PAGESIZE;
        #endif
        #ifdef _SC_THREAD_DESTRUCTOR_ITERATIONS
        defaultNames[96] = _SC_THREAD_DESTRUCTOR_ITERATIONS;
        #endif
        #ifdef _SC_THREAD_KEYS_MAX
        defaultNames[97] = _SC_THREAD_KEYS_MAX;
        #endif
        #ifdef _SC_THREAD_STACK_MIN
        defaultNames[98] = _SC_THREAD_STACK_MIN;
        #endif
        #ifdef _SC_THREAD_THREADS_MAX
        defaultNames[99] = _SC_THREAD_THREADS_MAX;
        #endif
        #ifdef _SC_RE_DUP_MAX
        defaultNames[100] = _SC_RE_DUP_MAX;
        #endif
        #ifdef _SC_RTSIG_MAX
        defaultNames[101] = _SC_RTSIG_MAX;
        #endif
        #ifdef _SC_SEM_NSEMS_MAX
        defaultNames[102] = _SC_SEM_NSEMS_MAX;
        #endif
        #ifdef _SC_SEM_VALUE_MAX
        defaultNames[103] = _SC_SEM_VALUE_MAX;
        #endif
        #ifdef _SC_SIGQUEUE_MAX
        defaultNames[104] = _SC_SIGQUEUE_MAX;
        #endif
        #ifdef _SC_STREAM_MAX
        defaultNames[105] = _SC_STREAM_MAX;
        #endif
        #ifdef _SC_SYMLOOP_MAX
        defaultNames[106] = _SC_SYMLOOP_MAX;
        #endif
        #ifdef _SC_TIMER_MAX
        defaultNames[107] = _SC_TIMER_MAX;
        #endif
        #ifdef _SC_TTY_NAME_MAX
        defaultNames[108] = _SC_TTY_NAME_MAX;
        #endif
        #ifdef _SC_TZNAME_MAX
        defaultNames[109] = _SC_TZNAME_MAX;
        #endif
        #ifdef _SC_XBS5_ILP32_OFF32
        defaultNames[110] = _SC_XBS5_ILP32_OFF32;
        #endif
        #ifdef _SC_XBS5_ILP32_OFFBIG
        defaultNames[111] = _SC_XBS5_ILP32_OFFBIG;
        #endif
        #ifdef _SC_XBS5_LP64_OFF64
        defaultNames[112] = _SC_XBS5_LP64_OFF64;
        #endif
        #ifdef _SC_XBS5_LPBIG_OFFBIG
        defaultNames[113] = _SC_XBS5_LPBIG_OFFBIG;
        #endif
        #ifdef _SC_XOPEN_CRYPT
        defaultNames[114] = _SC_XOPEN_CRYPT;
        #endif
        #ifdef _SC_XOPEN_ENH_I18N
        defaultNames[115] = _SC_XOPEN_ENH_I18N;
        #endif
        #ifdef _SC_XOPEN_LEGACY
        defaultNames[116] = _SC_XOPEN_LEGACY;
        #endif
        #ifdef _SC_XOPEN_REALTIME
        defaultNames[117] = _SC_XOPEN_REALTIME;
        #endif
        #ifdef _SC_XOPEN_REALTIME_THREADS
        defaultNames[118] = _SC_XOPEN_REALTIME_THREADS;
        #endif
        #ifdef _SC_XOPEN_SHM
        defaultNames[119] = _SC_XOPEN_SHM;
        #endif
        #ifdef _SC_XOPEN_STREAMS
        defaultNames[120] = _SC_XOPEN_STREAMS;
        #endif
        #ifdef _SC_XOPEN_UNIX
        defaultNames[121] = _SC_XOPEN_UNIX;
        #endif
        #ifdef _SC_XOPEN_VERSION
        defaultNames[122] = _SC_XOPEN_VERSION;
        #endif
        #ifdef _SC_NPROCESSORS_CONF
        defaultNames[123] = _SC_NPROCESSORS_CONF;
        #endif
        #ifdef _SC_NPROCESSORS_ONLN
        defaultNames[124] = _SC_NPROCESSORS_ONLN;
        #endif
        #ifdef _SC_PHYS_PAGES
        defaultNames[125] = _SC_PHYS_PAGES;
        #endif
        #ifdef _SC_AVPHYS_PAGES
        defaultNames[126] = _SC_AVPHYS_PAGES;
        #endif
        napi_property_descriptor allDesc[] = {
                {"get", 0, get, 0, 0, 0, napi_default, 0}
        };
        napi_define_properties(env, exports, 1, allDesc);
        return exports;
}

NAPI_MODULE(crc, Init);
