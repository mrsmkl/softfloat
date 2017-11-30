
#include <stdbool.h>
#include <stdint.h>
#include "platform.h"
#include "internals.h"
#include "softfloat.h"

float64_t f64_neg(float64_t a) {
   float64_t minusone = i32_to_f64(-1);
   return f64_mul(minusone, a);
}

float64_t f64_abs(float64_t a) {
   float64_t zero = i32_to_f64(0);
   if (f64_lt(a, zero)) return f64_neg(a);
   else return a;
}

float32_t f32_neg(float32_t a) {
   float32_t minusone = i32_to_f32(-1);
   return f32_mul(minusone, a);
}

float32_t f32_abs(float32_t a) {
   float32_t zero = i32_to_f32(0);
   if (f32_lt(a, zero)) return f32_neg(a);
   else return a;
}

