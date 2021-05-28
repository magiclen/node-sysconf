const sysconf = require("bindings")("sysconf");

sysconf._SC_AIO_LISTIO_MAX = 0;
sysconf._SC_AIO_MAX = 1;
sysconf._SC_AIO_PRIO_DELTA_MAX = 2;
sysconf._SC_ARG_MAX = 3;
sysconf._SC_ATEXIT_MAX = 4;
sysconf._SC_BC_BASE_MAX = 5;
sysconf._SC_BC_DIM_MAX = 6;
sysconf._SC_BC_SCALE_MAX = 7;
sysconf._SC_BC_STRING_MAX = 8;
sysconf._SC_CHILD_MAX = 9;
sysconf._SC_CLK_TCK = 10;
sysconf._SC_COLL_WEIGHTS_MAX = 11;
sysconf._SC_DELAYTIMER_MAX = 12;
sysconf._SC_EXPR_NEST_MAX = 13;
sysconf._SC_HOST_NAME_MAX = 14;
sysconf._SC_IOV_MAX = 15;
sysconf._SC_LINE_MAX = 16;
sysconf._SC_LOGIN_NAME_MAX = 17;
sysconf._SC_NGROUPS_MAX = 18;
sysconf._SC_GETGR_R_SIZE_MAX = 19;
sysconf._SC_GETPW_R_SIZE_MAX = 20;
sysconf._SC_MQ_OPEN_MAX = 21;
sysconf._SC_MQ_PRIO_MAX = 22;
sysconf._SC_OPEN_MAX = 23;
sysconf._SC_ADVISORY_INFO = 24;
sysconf._SC_BARRIERS = 25;
sysconf._SC_ASYNCHRONOUS_IO = 26;
sysconf._SC_CLOCK_SELECTION = 27;
sysconf._SC_CPUTIME = 28;
sysconf._SC_FSYNC = 29;
sysconf._SC_IPV6 = 30;
sysconf._SC_JOB_CONTROL = 31;
sysconf._SC_MAPPED_FILES = 32;
sysconf._SC_MEMLOCK = 33;
sysconf._SC_MEMLOCK_RANGE = 34;
sysconf._SC_MEMORY_PROTECTION = 35;
sysconf._SC_MESSAGE_PASSING = 36;
sysconf._SC_MONOTONIC_CLOCK = 37;
sysconf._SC_PRIORITIZED_IO = 38;
sysconf._SC_PRIORITY_SCHEDULING = 39;
sysconf._SC_RAW_SOCKETS = 40;
sysconf._SC_READER_WRITER_LOCKS = 41;
sysconf._SC_REALTIME_SIGNALS = 42;
sysconf._SC_REGEXP = 43;
sysconf._SC_SAVED_IDS = 44;
sysconf._SC_SEMAPHORES = 45;
sysconf._SC_SHARED_MEMORY_OBJECTS = 46;
sysconf._SC_SHELL = 47;
sysconf._SC_SPAWN = 48;
sysconf._SC_SPIN_LOCKS = 49;
sysconf._SC_SPORADIC_SERVER = 50;
sysconf._SC_SS_REPL_MAX = 51;
sysconf._SC_SYNCHRONIZED_IO = 52;
sysconf._SC_THREAD_ATTR_STACKADDR = 53;
sysconf._SC_THREAD_ATTR_STACKSIZE = 54;
sysconf._SC_THREAD_CPUTIME = 55;
sysconf._SC_THREAD_PRIO_INHERIT = 56;
sysconf._SC_THREAD_PRIO_PROTECT = 57;
sysconf._SC_THREAD_PRIORITY_SCHEDULING = 58;
sysconf._SC_THREAD_PROCESS_SHARED = 59;
sysconf._SC_THREAD_SAFE_FUNCTIONS = 60;
sysconf._SC_THREAD_SPORADIC_SERVER = 61;
sysconf._SC_THREADS = 62;
sysconf._SC_TIMEOUTS = 63;
sysconf._SC_TIMERS = 64;
sysconf._SC_TRACE = 65;
sysconf._SC_TRACE_EVENT_FILTER = 66;
sysconf._SC_TRACE_EVENT_NAME_MAX = 67;
sysconf._SC_TRACE_INHERIT = 68;
sysconf._SC_TRACE_LOG = 69;
sysconf._SC_TRACE_NAME_MAX = 70;
sysconf._SC_TRACE_SYS_MAX = 71;
sysconf._SC_TRACE_USER_EVENT_MAX = 72;
sysconf._SC_TYPED_MEMORY_OBJECTS = 73;
sysconf._SC_VERSION = 74;
sysconf._SC_V6_ILP32_OFF32 = 75;
sysconf._SC_V6_ILP32_OFFBIG = 76;
sysconf._SC_V6_LP64_OFF64 = 77;
sysconf._SC_V6_LPBIG_OFFBIG = 78;
sysconf._SC_2_C_BIND = 79;
sysconf._SC_2_C_DEV = 80;
sysconf._SC_2_CHAR_TERM = 81;
sysconf._SC_2_FORT_DEV = 82;
sysconf._SC_2_FORT_RUN = 83;
sysconf._SC_2_LOCALEDEF = 84;
sysconf._SC_2_PBS = 85;
sysconf._SC_2_PBS_ACCOUNTING = 86;
sysconf._SC_2_PBS_CHECKPOINT = 87;
sysconf._SC_2_PBS_LOCATE = 88;
sysconf._SC_2_PBS_MESSAGE = 89;
sysconf._SC_2_PBS_TRACK = 90;
sysconf._SC_2_SW_DEV = 91;
sysconf._SC_2_UPE = 92;
sysconf._SC_2_VERSION = 93;
sysconf._SC_PAGE_SIZE = 94;
sysconf._SC_PAGESIZE = 95;
sysconf._SC_THREAD_DESTRUCTOR_ITERATIONS = 96;
sysconf._SC_THREAD_KEYS_MAX = 97;
sysconf._SC_THREAD_STACK_MIN = 98;
sysconf._SC_THREAD_THREADS_MAX = 99;
sysconf._SC_RE_DUP_MAX = 100;
sysconf._SC_RTSIG_MAX = 101;
sysconf._SC_SEM_NSEMS_MAX = 102;
sysconf._SC_SEM_VALUE_MAX = 103;
sysconf._SC_SIGQUEUE_MAX = 104;
sysconf._SC_STREAM_MAX = 105;
sysconf._SC_SYMLOOP_MAX = 106;
sysconf._SC_TIMER_MAX = 107;
sysconf._SC_TTY_NAME_MAX = 108;
sysconf._SC_TZNAME_MAX = 109;
sysconf._SC_XBS5_ILP32_OFF32 = 110;
sysconf._SC_XBS5_ILP32_OFFBIG = 111;
sysconf._SC_XBS5_LP64_OFF64 = 112;
sysconf._SC_XBS5_LPBIG_OFFBIG = 113;
sysconf._SC_XOPEN_CRYPT = 114;
sysconf._SC_XOPEN_ENH_I18N = 115;
sysconf._SC_XOPEN_LEGACY = 116;
sysconf._SC_XOPEN_REALTIME = 117;
sysconf._SC_XOPEN_REALTIME_THREADS = 118;
sysconf._SC_XOPEN_SHM = 119;
sysconf._SC_XOPEN_STREAMS = 120;
sysconf._SC_XOPEN_UNIX = 121;
sysconf._SC_XOPEN_VERSION = 122;
sysconf._SC_NPROCESSORS_CONF = 123;
sysconf._SC_NPROCESSORS_ONLN = 124;
sysconf._SC_PHYS_PAGES = 125;
sysconf._SC_AVPHYS_PAGES = 126;

module.exports = sysconf;