#=============================================================================
#
# This Makefile is part of the SoftFloat IEEE Floating-Point Arithmetic
# Package, Release 3d, by John R. Hauser.
#
# Copyright 2011, 2012, 2013, 2014, 2015, 2016, 2017 The Regents of the
# University of California.  All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#  1. Redistributions of source code must retain the above copyright notice,
#     this list of conditions, and the following disclaimer.
#
#  2. Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions, and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#
#  3. Neither the name of the University nor the names of its contributors
#     may be used to endorse or promote products derived from this software
#     without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS "AS IS", AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ARE
# DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
# DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#=============================================================================

SOURCE_DIR ?= ../../source
SPECIALIZE_TYPE ?= 8086-SSE

SOFTFLOAT_OPTS ?= \
  -DSOFTFLOAT_ROUND_ODD -DINLINE_LEVEL=5 -DSOFTFLOAT_FAST_DIV32TO16 \
  -DSOFTFLOAT_FAST_DIV64TO32

DELETE = rm -f
C_INCLUDES = -I. -I$(SOURCE_DIR)/$(SPECIALIZE_TYPE) -I$(SOURCE_DIR)/include
COMPILE_C = \
  emcc -c -Werror-implicit-function-declaration -DSOFTFLOAT_FAST_INT64 \
    $(SOFTFLOAT_OPTS) $(C_INCLUDES) -O2 -o $@
MAKELIB = echo emar crs $@

OBJ = .o
LIB = .a

FUNCS = "['_f32_mul', '_f32_add', '_f32_eq', '_f32_to_ui32', '_f32_to_ui64', '_f32_to_i32', '_f32_to_i64', '_f32_to_f64', '_f32_sub', '_f32_div', '_f32_rem', '_f32_le', '_f32_sqrt', '_f32_lt', \
  '_f64_mul', '_f64_add', '_f64_eq', '_f64_to_ui32', '_f64_to_ui64', '_f64_to_i32', '_f64_to_i64', '_f64_to_f32', '_f64_sub', '_f64_div', '_f64_rem', '_f64_le', '_f64_sqrt', '_f64_lt', \
  '_f64_min', '_f64_max', '_f32_min', '_f32_max', '_f64_neg', '_f64_abs', '_f32_neg', '_f32_abs', '_f64_ne', '_f64_ge', '_f64_gt', '_f32_ne', '_f32_ge', '_f32_gt', \
  '_f64_floor', '_f64_ceil', '_f64_trunc', '_f64_nearest', \
  '_f32_floor', '_f32_ceil', '_f32_trunc', '_f32_nearest', \
  '_f32_trunc_i32', \
  '_f32_trunc_ui32', \
  '_f64_trunc_i32', \
  '_f64_trunc_ui32', \
  '_f32_trunc_i64', \
  '_f32_trunc_ui64', \
  '_f64_trunc_i64', \
  '_f64_trunc_ui64', \
  '_f64_copysign', \
  '_f32_copysign', \
  '_ui32_to_f32', '_i32_to_f32', '_ui64_to_f32', '_i64_to_f32', \
  '_ui64_to_f64', '_ui32_to_f64', '_i32_to_f64', '_i64_to_f64', '_i64_to_f64']"

# LINK = emcc -o $@ -s EXPORTED_FUNCTIONS=${FUNCS} --closure=0 -s SIDE_MODULE=2 -s LEGACY_VM_SUPPORT
LINK = wasm-ld -o softfloat.wasm   --no-entry --export-dynamic

.PHONY: all
all: softfloat$(LIB) softfloat.wasm

