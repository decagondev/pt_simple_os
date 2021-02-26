#![crate_type = "staticlib"]
// use std::primitive::char; removed as u8 works fine for a char

#[no_mangle]
fn output_char() -> u8 { // changed to u8 to stop warnings and also to clean up the types
    'X' as u8
}