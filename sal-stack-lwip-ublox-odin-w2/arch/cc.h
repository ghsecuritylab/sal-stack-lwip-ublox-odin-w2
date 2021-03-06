/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Adam Dunkels <adam@sics.se>
 *
 */
#ifndef __ARCH_CC_H__
#define __ARCH_CC_H__

#  ifndef __CB_FILE__
#    define __CB_FILE__ "LWIP"
#  endif

#include "cb_comdefs.h"

/* prototypes for printf() and abort() */
#include "mbed-drivers/mbed_assert.h"
#include <stdio.h>
#include <stdlib.h>

#define BYTE_ORDER LITTLE_ENDIAN

typedef cb_uint8    u8_t;
typedef cb_int8     s8_t;
typedef cb_uint16   u16_t;
typedef cb_int16    s16_t;
typedef cb_uint32   u32_t;
typedef cb_int32    s32_t;
typedef u32_t mem_ptr_t;


#define PACK_STRUCT_BEGIN  cb_PACKED_STRUCT_ATTR_PRE
#define PACK_STRUCT_STRUCT cb_PACKED_STRUCT_ATTR_INLINE_POST
#define PACK_STRUCT_END    cb_PACKED_STRUCT_ATTR_POST
#define PACK_STRUCT_FIELD(x) x


#define U16_F   "u"
#define U32_F   "u"

#define S16_F   "d"
#define S32_F   "d"

#define X16_F   "x"
#define X32_F   "x"

#define LWIP_RAND() ((u32_t)rand())

/* Platform specific diagnostic output */

#ifndef NDEBUG
#  define LWIP_PLATFORM_DIAG(x)   do { printf x ; } while(0)
#else
#  define LWIP_PLATFORM_DIAG(x)   
#endif

#ifndef NDEBUG
#ifdef __LWIP_FILE__
#define LWIP_PLATFORM_ASSERT(x) do {    \
          printf("lwIP assert %s:%d: %s\n\n", __LWIP_FILE__, __LINE__, x); \
          MBED_ASSERT(0); \
        } while(0)
#else
/* NOTE: Assert info string removed on purpose to reduce code size */
#define LWIP_PLATFORM_ASSERT(x) do { \
          printf("lwIP assert %s:%d\n", __FILE__, __LINE__); \
          MBED_ASSERT(0); \
        } while(0)
#endif

#else
#define LWIP_PLATFORM_ASSERT(x) do {cb_ASSERT(0);} while(0)

#endif





#endif /* __ARCH_CC_H__ */
