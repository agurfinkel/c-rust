#![no_std]

use sea;

use core::fmt::{self, Arguments};

struct NullWriter;

impl NullWriter {
    pub fn write_fmt(&mut self, _: Arguments<'_>) -> fmt::Result { Ok(()) }
}

custom_print::define_macros!(
    {cprint, cprintln, ceprint, ceprintln},
    NullWriter
);

macro_rules! print { ($($args:tt)*) => { cprint!($($args)*); } }
macro_rules! println { ($($args:tt)*) => { cprintln!($($args)*); } }
macro_rules! eprint { ($($args:tt)*) => { ceprint!($($args)*); } }
macro_rules! eprintln { ($($args:tt)*) => { ceprintln!($($args)*); } }

#[no_mangle]
pub extern "C" fn entrypt() {
    let v: i32 = sea::nd_i32();
    sea::assume(v >= 1);
    let result: i32 = v * 2;

    print!("test");
    println!("test");
    print!("test {}", 42);
    println!("test {}", 42);
    eprint!("test");
    eprintln!("test");
    eprint!("test {}", 42);
    eprintln!("test {}", 42);

    sea::sassert!(result > v);
}