OBJS_PRIMITIVES = \
  s_eq128$(OBJ) \
  s_le128$(OBJ) \
  s_lt128$(OBJ) \
  s_shortShiftLeft128$(OBJ) \
  s_shortShiftRight128$(OBJ) \
  s_shortShiftRightJam64$(OBJ) \
  s_shortShiftRightJam64Extra$(OBJ) \
  s_shortShiftRightJam128$(OBJ) \
  s_shortShiftRightJam128Extra$(OBJ) \
  s_shiftRightJam32$(OBJ) \
  s_shiftRightJam64$(OBJ) \
  s_shiftRightJam64Extra$(OBJ) \
  s_shiftRightJam128$(OBJ) \
  s_shiftRightJam128Extra$(OBJ) \
  s_shiftRightJam256M$(OBJ) \
  s_countLeadingZeros8$(OBJ) \
  s_countLeadingZeros16$(OBJ) \
  s_countLeadingZeros32$(OBJ) \
  s_countLeadingZeros64$(OBJ) \
  s_add128$(OBJ) \
  s_add256M$(OBJ) \
  s_sub128$(OBJ) \
  s_sub256M$(OBJ) \
  s_mul64ByShifted32To128$(OBJ) \
  s_mul64To128$(OBJ) \
  s_mul128By32$(OBJ) \
  s_mul128To256M$(OBJ) \
  s_approxRecip_1Ks$(OBJ) \
  s_approxRecip32_1$(OBJ) \
  s_approxRecipSqrt_1Ks$(OBJ) \
  s_approxRecipSqrt32_1$(OBJ) \

OBJS_SPECIALIZE = \
  softfloat_raiseFlags$(OBJ) \
  s_f16UIToCommonNaN$(OBJ) \
  s_commonNaNToF16UI$(OBJ) \
  s_propagateNaNF16UI$(OBJ) \
  s_f32UIToCommonNaN$(OBJ) \
  s_commonNaNToF32UI$(OBJ) \
  s_propagateNaNF32UI$(OBJ) \
  s_f64UIToCommonNaN$(OBJ) \
  s_commonNaNToF64UI$(OBJ) \
  s_propagateNaNF64UI$(OBJ) \
  extF80M_isSignalingNaN$(OBJ) \
  s_extF80UIToCommonNaN$(OBJ) \
  s_commonNaNToExtF80UI$(OBJ) \
  s_propagateNaNExtF80UI$(OBJ) \
  f128M_isSignalingNaN$(OBJ) \
  s_f128UIToCommonNaN$(OBJ) \
  s_commonNaNToF128UI$(OBJ) \
  s_propagateNaNF128UI$(OBJ) \

