extern crate libc;
extern crate neon;

use neon::prelude::*;

fn get(mut cx: FunctionContext) -> JsResult<JsValue> {
    let value = cx.argument::<JsNumber>(0)?.value(&mut cx);

    if value.is_infinite() || value.is_nan() || value.fract() > f64::EPSILON {
        return cx.throw_type_error(format!("{} is not an integer", value));
    }

    let value = value as i64;

    if value > u8::MAX as i64 {
        cx.throw_range_error(format!("{} is bigger than {}", value, u8::MAX))
    } else if value < u8::MIN as i64 {
        cx.throw_range_error(format!("{} is smaller than {}", value, u8::MIN))
    } else {
        let result = unsafe { libc::sysconf(value as libc::c_int) };

        if result == -1 {
            Ok(JsUndefined::new(&mut cx).upcast())
        } else {
            Ok(JsNumber::new(&mut cx, result as f64).upcast())
        }
    }
}

macro_rules! export_const {
    (@inner $cx:expr, $key:expr, $number:expr) => {
        {
            let v = JsNumber::new(&mut $cx, $number as f64);
            $cx.export_value($key, v)?;
        }
    };
    ($cx:expr; $($key:expr => $number:expr),+ $(,)*) => {
        $(
            export_const!(@inner $cx, $key, $number);
        )+
    };
}

#[neon::main]
fn main(mut cx: ModuleContext) -> NeonResult<()> {
    cx.export_function("get", get)?;

    export_const! {
        cx;
        "_SC_ARG_MAX" => libc::_SC_ARG_MAX,
        "_SC_CHILD_MAX" => libc::_SC_CHILD_MAX,
        "_SC_HOST_NAME_MAX" => libc::_SC_HOST_NAME_MAX,
        "_SC_LOGIN_NAME_MAX" => libc::_SC_LOGIN_NAME_MAX,
        "_SC_NGROUPS_MAX" => libc::_SC_NGROUPS_MAX,
        "_SC_CLK_TCK" => libc::_SC_CLK_TCK,
        "_SC_OPEN_MAX" => libc::_SC_OPEN_MAX,
        "_SC_PAGESIZE" => libc::_SC_PAGESIZE,
        "_SC_PAGE_SIZE" => libc::_SC_PAGE_SIZE,
        "_SC_RE_DUP_MAX" => libc::_SC_RE_DUP_MAX,
        "_SC_STREAM_MAX" => libc::_SC_STREAM_MAX,
        "_SC_SYMLOOP_MAX" => libc::_SC_SYMLOOP_MAX,
        "_SC_TTY_NAME_MAX" => libc::_SC_TTY_NAME_MAX,
        "_SC_TZNAME_MAX" => libc::_SC_TZNAME_MAX,
        "_SC_VERSION" => libc::_SC_VERSION,
        "_SC_BC_BASE_MAX" => libc::_SC_BC_BASE_MAX,
        "_SC_BC_DIM_MAX" => libc::_SC_BC_DIM_MAX,
        "_SC_BC_SCALE_MAX" => libc::_SC_BC_SCALE_MAX,
        "_SC_BC_STRING_MAX" => libc::_SC_BC_STRING_MAX,
        "_SC_COLL_WEIGHTS_MAX" => libc::_SC_COLL_WEIGHTS_MAX,
        "_SC_EXPR_NEST_MAX" => libc::_SC_EXPR_NEST_MAX,
        "_SC_LINE_MAX" => libc::_SC_LINE_MAX,
        "_SC_2_VERSION" => libc::_SC_2_VERSION,
        "_SC_2_C_DEV" => libc::_SC_2_C_DEV,
        "_SC_2_FORT_DEV" => libc::_SC_2_FORT_DEV,
        "_SC_2_FORT_RUN" => libc::_SC_2_FORT_RUN,
        "_SC_2_LOCALEDEF" => libc::_SC_2_LOCALEDEF,
        "_SC_2_SW_DEV" => libc::_SC_2_SW_DEV,
        "_SC_PHYS_PAGES" => libc::_SC_PHYS_PAGES,
        "_SC_AVPHYS_PAGES" => libc::_SC_AVPHYS_PAGES,
        "_SC_NPROCESSORS_CONF" => libc::_SC_NPROCESSORS_CONF,
        "_SC_NPROCESSORS_ONLN" => libc::_SC_NPROCESSORS_ONLN,
    };

    Ok(())
}
