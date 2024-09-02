
#include <stdbool.h>
#include <stdint.h>
#include "platform.h"
#include "internals.h"
#include "softfloat.h"

bool is_nan64(float64_t a) {
   if (f64_eq(a,a)) return false;
   else return true;
}

bool is_nan32(float32_t a) {
   if (f32_eq(a,a)) return false;
   else return true;
}

float64_t f64_max(float64_t a, float64_t b) {
   if (is_nan64(a)) return a;
   if (is_nan64(b)) return b;
   if (f64_le(a,b)) return b;
   else return a;
}

float64_t f64_min(float64_t a, float64_t b) {
   if (is_nan64(a)) return a;
   if (is_nan64(b)) return b;
   if (f64_le(a,b)) return a;
   else return b;
}

bool f32_isReal(float32_t f) {
	uint32_t exponentMask = (1u << 31) - (1u << 23);
	return (f.v & exponentMask) != exponentMask;
}

bool f32_isNaN(float32_t f) {
	if (f32_isReal(f)) return false;
	uint32_t fraction = f.v & ((1 << 23) - 1);
	return fraction != 0;
}

bool f32_isInfinity(float32_t f) {
	if (f32_isReal(f)) return false;
	uint32_t fraction = f.v & ((1 << 23) - 1);
	return fraction == 0;
}

bool f32_isNegative(float32_t f) {
	return f.v & (1u << 31);
}

bool f32_isZero(float32_t f) {
	return (f.v & ~(1u << 31)) == 0;
}

float32_t f32_max(float32_t a, float32_t b) {
   if (f32_isNaN(a)) {
		return a;
	} else if (f32_isNaN(b)) {
		return b;
	} else if (f32_isInfinity(a) && !f32_isNegative(a)) {
		return a;
	} else if (f32_isInfinity(b) && !f32_isNegative(b)) {
		return b;
	} else if (f32_isInfinity(a) && f32_isNegative(a)) {
		return b;
	} else if (f32_isInfinity(b) && f32_isNegative(b)) {
		return a;
	} else if (f32_isZero(a) && f32_isZero(b) && (f32_isNegative(a) != f32_isNegative(b))) {
		return f32_positiveZero();
	} else {
		if (f32_lt(a, b)) {
			return b;
		} else {
			return a;
		}
	}
   /*
   if (is_nan32(a)) return a;
   if (is_nan32(b)) return b;
   if (f32_le(a,b)) return b;
   else return a;
   */
}

float32_t f32_min(float32_t a, float32_t b) {
	if (f32_isNaN(a)) {
		return a;
	} else if (f32_isNaN(b)) {
		return b;
	} else if (f32_isInfinity(a) && f32_isNegative(a)) {
		return a;
	} else if (f32_isInfinity(b) && f32_isNegative(b)) {
		return b;
	} else if (f32_isInfinity(a) && !f32_isNegative(a)) {
		return b;
	} else if (f32_isInfinity(b) && !f32_isNegative(b)) {
		return a;
	} else if (f32_isZero(a) && f32_isZero(b) && (f32_isNegative(a) != f32_isNegative(b))) {
		return f32_negativeZero();
	} else {
		if (f32_lt(b, a)) {
			return b;
		} else {
			return a;
		}
	}
   /*
   if (is_nan32(a)) return a;
   if (is_nan32(b)) return b;
   if (f32_le(a,b)) return a;
   else return b;
   */
}

