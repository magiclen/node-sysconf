const sysconf = require("../index.node");

export enum Name {
    _SC_ARG_MAX = sysconf._SC_ARG_MAX,
    _SC_CHILD_MAX = sysconf._SC_CHILD_MAX,
    _SC_HOST_NAME_MAX = sysconf._SC_HOST_NAME_MAX,
    _SC_LOGIN_NAME_MAX = sysconf._SC_LOGIN_NAME_MAX,
    _SC_NGROUPS_MAX = sysconf._SC_NGROUPS_MAX,
    _SC_CLK_TCK = sysconf._SC_CLK_TCK,
    _SC_OPEN_MAX = sysconf._SC_OPEN_MAX,
    _SC_PAGESIZE = sysconf._SC_PAGESIZE,
    _SC_PAGE_SIZE = sysconf._SC_PAGE_SIZE,
    _SC_RE_DUP_MAX = sysconf._SC_RE_DUP_MAX,
    _SC_STREAM_MAX = sysconf._SC_STREAM_MAX,
    _SC_SYMLOOP_MAX = sysconf._SC_SYMLOOP_MAX,
    _SC_TTY_NAME_MAX = sysconf._SC_TTY_NAME_MAX,
    _SC_TZNAME_MAX = sysconf._SC_TZNAME_MAX,
    _SC_VERSION = sysconf._SC_VERSION,
    _SC_BC_BASE_MAX = sysconf._SC_BC_BASE_MAX,
    _SC_BC_DIM_MAX = sysconf._SC_BC_DIM_MAX,
    _SC_BC_SCALE_MAX = sysconf._SC_BC_SCALE_MAX,
    _SC_BC_STRING_MAX = sysconf._SC_BC_STRING_MAX,
    _SC_COLL_WEIGHTS_MAX = sysconf._SC_COLL_WEIGHTS_MAX,
    _SC_EXPR_NEST_MAX = sysconf._SC_EXPR_NEST_MAX,
    _SC_LINE_MAX = sysconf._SC_LINE_MAX,
    _SC_2_VERSION = sysconf._SC_2_VERSION,
    _SC_2_C_DEV = sysconf._SC_2_C_DEV,
    _SC_2_FORT_DEV = sysconf._SC_2_FORT_DEV,
    _SC_2_FORT_RUN = sysconf._SC_2_FORT_RUN,
    _SC_2_LOCALEDEF = sysconf._SC_2_LOCALEDEF,
    _SC_2_SW_DEV = sysconf._SC_2_SW_DEV,
    _SC_PHYS_PAGES = sysconf._SC_PHYS_PAGES,
    _SC_AVPHYS_PAGES = sysconf._SC_AVPHYS_PAGES,
    _SC_NPROCESSORS_CONF = sysconf._SC_NPROCESSORS_CONF,
    _SC_NPROCESSORS_ONLN = sysconf._SC_NPROCESSORS_ONLN,
}

export const get = (name: Name | number): number | undefined => {
    return sysconf.get(name);
};
