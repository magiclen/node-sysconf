use napi_derive::napi;

#[allow(non_camel_case_types)]
pub type number = libc::c_int;

#[napi(ts_return_type = "number")]
pub fn sysconf(value: u8) -> libc::c_long {
    unsafe { libc::sysconf(value as libc::c_int) }
}

macro_rules! export_const {
    (@inner $name:ident) => {
        #[napi]
        pub const $name: number = libc::$name;
    };
    (@inner $name:ident, $value:expr) => {
        #[napi]
        pub const $name: number = $value;
    };
    ($($name:ident $(=> $value:expr)?),+ $(,)*) => {
        $(
            export_const!(@inner $name $(, $value)?);
        )+
    };
}

// https://pubs.opengroup.org/onlinepubs/9699919799/functions/sysconf.html
// https://man7.org/linux/man-pages/man3/sysconf.3.html
export_const! {
    _SC_AIO_LISTIO_MAX,
    _SC_AIO_MAX,
    _SC_AIO_PRIO_DELTA_MAX,
    _SC_ATEXIT_MAX,
    _SC_BC_BASE_MAX,
    _SC_BC_DIM_MAX,
    _SC_BC_SCALE_MAX,
    _SC_BC_STRING_MAX,
    _SC_CHILD_MAX,
    _SC_CLK_TCK,
    _SC_COLL_WEIGHTS_MAX,
    _SC_DELAYTIMER_MAX,
    _SC_EXPR_NEST_MAX,
    _SC_HOST_NAME_MAX,
    _SC_IOV_MAX,
    _SC_LINE_MAX,
    _SC_LOGIN_NAME_MAX,
    _SC_NGROUPS_MAX,
    _SC_GETGR_R_SIZE_MAX,
    _SC_GETPW_R_SIZE_MAX,
    _SC_MQ_OPEN_MAX,
    _SC_MQ_PRIO_MAX,
    _SC_OPEN_MAX,
    _SC_PAGE_SIZE,
    _SC_PAGESIZE,
    _SC_THREAD_DESTRUCTOR_ITERATIONS,
    _SC_THREAD_KEYS_MAX,
    _SC_THREAD_STACK_MIN,
    _SC_THREAD_THREADS_MAX,
    _SC_RE_DUP_MAX,
    _SC_RTSIG_MAX,
    _SC_SEM_NSEMS_MAX,
    _SC_SEM_VALUE_MAX,
    _SC_SIGQUEUE_MAX,
    _SC_STREAM_MAX,
    _SC_SYMLOOP_MAX,
    _SC_TIMER_MAX,
    _SC_TTY_NAME_MAX,
    _SC_TZNAME_MAX,
    _SC_ADVISORY_INFO,
    _SC_BARRIERS,
    _SC_ASYNCHRONOUS_IO,
    _SC_CLOCK_SELECTION,
    _SC_CPUTIME,
    _SC_FSYNC,
    _SC_IPV6,
    _SC_JOB_CONTROL,
    _SC_MAPPED_FILES,
    _SC_MEMLOCK,
    _SC_MEMLOCK_RANGE,
    _SC_MEMORY_PROTECTION,
    _SC_MESSAGE_PASSING,
    _SC_MONOTONIC_CLOCK,
    _SC_PRIORITIZED_IO,
    _SC_PRIORITY_SCHEDULING,
    _SC_RAW_SOCKETS,
    _SC_READER_WRITER_LOCKS,
    _SC_REGEXP,
    _SC_SAVED_IDS,
    _SC_SEMAPHORES,
    _SC_SHARED_MEMORY_OBJECTS,
    _SC_SHELL,
    _SC_SPIN_LOCKS,
    _SC_SPORADIC_SERVER,
    _SC_SS_REPL_MAX,
    _SC_SYNCHRONIZED_IO,
    _SC_THREAD_ATTR_STACKADDR,
    _SC_THREAD_ATTR_STACKSIZE,
    _SC_THREAD_CPUTIME,
    _SC_THREAD_PRIO_INHERIT,
    _SC_THREAD_PRIO_PROTECT,
    _SC_THREAD_PRIORITY_SCHEDULING,
    _SC_THREAD_PROCESS_SHARED,
    _SC_THREAD_SAFE_FUNCTIONS,
    _SC_THREAD_SPORADIC_SERVER,
    _SC_THREADS,
    _SC_TIMEOUTS,
    _SC_TIMERS,
    _SC_TRACE,
    _SC_TRACE_EVENT_FILTER,
    _SC_TRACE_EVENT_NAME_MAX,
    _SC_TRACE_INHERIT,
    _SC_TRACE_LOG,
    _SC_TRACE_NAME_MAX,
    _SC_TRACE_SYS_MAX,
    _SC_TRACE_USER_EVENT_MAX,
    _SC_TYPED_MEMORY_OBJECTS,
    _SC_VERSION,
    _SC_V6_ILP32_OFF32,
    _SC_V6_ILP32_OFFBIG,
    _SC_V6_LP64_OFF64,
    _SC_V6_LPBIG_OFFBIG,
    _SC_2_C_BIND,
    _SC_2_C_DEV,
    _SC_2_CHAR_TERM,
    _SC_2_FORT_DEV,
    _SC_2_FORT_RUN,
    _SC_2_LOCALEDEF,
    _SC_2_PBS,
    _SC_2_PBS_ACCOUNTING,
    _SC_2_PBS_CHECKPOINT,
    _SC_2_PBS_LOCATE,
    _SC_2_PBS_MESSAGE,
    _SC_2_PBS_TRACK,
    _SC_2_SW_DEV,
    _SC_2_UPE,
    _SC_2_VERSION,
    _SC_XOPEN_CRYPT,
    _SC_XOPEN_ENH_I18N,
    _SC_XOPEN_REALTIME,
    _SC_XOPEN_REALTIME_THREADS,
    _SC_XOPEN_SHM,
    _SC_XOPEN_STREAMS,
    _SC_XOPEN_UNIX,
    // _SC_XOPEN_UUCP,
    _SC_XOPEN_VERSION,
}

#[cfg(all(unix, not(target_os = "macos")))]
export_const! {
    _SC_THREAD_ROBUST_PRIO_INHERIT,
    _SC_THREAD_ROBUST_PRIO_PROTECT,
    _SC_V7_ILP32_OFF32,
    _SC_V7_ILP32_OFFBIG,
    _SC_V7_LP64_OFF64,
    _SC_V7_LPBIG_OFFBIG,
}

#[cfg(target_os = "macos")]
export_const! {
    _SC_THREAD_ROBUST_PRIO_INHERIT => -1,
    _SC_THREAD_ROBUST_PRIO_PROTECT => -1,
    _SC_V7_ILP32_OFF32 => -1,
    _SC_V7_ILP32_OFFBIG => -1,
    _SC_V7_LP64_OFF64 => -1,
    _SC_V7_LPBIG_OFFBIG => -1,
}

// -----

#[cfg(target_os = "linux")]
export_const! {
    _SC_PHYS_PAGES,
    _SC_AVPHYS_PAGES,
    _SC_NPROCESSORS_CONF,
    _SC_NPROCESSORS_ONLN,
}

#[cfg(target_os = "macos")]
export_const! {
    _SC_PHYS_PAGES => libc::_SC_PHYS_PAGES,
    _SC_AVPHYS_PAGES => -1,
    _SC_NPROCESSORS_CONF => libc::_SC_NPROCESSORS_CONF,
    _SC_NPROCESSORS_ONLN => libc::_SC_NPROCESSORS_ONLN,
}