OBJS_OTHERS = \
  s_roundToUI32$(OBJ) \
  s_roundToUI64$(OBJ) \
  s_roundToI32$(OBJ) \
  s_roundToI64$(OBJ) \
  s_normSubnormalF16Sig$(OBJ) \
  s_roundPackToF16$(OBJ) \
  s_normRoundPackToF16$(OBJ) \
  s_addMagsF16$(OBJ) \
  s_subMagsF16$(OBJ) \
  s_mulAddF16$(OBJ) \
  s_normSubnormalF32Sig$(OBJ) \
  s_roundPackToF32$(OBJ) \
  s_normRoundPackToF32$(OBJ) \
  s_addMagsF32$(OBJ) \
  s_subMagsF32$(OBJ) \
  s_mulAddF32$(OBJ) \
  s_normSubnormalF64Sig$(OBJ) \
  s_roundPackToF64$(OBJ) \
  s_normRoundPackToF64$(OBJ) \
  s_addMagsF64$(OBJ) \
  s_subMagsF64$(OBJ) \
  s_mulAddF64$(OBJ) \
  s_normSubnormalExtF80Sig$(OBJ) \
  s_roundPackToExtF80$(OBJ) \
  s_normRoundPackToExtF80$(OBJ) \
  s_addMagsExtF80$(OBJ) \
  s_subMagsExtF80$(OBJ) \
  s_normSubnormalF128Sig$(OBJ) \
  s_roundPackToF128$(OBJ) \
  s_normRoundPackToF128$(OBJ) \
  s_addMagsF128$(OBJ) \
  s_subMagsF128$(OBJ) \
  s_mulAddF128$(OBJ) \
  softfloat_state$(OBJ) \
  ui32_to_f16$(OBJ) \
  ui32_to_f32$(OBJ) \
  ui32_to_f64$(OBJ) \
  ui32_to_extF80$(OBJ) \
  ui32_to_extF80M$(OBJ) \
  ui32_to_f128$(OBJ) \
  ui32_to_f128M$(OBJ) \
  ui64_to_f16$(OBJ) \
  ui64_to_f32$(OBJ) \
  ui64_to_f64$(OBJ) \
  ui64_to_extF80$(OBJ) \
  ui64_to_extF80M$(OBJ) \
  ui64_to_f128$(OBJ) \
  ui64_to_f128M$(OBJ) \
  i32_to_f16$(OBJ) \
  i32_to_f32$(OBJ) \
  i32_to_f64$(OBJ) \
  i32_to_extF80$(OBJ) \
  i32_to_extF80M$(OBJ) \
  i32_to_f128$(OBJ) \
  i32_to_f128M$(OBJ) \
  i64_to_f16$(OBJ) \
  i64_to_f32$(OBJ) \
  i64_to_f64$(OBJ) \
  i64_to_extF80$(OBJ) \
  i64_to_extF80M$(OBJ) \
  i64_to_f128$(OBJ) \
  i64_to_f128M$(OBJ) \
  f16_to_ui32$(OBJ) \
  f16_to_ui64$(OBJ) \
  f16_to_i32$(OBJ) \
  f16_to_i64$(OBJ) \
  f16_to_ui32_r_minMag$(OBJ) \
  f16_to_ui64_r_minMag$(OBJ) \
  f16_to_i32_r_minMag$(OBJ) \
  f16_to_i64_r_minMag$(OBJ) \
  f16_to_f32$(OBJ) \
  f16_to_f64$(OBJ) \
  f16_to_extF80$(OBJ) \
  f16_to_extF80M$(OBJ) \
  f16_to_f128$(OBJ) \
  f16_to_f128M$(OBJ) \
  f16_roundToInt$(OBJ) \
  f16_add$(OBJ) \
  f16_sub$(OBJ) \
  f16_mul$(OBJ) \
  f16_mulAdd$(OBJ) \
  f16_div$(OBJ) \
  f16_rem$(OBJ) \
  f16_sqrt$(OBJ) \
  f16_eq$(OBJ) \
  f16_le$(OBJ) \
  f16_lt$(OBJ) \
  f16_eq_signaling$(OBJ) \
  f16_le_quiet$(OBJ) \
  f16_lt_quiet$(OBJ) \
  f16_isSignalingNaN$(OBJ) \
  f32_to_ui32$(OBJ) \
  f32_to_ui64$(OBJ) \
  f32_to_i32$(OBJ) \
  f32_to_i64$(OBJ) \
  f32_to_ui32_r_minMag$(OBJ) \
  f32_to_ui64_r_minMag$(OBJ) \
  f32_to_i32_r_minMag$(OBJ) \
  f32_to_i64_r_minMag$(OBJ) \
  f32_to_f16$(OBJ) \
  f32_to_f64$(OBJ) \
  f32_to_extF80$(OBJ) \
  f32_to_extF80M$(OBJ) \
  f32_to_f128$(OBJ) \
  f32_to_f128M$(OBJ) \
  f32_roundToInt$(OBJ) \
  f32_add$(OBJ) \
  f32_sub$(OBJ) \
  f32_mul$(OBJ) \
  f32_mulAdd$(OBJ) \
  f32_div$(OBJ) \
  f32_rem$(OBJ) \
  f32_sqrt$(OBJ) \
  f32_eq$(OBJ) \
  f32_le$(OBJ) \
  f32_lt$(OBJ) \
  f32_eq_signaling$(OBJ) \
  f32_le_quiet$(OBJ) \
  f32_lt_quiet$(OBJ) \
  f32_isSignalingNaN$(OBJ) \
  f64_to_ui32$(OBJ) \
  f64_to_ui64$(OBJ) \
  f64_to_i32$(OBJ) \
  f64_to_i64$(OBJ) \
  f64_to_ui32_r_minMag$(OBJ) \
  f64_to_ui64_r_minMag$(OBJ) \
  f64_to_i32_r_minMag$(OBJ) \
  f64_to_i64_r_minMag$(OBJ) \
  f64_to_f16$(OBJ) \
  f64_to_f32$(OBJ) \
  f64_to_extF80$(OBJ) \
  f64_to_extF80M$(OBJ) \
  f64_to_f128$(OBJ) \
  f64_to_f128M$(OBJ) \
  f64_roundToInt$(OBJ) \
  f64_add$(OBJ) \
  f64_sub$(OBJ) \
  f64_mul$(OBJ) \
  f64_mulAdd$(OBJ) \
  f64_div$(OBJ) \
  f64_rem$(OBJ) \
  f64_sqrt$(OBJ) \
  f64_eq$(OBJ) \
  f64_le$(OBJ) \
  f64_lt$(OBJ) \
  f64_eq_signaling$(OBJ) \
  f64_le_quiet$(OBJ) \
  f64_lt_quiet$(OBJ) \
  f64_isSignalingNaN$(OBJ) \
  extF80_to_ui32$(OBJ) \
  extF80_to_ui64$(OBJ) \
  extF80_to_i32$(OBJ) \
  extF80_to_i64$(OBJ) \
  extF80_to_ui32_r_minMag$(OBJ) \
  extF80_to_ui64_r_minMag$(OBJ) \
  extF80_to_i32_r_minMag$(OBJ) \
  extF80_to_i64_r_minMag$(OBJ) \
  extF80_to_f16$(OBJ) \
  extF80_to_f32$(OBJ) \
  extF80_to_f64$(OBJ) \
  extF80_to_f128$(OBJ) \
  extF80_roundToInt$(OBJ) \
  extF80_add$(OBJ) \
  extF80_sub$(OBJ) \
  extF80_mul$(OBJ) \
  extF80_div$(OBJ) \
  extF80_rem$(OBJ) \
  extF80_sqrt$(OBJ) \
  extF80_eq$(OBJ) \
  extF80_le$(OBJ) \
  extF80_lt$(OBJ) \
  extF80_eq_signaling$(OBJ) \
  extF80_le_quiet$(OBJ) \
  extF80_lt_quiet$(OBJ) \
  extF80_isSignalingNaN$(OBJ) \
  extF80M_to_ui32$(OBJ) \
  extF80M_to_ui64$(OBJ) \
  extF80M_to_i32$(OBJ) \
  extF80M_to_i64$(OBJ) \
  extF80M_to_ui32_r_minMag$(OBJ) \
  extF80M_to_ui64_r_minMag$(OBJ) \
  extF80M_to_i32_r_minMag$(OBJ) \
  extF80M_to_i64_r_minMag$(OBJ) \
  extF80M_to_f16$(OBJ) \
  extF80M_to_f32$(OBJ) \
  extF80M_to_f64$(OBJ) \
  extF80M_to_f128M$(OBJ) \
  extF80M_roundToInt$(OBJ) \
  extF80M_add$(OBJ) \
  extF80M_sub$(OBJ) \
  extF80M_mul$(OBJ) \
  extF80M_div$(OBJ) \
  extF80M_rem$(OBJ) \
  extF80M_sqrt$(OBJ) \
  extF80M_eq$(OBJ) \
  extF80M_le$(OBJ) \
  extF80M_lt$(OBJ) \
  extF80M_eq_signaling$(OBJ) \
  extF80M_le_quiet$(OBJ) \
  extF80M_lt_quiet$(OBJ) \
  f128_to_ui32$(OBJ) \
  f128_to_ui64$(OBJ) \
  f128_to_i32$(OBJ) \
  f128_to_i64$(OBJ) \
  f128_to_ui32_r_minMag$(OBJ) \
  f128_to_ui64_r_minMag$(OBJ) \
  f128_to_i32_r_minMag$(OBJ) \
  f128_to_i64_r_minMag$(OBJ) \
  f128_to_f16$(OBJ) \
  f128_to_f32$(OBJ) \
  f128_to_extF80$(OBJ) \
  f128_to_f64$(OBJ) \
  f128_roundToInt$(OBJ) \
  f128_add$(OBJ) \
  f128_sub$(OBJ) \
  f128_mul$(OBJ) \
  f128_mulAdd$(OBJ) \
  f128_div$(OBJ) \
  f128_rem$(OBJ) \
  f128_sqrt$(OBJ) \
  f128_eq$(OBJ) \
  f128_le$(OBJ) \
  f128_lt$(OBJ) \
  f128_eq_signaling$(OBJ) \
  f128_le_quiet$(OBJ) \
  f128_lt_quiet$(OBJ) \
  f128_isSignalingNaN$(OBJ) \
  f128M_to_ui32$(OBJ) \
  f128M_to_ui64$(OBJ) \
  f128M_to_i32$(OBJ) \
  f128M_to_i64$(OBJ) \
  f128M_to_ui32_r_minMag$(OBJ) \
  f128M_to_ui64_r_minMag$(OBJ) \
  f128M_to_i32_r_minMag$(OBJ) \
  f128M_to_i64_r_minMag$(OBJ) \
  f128M_to_f16$(OBJ) \
  f128M_to_f32$(OBJ) \
  f128M_to_extF80M$(OBJ) \
  f128M_to_f64$(OBJ) \
  f128M_roundToInt$(OBJ) \
  f128M_add$(OBJ) \
  f128M_sub$(OBJ) \
  f128M_mul$(OBJ) \
  f128M_mulAdd$(OBJ) \
  f128M_div$(OBJ) \
  f128M_rem$(OBJ) \
  f128M_sqrt$(OBJ) \
  f128M_eq$(OBJ) \
  f128M_le$(OBJ) \
  f128M_lt$(OBJ) \
  f128M_eq_signaling$(OBJ) \
  f128M_le_quiet$(OBJ) \
  f128M_lt_quiet$(OBJ) \
  f_minmax$(OBJ) \
  f_absneg$(OBJ) \
  f_compare$(OBJ) \
  f_round$(OBJ)

