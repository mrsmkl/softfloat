
#include <stdbool.h>
#include <stdint.h>
#include "platform.h"
#include "internals.h"
#include "softfloat.h"

float64_t f64_max(float64_t a, float64_t b) {
   if (f64_le(a,b)) return b;
   else return a;
}

float64_t f64_min(float64_t a, float64_t b) {
   if (f64_le(a,b)) return a;
   else return b;
}

float32_t f32_max(float32_t a, float32_t b) {
   if (f32_le(a,b)) return b;
   else return a;
}

float32_t f32_min(float32_t a, float32_t b) {
   if (f32_le(a,b)) return a;
   else return b;
}

