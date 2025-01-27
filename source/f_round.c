

#include <stdbool.h>
#include <stdint.h>
#include "platform.h"
#include "internals.h"
#include "softfloat.h"

float64_t f64_floor(float64_t a) {
   return f64_roundToInt(a, softfloat_round_min, true);
}

float64_t f64_ceil(float64_t a) {
   return f64_roundToInt(a, softfloat_round_max, true);
}

float64_t f64_trunc(float64_t a) {
   return f64_roundToInt(a, softfloat_round_minMag, true);
}

float64_t f64_nearest(float64_t a) {
   return f64_roundToInt(a, softfloat_round_near_even, true);
}

float32_t f32_floor(float32_t a) {
   return f32_roundToInt(a, softfloat_round_min, true);
}

float32_t f32_ceil(float32_t a) {
   return f32_roundToInt(a, softfloat_round_max, true);
}

float32_t f32_trunc(float32_t a) {
   return f32_roundToInt(a, softfloat_round_minMag, true);
}

float32_t f32_nearest(float32_t a) {
   return f32_roundToInt(a, softfloat_round_near_even, true);
}

bool f64_isNaN(float64_t f);
bool f32_isNaN(float32_t f);

int_fast32_t f32_trunc_i32(float32_t a) {
   if (f32_isNaN(a)) {
      __builtin_trap();
   }
   return f32_to_i32(a, softfloat_round_minMag, true);
}

int_fast32_t f32_trunc_ui32(float32_t a) {
   if (f32_isNaN(a)) {
      __builtin_trap();
   }
   return f32_to_ui32(a, softfloat_round_minMag, true);
}

int_fast64_t f32_trunc_i64(float32_t a) {
   if (f32_isNaN(a)) {
      __builtin_trap();
   }
   return f32_to_i64(a, softfloat_round_minMag, true);
}

int_fast64_t f32_trunc_ui64(float32_t a) {
   if (f32_isNaN(a)) {
      __builtin_trap();
   }
   return f32_to_ui64(a, softfloat_round_minMag, true);
}

// some probem
int_fast32_t f64_trunc_i32(float64_t a) {
   if (f64_isNaN(a)) {
      __builtin_trap();
   }
   return f64_to_i32(a, softfloat_round_minMag, true);
}

int_fast32_t f64_trunc_ui32(float64_t a) {
   if (f64_isNaN(a)) {
      __builtin_trap();
   }
   return f64_to_ui32(a, softfloat_round_minMag, true);
}

int_fast64_t f64_trunc_i64(float64_t a) {
   if (f64_isNaN(a)) {
      __builtin_trap();
   }
   return f64_to_i64(a, softfloat_round_minMag, true);
}

int_fast64_t f64_trunc_ui64(float64_t a) {
   if (f64_isNaN(a)) {
      __builtin_trap();
   }
   return f64_to_ui64(a, softfloat_round_minMag, true);
}

float32_t f32_copysign(float32_t a, float32_t b) {
   union ui32_f32 ua, ub;
   ua.f = a; ub.f = b;
   ua.ui = (ua.ui & 0x7fffffff) | (ub.ui & 0x80000000);
   return ua.f;
}

float64_t f64_copysign(float64_t a, float64_t b) {
   union ui64_f64 ua, ub;
   ua.f = a; ub.f = b;
   ua.ui = (ua.ui & 0x7fffffffffffffff) | (ub.ui & 0x8000000000000000);
   return ua.f;
}



