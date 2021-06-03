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

#[neon::main]
fn main(mut cx: ModuleContext) -> NeonResult<()> {
    cx.export_function("get", get)?;
    Ok(())
}
