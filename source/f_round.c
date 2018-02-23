

#include <stdbool.h>
#include <stdint.h>
#include "platform.h"
#include "internals.h"
#include "softfloat.h"

float64_t f64_floor(float64_t a) {
   float64_t one = i32_to_f64(1);
   float64_t zero = i32_to_f64(0);
   float64_t r = f64_rem(a, one);
   if (f64_lt(r, zero)) r = f64_add(one, r);
   return f64_sub(a, r);
}

float64_t f64_ceil(float64_t a) {
   float64_t one = i32_to_f64(1);
   float64_t zero = i32_to_f64(0);
   float64_t r = f64_rem(a, one);
   if (f64_le(r, zero)) r = f64_add(one, r);
   return f64_add(a, f64_sub(one, r));
}

float64_t f64_trunc(float64_t a) {
   float64_t zero = i32_to_f64(0);
   if (f64_lt(a, zero)) return f64_ceil(a);
   else return f64_floor(a);
}

float64_t f64_nearest(float64_t a) {
   float64_t half = f64_div(i32_to_f64(1), i32_to_f64(2));
   return f64_floor(f64_add(a, half));
}

float32_t f32_floor(float32_t a) {
   float32_t one = i32_to_f32(1);
   float32_t zero = i32_to_f32(0);
   float32_t r = f32_rem(a, one);
   if (f32_lt(r, zero)) r = f32_add(one, r);
   return f32_sub(a, r);
}

float32_t f32_ceil(float32_t a) {
   float32_t one = i32_to_f32(1);
   float32_t zero = i32_to_f32(0);
   float32_t r = f32_rem(a, one);
   if (f32_le(r, zero)) r = f32_add(one, r);
   return f32_add(a, f32_sub(one, r));
}

float32_t f32_trunc(float32_t a) {
   float32_t zero = i32_to_f32(0);
   if (f32_lt(a, zero)) return f32_ceil(a);
   else return f32_floor(a);
}

float32_t f32_nearest(float32_t a) {
   float32_t half = f32_div(i32_to_f32(1), i32_to_f32(2));
   return f32_floor(f32_add(a, half));
}



