
/*============================================================================

This C source file is part of the SoftFloat IEEE Floating-Point Arithmetic
Package, Release 3d, by John R. Hauser.

Copyright 2011, 2012, 2013, 2014, 2015, 2016 The Regents of the University of
California.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice,
    this list of conditions, and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions, and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

 3. Neither the name of the University nor the names of its contributors may
    be used to endorse or promote products derived from this software without
    specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS "AS IS", AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ARE
DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=============================================================================*/

#include <stdint.h>
#include "platform.h"
#include "primitives.h"

const uint16_t softfloat_approxRecipSqrt_1k0s(int a) {
    switch (a) {
        case 0: return 0xb4c9;
        case 1: return 0xffab;
        case 2: return 0xaa7d;
        case 3: return 0xf11c;
        case 4: return 0xa1c5;
        case 5: return 0xe4c7;
        case 6: return 0x9a43;
        case 7: return 0xda29;
        case 8: return 0x93b5;
        case 9: return 0xd0e5;
        case 10: return 0x8ded;
        case 11: return 0xc8b7;
        case 12: return 0x88c6;
        case 13: return 0xc16d;
        case 14: return 0x8424;
        case 15: return 0xbae1;
    }
    return 0;
//    0xB4C9, 0xFFAB, 0xAA7D, 0xF11C, 0xA1C5, 0xE4C7, 0x9A43, 0xDA29, 0x93B5, 0xD0E5, 0x8DED, 0xC8B7, 0x88C6, 0xC16D, 0x8424, 0xBAE1
}

const uint16_t softfloat_approxRecipSqrt_1k1s(int a) {
    switch (a) {
        case 0: return 0xa5a5;
        case 1: return 0xea42;
        case 2: return 0x8c21;
        case 3: return 0xc62d;
        case 4: return 0x788f;
        case 5: return 0xaa7f;
        case 6: return 0x6928;
        case 7: return 0x94b6;
        case 8: return 0x5cc7;
        case 9: return 0x8335;
        case 10: return 0x52a6;
        case 11: return 0x74e2;
        case 12: return 0x4a3e;
        case 13: return 0x68fe;
        case 14: return 0x432b;
        case 15: return 0x5efd;
    }
    return 0;
    // 0xA5A5, 0xEA42, 0x8C21, 0xC62D, 0x788F, 0xAA7F, 0x6928, 0x94B6,0x5CC7, 0x8335, 0x52A6, 0x74E2, 0x4A3E, 0x68FE, 0x432B, 0x5EFD
}