OBJS_ALL = $(OBJS_PRIMITIVES) $(OBJS_SPECIALIZE) $(OBJS_OTHERS)

$(OBJS_ALL): \
  platform.h $(SOURCE_DIR)/include/primitiveTypes.h \
  $(SOURCE_DIR)/include/primitives.h
$(OBJS_SPECIALIZE) $(OBJS_OTHERS): \
  $(SOURCE_DIR)/include/softfloat_types.h $(SOURCE_DIR)/include/internals.h \
  $(SOURCE_DIR)/$(SPECIALIZE_TYPE)/specialize.h \
  $(SOURCE_DIR)/include/softfloat.h

$(OBJS_PRIMITIVES) $(OBJS_OTHERS): %$(OBJ): $(SOURCE_DIR)/%.c
	$(COMPILE_C) $(SOURCE_DIR)/$*.c

$(OBJS_SPECIALIZE): %$(OBJ): $(SOURCE_DIR)/$(SPECIALIZE_TYPE)/%.c
	$(COMPILE_C) $(SOURCE_DIR)/$(SPECIALIZE_TYPE)/$*.c

softfloat$(LIB): $(OBJS_ALL)
	$(DELETE) $@
	$(MAKELIB) $^

softfloat.wasm: $(OBJS_ALL)
	$(DELETE) $@
	$(LINK) -o softfloat.wasm extF80_add.o extF80_div.o extF80_eq.o extF80_eq_signaling.o extF80_isSignalingNaN.o extF80_le.o extF80_le_quiet.o extF80_lt.o extF80_lt_quiet.o extF80M_add.o extF80M_div.o extF80M_eq.o extF80M_eq_signaling.o extF80M_isSignalingNaN.o extF80M_le.o extF80M_le_quiet.o extF80M_lt.o extF80M_lt_quiet.o extF80M_mul.o extF80M_rem.o extF80M_roundToInt.o extF80M_sqrt.o extF80M_sub.o extF80M_to_f128M.o extF80M_to_f16.o extF80M_to_f32.o extF80M_to_f64.o extF80M_to_i32.o extF80M_to_i32_r_minMag.o extF80M_to_i64.o extF80M_to_i64_r_minMag.o extF80M_to_ui32.o extF80M_to_ui32_r_minMag.o extF80M_to_ui64.o extF80M_to_ui64_r_minMag.o extF80_mul.o extF80_rem.o extF80_roundToInt.o extF80_sqrt.o extF80_sub.o extF80_to_f128.o extF80_to_f16.o extF80_to_f32.o extF80_to_f64.o extF80_to_i32.o extF80_to_i32_r_minMag.o extF80_to_i64.o extF80_to_i64_r_minMag.o extF80_to_ui32.o extF80_to_ui32_r_minMag.o extF80_to_ui64.o extF80_to_ui64_r_minMag.o f128_add.o f128_div.o f128_eq.o f128_eq_signaling.o f128_isSignalingNaN.o f128_le.o f128_le_quiet.o f128_lt.o f128_lt_quiet.o f128M_add.o f128M_div.o f128M_eq.o f128M_eq_signaling.o f128M_isSignalingNaN.o f128M_le.o f128M_le_quiet.o f128M_lt.o f128M_lt_quiet.o f128M_mul.o f128M_rem.o f128M_roundToInt.o f128M_sqrt.o f128M_sub.o f128M_to_extF80M.o f128M_to_f16.o f128M_to_f32.o f128M_to_f64.o f128M_to_i32.o f128M_to_i32_r_minMag.o f128M_to_i64.o f128M_to_i64_r_minMag.o f128M_to_ui32.o f128M_to_ui32_r_minMag.o f128M_to_ui64.o f128M_to_ui64_r_minMag.o f128_mul.o f128_rem.o f128_roundToInt.o f128_sqrt.o f128_sub.o f128_to_extF80.o f128_to_f16.o f128_to_f32.o f128_to_f64.o f128_to_i32.o f128_to_i32_r_minMag.o f128_to_i64.o f128_to_i64_r_minMag.o f128_to_ui32.o f128_to_ui32_r_minMag.o f128_to_ui64.o f128_to_ui64_r_minMag.o f16_add.o f16_div.o f16_eq.o f16_eq_signaling.o f16_isSignalingNaN.o f16_le.o f16_le_quiet.o f16_lt.o f16_lt_quiet.o f16_mulAdd.o f16_mul.o f16_rem.o f16_roundToInt.o f16_sqrt.o f16_sub.o f16_to_extF80M.o f16_to_extF80.o f16_to_f128M.o f16_to_f128.o f16_to_f32.o f16_to_f64.o f16_to_i32.o f16_to_i32_r_minMag.o f16_to_i64.o f16_to_i64_r_minMag.o f16_to_ui32.o f16_to_ui32_r_minMag.o f16_to_ui64.o f16_to_ui64_r_minMag.o f32_add.o f32_div.o f32_eq.o f32_eq_signaling.o f32_isSignalingNaN.o f32_le.o f32_le_quiet.o f32_lt.o f32_lt_quiet.o f32_mulAdd.o f32_mul.o f32_rem.o f32_roundToInt.o f32_sqrt.o f32_sub.o f32_to_extF80M.o f32_to_extF80.o f32_to_f128M.o f32_to_f128.o f32_to_f16.o f32_to_f64.o f32_to_i32.o f32_to_i32_r_minMag.o f32_to_i64.o f32_to_i64_r_minMag.o f32_to_ui32.o f32_to_ui32_r_minMag.o f32_to_ui64.o f32_to_ui64_r_minMag.o f64_add.o f64_div.o f64_eq.o f64_eq_signaling.o f64_isSignalingNaN.o f64_le.o f64_le_quiet.o f64_lt.o f64_lt_quiet.o f64_mulAdd.o f64_mul.o f64_rem.o f64_roundToInt.o f64_sqrt.o f64_sub.o f64_to_extF80M.o f64_to_extF80.o f64_to_f128M.o f64_to_f128.o f64_to_f16.o f64_to_f32.o f64_to_i32.o f64_to_i32_r_minMag.o f64_to_i64.o f64_to_i64_r_minMag.o f64_to_ui32.o f64_to_ui32_r_minMag.o f64_to_ui64.o f64_to_ui64_r_minMag.o f_absneg.o f_compare.o f_minmax.o f_round.o i32_to_extF80M.o i32_to_extF80.o i32_to_f128M.o i32_to_f128.o i32_to_f16.o i32_to_f32.o i32_to_f64.o i64_to_extF80M.o i64_to_extF80.o i64_to_f128M.o i64_to_f128.o i64_to_f16.o i64_to_f32.o i64_to_f64.o s_add128.o s_add256M.o s_addMagsExtF80.o s_addMagsF128.o s_addMagsF16.o s_addMagsF32.o s_addMagsF64.o s_approxRecip_1Ks.o s_approxRecip32_1.o s_approxRecipSqrt_1Ks.o s_approxRecipSqrt32_1.o s_commonNaNToExtF80UI.o s_commonNaNToF128UI.o s_commonNaNToF16UI.o s_commonNaNToF32UI.o s_commonNaNToF64UI.o s_countLeadingZeros16.o s_countLeadingZeros32.o s_countLeadingZeros64.o s_countLeadingZeros8.o s_eq128.o s_extF80UIToCommonNaN.o s_f128UIToCommonNaN.o s_f16UIToCommonNaN.o s_f32UIToCommonNaN.o s_f64UIToCommonNaN.o s_le128.o s_lt128.o s_mul128By32.o s_mul128To256M.o s_mul64ByShifted32To128.o s_mul64To128.o s_mulAddF16.o s_mulAddF32.o s_mulAddF64.o s_normRoundPackToExtF80.o s_normRoundPackToF128.o s_normRoundPackToF16.o s_normRoundPackToF32.o s_normRoundPackToF64.o s_normSubnormalExtF80Sig.o s_normSubnormalF128Sig.o s_normSubnormalF16Sig.o s_normSubnormalF32Sig.o s_normSubnormalF64Sig.o softfloat_raiseFlags.o softfloat_state.o s_propagateNaNExtF80UI.o s_propagateNaNF128UI.o s_propagateNaNF16UI.o s_propagateNaNF32UI.o s_propagateNaNF64UI.o s_roundPackToExtF80.o s_roundPackToF128.o s_roundPackToF16.o s_roundPackToF32.o s_roundPackToF64.o s_roundToI32.o s_roundToI64.o s_roundToUI32.o s_roundToUI64.o s_shiftRightJam128Extra.o s_shiftRightJam128.o s_shiftRightJam32.o s_shiftRightJam64Extra.o s_shiftRightJam64.o s_shortShiftLeft128.o s_shortShiftRight128.o s_shortShiftRightJam128Extra.o s_shortShiftRightJam128.o s_shortShiftRightJam64Extra.o s_shortShiftRightJam64.o s_sub128.o s_sub256M.o s_subMagsExtF80.o s_subMagsF128.o s_subMagsF16.o s_subMagsF32.o s_subMagsF64.o ui32_to_extF80M.o ui32_to_extF80.o ui32_to_f128M.o ui32_to_f128.o ui32_to_f16.o ui32_to_f32.o ui32_to_f64.o ui64_to_extF80M.o ui64_to_extF80.o ui64_to_f128M.o ui64_to_f128.o ui64_to_f16.o ui64_to_f32.o ui64_to_f64.o

.PHONY: clean
clean:
	$(DELETE) $(OBJS_ALL) softfloat$(LIB) softfloat.wasm
