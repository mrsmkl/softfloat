

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
   float32_t max = {0x4f000000};  // i32::max + 1 = 0x4F000000
	float32_t min = {0xcf000001};  // i32::min - 1 = 0xCF000000 (adjusted due to rounding)
	if (f32_isNaN(a) || f32_le(max, a) || f32_le(a, min)) {
      __builtin_trap();
   }
   return f32_to_i32(a, softfloat_round_minMag, true);
}

int_fast32_t f32_trunc_ui32(float32_t a) {
	float32_t max = {0x4f800000};  // u32::max + 1 = 0x4f800000
	float32_t min = {0xbf800000};  // -1           = 0xbf800000
	if (f32_isNaN(a) || f32_le(max, a) || f32_le(a, min)) {
      __builtin_trap();
   }
   return f32_to_ui32(a, softfloat_round_minMag, true);
}

int_fast64_t f32_trunc_i64(float32_t a) {
	float32_t max = {0x5f000000};  // i64::max + 1 = 0x5f000000
	float32_t min = {0xdf000001};  // i64::min - 1 = 0xdf000000 (adjusted due to rounding)
	if (f32_isNaN(a) || f32_le(max, a) || f32_le(a, min)) {
      __builtin_trap();
   }
   return f32_to_i64(a, softfloat_round_minMag, true);
}

int_fast64_t f32_trunc_ui64(float32_t a) {
	float32_t max = {0x5f800000};  // i64::max + 1 = 0x5f800000
	float32_t min = {0xbf800000};  // -1           = 0xbf800000
	if (f32_isNaN(a) || f32_le(max, a) || f32_le(a, min)) {
      __builtin_trap();
   }
   return f32_to_ui64(a, softfloat_round_minMag, true);
}

int_fast32_t f64_trunc_i32(float64_t a) {
	float64_t max = {0x41e0000000000000};  // i32::max + 1 = 0x41e0000000000000
	float64_t min = {0xc1e0000000200000};  // i32::min - 1 = 0xc1e0000000200000
	if (f64_isNaN(a) || f64_le(max, a) || f64_le(a, min)) {
      __builtin_trap();
   }
   return f64_to_i32(a, softfloat_round_minMag, true);
}

int_fast32_t f64_trunc_ui32(float64_t a) {
	float64_t max = {0x41f0000000000000};  // u32::max + 1 = 0x41f0000000000000
	float64_t min = {0xbff0000000000000};  // -1           = 0xbff0000000000000
	if (f64_isNaN(a) || f64_le(max, a) || f64_le(a, min)) {
      __builtin_trap();
   }
   return f64_to_ui32(a, softfloat_round_minMag, true);
}

int_fast64_t f64_trunc_i64(float64_t a) {
	float64_t max = {0x43e0000000000000};  // i64::max + 1 = 0x43e0000000000000
	float64_t min = {0xc3e0000000000001};  // i64::min - 1 = 0xc3e0000000000000 (adjusted due to rounding)
	if (f64_isNaN(a) || f64_le(max, a) || f64_le(a, min)) {
      __builtin_trap();
   }
   return f64_to_i64(a, softfloat_round_minMag, true);
}

