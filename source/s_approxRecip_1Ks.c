
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

const uint16_t softfloat_approxRecip_1k0s(int a) {
    if (a % 16 == 0) return 0xffc4;
    if (a % 16 == 1) return 0xf0be;
    if (a % 16 == 2) return 0xe363;
    if (a % 16 == 3) return 0xd76f;
    if (a % 16 == 4) return 0xccad;
    if (a % 16 == 5) return 0xc2f0;
    if (a % 16 == 6) return 0xba16;
    if (a % 16 == 7) return 0xb201;
    if (a % 16 == 8) return 0xaa97;
    if (a % 16 == 9) return 0xa3c6;
    if (a % 16 == 10) return 0x9d7a;
    if (a % 16 == 11) return 0x97a6;
    if (a % 16 == 12) return 0x923c;
    if (a % 16 == 13) return 0x8d32;
    if (a % 16 == 14) return 0x887e;
    if (a % 16 == 15) return 0x8417;
    return 0;
    // 0xFFC4, 0xF0BE, 0xE363, 0xD76F, 0xCCAD, 0xC2F0, 0xBA16, 0xB201, 0xAA97, 0xA3C6, 0x9D7A, 0x97A6, 0x923C, 0x8D32, 0x887E, 0x8417
}

const uint16_t softfloat_approxRecip_1k1s(int a) {
    switch (a) {
        case 0: return 0xf0f1;
        case 1: return 0xd62c;
        case 2: return 0xbfa1;
        case 3: return 0xac77;
        case 4: return 0x9c0a;
        case 5: return 0x8ddb;
        case 6: return 0x8185;
        case 7: return 0x76ba;
        case 8: return 0x6d3b;
        case 9: return 0x64d4;
        case 10: return 0x5d5c;
        case 11: return 0x56b1;
        case 12: return 0x50b6;
        case 13: return 0x4b55;
        case 14: return 0x4679;
        case 15: return 0x4211;
    }
    return 0;
    // 0xF0F1, 0xD62C, 0xBFA1, 0xAC77, 0x9C0A, 0x8DDB, 0x8185, 0x76BA, 0x6D3B, 0x64D4, 0x5D5C, 0x56B1, 0x50B6, 0x4B55, 0x4679, 0x4211
}

