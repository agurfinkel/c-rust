/**
 * \brief Dummy implementation of SeaHorn verification builtins
 *
 * Dummy implementation is necessary to build Rust project with LTO.
 * The bodies of these functions are removed by SeaHorn before any
 * optimizataion and verification takes place
 */
#include "seahorn/seahorn.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h> // for free

void __VERIFIER_error(void) { return; }

void __VERIFIER_assume(int i) { return; }

void __SEA_assume(bool b) { return; }

void __VERIFIER_assert(bool pred) {}

int8_t sea_nd_i8(void) { return 0; }
uint8_t sea_nd_u8(void) { return 0;}
int16_t sea_nd_i16(void) { return 0; }
uint16_t sea_nd_u16(void) { return 0;}
int32_t sea_nd_i32(void) { return 0; }
uint32_t sea_nd_u32(void) { return 0;}
int64_t sea_nd_i64(void) { return 0; }
uint64_t sea_nd_u64(void) { return 0;}
size_t sea_nd_usize(void) { return 0; }
uintptr_t sea_nd_uintptr(void) {return 0; }

bool sea_nd_bool(void) { return true; }

void *sea_realloc(void *ptr, size_t sz) {
  if (ptr)
    free(ptr);
  return malloc(sz);
}

void *realloc(void *ptr, size_t sz) { return sea_realloc(ptr, sz); }

void sea_printf( const char* format, ... ) { return; }