int_fast64_t f64_trunc_ui64(float64_t a) {
	float64_t max = {0x43f0000000000000};  // u64::max + 1 = 0x43f0000000000000
	float64_t min = {0xbff0000000000000};  // -1           = 0xbff0000000000000
	if (f64_isNaN(a) || f64_le(max, a) || f64_le(a, min)) {
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

int32_t i32_trunc_sat_f32_s(float32_t val) {
	// signed truncation is defined over (i32::min - 1, i32::max + 1)
	float32_t max = {0x4f000000};  // i32::max + 1 = 0x4F000000
	float32_t min = {0xcf000001};  // i32::min - 1 = 0xCF000000 (adjusted due to rounding)
	if (f32_isNaN(val)) {
		return 0;
	}
	if (f32_le(max, val)) {
		return 2147483647;
	}
	if (f32_le(val, min)) {
		return -2147483648;
	}
	return f32_to_i32(val, softfloat_round_minMag, true);
}

bool f32_isNegative(float32_t f);
bool f64_isNegative(float64_t f);

uint32_t i32_trunc_sat_f32_u(float32_t val) {
	// unsigned truncation is defined over (-1, u32::max + 1)
	float32_t max = {0x4f800000};  // u32::max + 1 = 0x4f800000
	if (f32_isNaN(val) || f32_isNegative(val)) {
		return 0;
	}
	if (f32_le(max, val)) {
		return ~0u;
	}
	return f32_to_ui32(val, softfloat_round_minMag, true);
}

int64_t i64_trunc_sat_f32_s(float32_t val) {
	// unsigned truncation is defined over (i64::min - 1, i64::max + 1)
	float32_t max = {0x5f000000};  // i64::max + 1 = 0x5f000000
	float32_t min = {0xdf000001};  // i64::min - 1 = 0xdf000000 (adjusted due to rounding)
	if (f32_isNaN(val)) {
		return 0;
	}
	if (f32_le(max, val)) {
		return 9223372036854775807ll;
	}
	if (f32_le(val, min)) {
		return -(((int64_t) 1) << 63);
	}
	return f32_to_i64(val, softfloat_round_minMag, true);
}

uint64_t i64_trunc_sat_f32_u(float32_t val) {
	// unsigned truncation is defined over (-1, i64::max + 1)
	float32_t max = {0x5f800000};  // i64::max + 1 = 0x5f800000
	if (f32_isNaN(val) || f32_isNegative(val)) {
		return 0;
	}
	if (f32_le(max, val)) {
		return ~0ull;
	}
	return f32_to_ui64(val, softfloat_round_minMag, true);
}

int32_t i32_trunc_sat_f64_s(float64_t val) {
	// signed truncation is defined over (i32::min - 1, i32::max + 1)
	float64_t max = {0x41e0000000000000};  // i32::max + 1 = 0x41e0000000000000
	float64_t min = {0xc1e0000000200000};  // i32::min - 1 = 0xc1e0000000200000
	if (f64_isNaN(val)) {
		return 0;
	}
	if (f64_le(max, val)) {
		return 2147483647;
	}
	if (f64_le(val, min)) {
		return -2147483648;
	}
	return f64_to_i32(val, softfloat_round_minMag, true);
}

uint32_t i32_trunc_sat_f64_u(float64_t val) {
	// unsigned truncation is defined over (-1, u32::max + 1)
	float64_t max = {0x41f0000000000000};  // u32::max + 1 = 0x41f0000000000000
	if (f64_isNaN(val) || f64_isNegative(val)) {
		return 0;
	}
	if (f64_le(max, val)) {
		return ~0u;
	}
	return f64_to_ui32(val, softfloat_round_minMag, true);
}

int64_t i64_trunc_sat_f64_s(float64_t val) {
	// signed truncation is defined over (i64::min - 1, u64::max + 1)
	float64_t max = {0x43e0000000000000};  // i64::max + 1 = 0x43e0000000000000
	float64_t min = {0xc3e0000000000001};  // i64::min - 1 = 0xc3e0000000000000 (adjusted due to rounding)
	if (f64_isNaN(val)) {
		return 0;
	}
	if (f64_le(max, val)) {
		return 9223372036854775807ll;
	}
	if (f64_le(val, min)) {
		return -(((int64_t) 1) << 63);
	}
	return f64_to_i64(val, softfloat_round_minMag, true);
}

uint64_t i64_trunc_sat_f64_u(float64_t val) {
	// unsigned truncation is defined over (-1, u64::max + 1)
	float64_t max = {0x43f0000000000000};  // u64::max + 1 = 0x43f0000000000000
	if (f64_isNaN(val) || f64_isNegative(val)) {
		return 0;
	}
	if (f64_le(max, val)) {
		return 18446744073709551615ull;
	}
	return f64_to_ui64(val, softfloat_round_minMag, true);
}

