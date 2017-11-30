

#include <stdbool.h>
#include <stdint.h>
#include "platform.h"
#include "internals.h"
#include "softfloat.h"

bool f64_ne(float64_t a, float64_t b) {
   return !f64_eq(a, b);
}

bool f64_ge(float64_t a, float64_t b) {
   return f64_le(b, a);
}

bool f64_gt(float64_t a, float64_t b) {
   return f64_lt(b, a);
}

bool f32_ne(float32_t a, float32_t b) {
   return !f32_eq(a, b);
}

bool f32_ge(float32_t a, float32_t b) {
   return f32_le(b, a);
}

bool f32_gt(float32_t a, float32_t b) {
   return f32_lt(b, a);
}



