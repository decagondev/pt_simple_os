#![crate_type = "staticlib"]
use std::primitive::char;

#[no_mangle]
fn output_char() -> std::primitive::char {
    'G' as std::primitive::char
}