/* Machine/OS specific configuration information for GNUstep

   Please NOTE - GSConfig.h is generated by the configure script from the
   file GSConfig.h.in - changes/fixes need to be made to the original file,
   not to the GSConfig.h generated from it.

   Copyright (C) 1998-2010 Free Software Foundation, Inc.

   Written by:  Richard frith-Macdonald <richard@brainstorm.co.uk>

   This file is part of the GNUstep Base Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02111 USA.
   */

#ifndef	included_GSConfig_h
#define	included_GSConfig_h

/* Check the compiler to see if we are building on/for ms-windows.
 * Whatever the compiler uses, we want a standard setting of _WIN64
 * to indicate 64bit AND _WIN32 to indicate ms-windows.
 * These are defined by gcc, clang, and microsoft compilers anyway.
 */
#if     defined(__WIN32__) \
	|| defined(__MS_WIN32__) \
	|| defined(__MINGW32__)
#  if	!defined(_WIN32)
#    define _WIN32
#  endif
#endif
#if     defined(__WIN64__) \
	|| defined(__MS_WIN64__) \
	|| defined(__MINGW64__)
#  if	!defined(__WIN64__)
#    define __WIN64__
#  endif
#  if	!defined(_WIN32)
#    define _WIN32
#  endif
#endif

/* Check to see if this is a MINGW build (all we currently support)
 */
#if	defined(__MINGW32__) || defined(__MINGW64__)
#  if	!defined(__MINGW__)
#    define __MINGW__
#  endif
#endif

// Make sure we expose the constants that we use in ObjC++ mode
#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif
#ifndef __STDC_LIMIT_MACROS 
#define __STDC_LIMIT_MACROS 1
#endif

#if !defined(NeXT_Foundation_LIBRARY)

/* An alternate to GS_FAKE_MAIN which forces the user to call the
   NSProcessInfo initialization in 'main', GS_FAKE_MAIN must also
   be undefined. */
#if 0
#define GS_PASS_ARGUMENTS 0
#endif

#define GS_FAKE_MAIN	1
#if	GS_FAKE_MAIN

/*
 * NOTE - if GS_FAKE_MAIN (above) is set to 1, this hack applies - and you
 * must make sure that this file is included in any file that implements
 * the 'main()' function and links with the GNUstep base libarary.
 * You should NOT include this file in a program that does not link with
 * the base library.
 * This file is included automatically in NSObject.h and Foundation.h
 *
 * The Foundation classe NSProcessInfo need access to the argc, argv,
 * and env variables of the main() function. The purpose of this (ugly hack)
 * definition is to give the gstep-base library the opportunity to implement
 * its own main function with private access to the global vars. The private
 * main() implementation (in NSProcessInfo.m) will then call the user defined
 * gnustep_base_user_main() function.
 *
 * The original hack was -
 ** Written by:  Georg Tuparev, EMBL & Academia Naturalis,
 **              Heidelberg, Germany
 **              Tuparev@EMBL-Heidelberg.de
 **
 **  NOTE! This is very dirty and dangerous trick. I spend several hours
 ** on thinking and man pages browsing, but couldn't find better solution.
 ** I know that I will spend 666 years in the Computer Hell for writing
 ** this hack, and the master devil (Bully Boy) will send me to write
 ** Windowz software.
 ** BTW, for writing this hack I got personal congratulations from Dennis
 ** Ritchie and Bjarne Stroustrup sent me a bunch of flowers and asked me
 ** to participate in the standardization committee for C-- v.6.0 as
 ** responsible for the new Tab-Overriding-Operator and Scope-Sensitive-
 ** Comments ... but this makes my situation even worse ;-)
 ** - Georg
 *
 * On some systems, there are other relatively clean workarounds, if this
 * applies to the system you are running on, your configuration script
 * should have set GS_FAKE_MAIN to zero, so that this define hack will
 * not be used.
 */

#define main gnustep_base_user_main

#endif	/* GS_FAKE_MAIN */
#endif

/*
 * Definition to specify if your processor stores words with the most
 * significant byte first (like Motorola and SPARC, unlike Intel and VAX).
 */
#define GS_WORDS_BIGENDIAN	0

/*
 *	Size definitions for standard types
 */
#define	GS_SIZEOF_SHORT		2
#define	GS_SIZEOF_INT		4
#define	GS_SIZEOF_LONG		8
#define	GS_SIZEOF_LONG_LONG	8
#define	GS_SIZEOF_FLOAT		4
#define	GS_SIZEOF_DOUBLE	8
#define	GS_SIZEOF_VOIDP		8

/*
 *	Size information to be places in bits 5 and 6 of type encoding bytes
 *	in archives (bits 0 to 4 are used for basic type info and bit 7 is
 *	used to mark cross-references to previously encoded objects).
 */
#define	_GSC_S_SHT	_GSC_I16
#define	_GSC_S_INT	_GSC_I32
#define	_GSC_S_LNG	_GSC_I64
#define	_GSC_S_LNG_LNG	_GSC_I64

/*
 * Type definitions for types with known sizes.
 */
typedef signed char gss8;
typedef unsigned char gsu8;
typedef signed short gss16;
typedef unsigned short gsu16;
typedef signed int gss32;
typedef unsigned int gsu32;
typedef signed long gss64;
typedef unsigned long gsu64;
typedef struct { gsu8 a[16]; } gss128;
typedef struct { gsu8 a[16]; } gsu128;
typedef float gsf32;
typedef double gsf64;

/*
 * Integer type with same size as a pointer
 */
typedef	unsigned long gsuaddr;
typedef	long gssaddr;
typedef	gsuaddr gsaddr;

/*
 *	Do we have real 64-bit and 128-bit integers or are we just pretending.
 */
#define GS_HAVE_I64	1
#define GS_HAVE_I128	0

/*
 * Ensure some standard types are defined.
 */
#include <inttypes.h>











/*
 * PTR Limit information replacements for buggy headers
 */ 
#if 0
#undef INTPTR_MAX
#define INTPTR_MAX 
#undef INTPTR_MIN
#define INTPTR_MIN 
#undef UINTPTR_MAX
#define UINTPTR_MAX 
#endif


/*
 *	Do we have zlib for file handle compression?
 */
#define USE_ZLIB	0

/*
 *	Do we have the GNU Multiple-precision library for NSDecimal?
 */
//#define USE_GMP	0
#define USE_GMP	0

#ifdef	GS_WITH_GC
#undef  GS_WITH_GC
#endif
#define	GS_WITH_GC	0

/*
 * Define to say if we use NXConstantString or NSConstantString
 */
#define NXConstantString	


/*
 * Wide unicode character type.
 */
#ifndef	UTF32Char
#define	UTF32Char	uint32_t
#endif

/*
 * Native character type for use in systemcalls etc.
 */

#if	defined(__MINGW__)
#  define	GSNativeChar	uint16_t
#else
#  define	GSNativeChar	char
#endif

/*
 * Types used to avoid exposing pthread header in NSLock.h
 * NB. These types should *never* be used except to provide enough space
 * in a class layout for the type of data actually used by the pthread
 * implementation of the current platform.
 */
typedef	struct {
  uint8_t	dummy[48];
} gs_cond_t	__attribute__((aligned (8)));
typedef	struct {
  uint8_t	dummy[40];
} gs_mutex_t	__attribute__((aligned (8)));

#define	OBJC2RUNTIME 1
#define BASE_NATIVE_OBJC_EXCEPTIONS     1
#define GS_NONFRAGILE     1
#define GS_MIXEDABI     1
#define GS_USE_LIBXML 1
#define GS_USE_GNUTLS 1
#define GS_USE_AVAHI 0
#define GS_USE_MDNS 0
#define GS_USE_ICU 1
#define GS_USE_LIBDISPATCH 0
#define GS_USE_LIBDISPATCH_RUNLOOP 0
#define GS_HAVE_OBJC_ROOT_CLASS_ATTR 1

#ifndef __has_include
#  define __has_include(x) 0
#endif
#ifndef __has_feature
#  define __has_feature(x) 0
#endif
#ifndef __has_builtin
#  define __has_builtin(x) 0
#endif

/*
 * __has_extension has slightly different semantics from __has_feature.
 * It evaluates to true if the feature is supported by by clang for the
 * current compilation unit (language and -f switches), regardless of
 * whether it is part of the language standard or just a (non-standard)
 * extension.
 */
#ifndef __has_extension
#  define __has_extension(x) __has_feature(x)
#endif

#if defined(_WIN32)
#define BOOL WinBOOL
#define __OBJC_BOOL 1
#include <w32api.h>
#ifndef _WIN32_WINNT
#define _WIN32_WINNT Windows2000
#endif
#if	!defined(WINVER)
#define WINVER Windows2000
#elif (WINVER < Windows2000)
#undef	WINVER
#define WINVER Windows2000
#endif

#if defined(__WIN64__)
#include <winsock2.h>
#include <windows.h>
#else
#include <windows.h>
#include <winsock2.h>
#endif

#undef __OBJC_BOOL
#undef  BOOL
#endif

/* Include the blocks runtime header if it's available (It shouldn't matter
 * that this doesn't work on compilers that don't support __has_include(),
 * because they also don't support blocks).
 */
#if __has_include(<objc/block_runtime.h>)
#  include <objc/block_runtime.h>
#endif

#ifndef _WIN32
#include <sys/param.h> /* Hack to get rid of warning in GNU libc 2.0.3. */
#endif

/* The following group of lines maintained by the gstep-base configure */
#define GNUSTEP_BASE_VERSION            1.24.9
#define GNUSTEP_BASE_MAJOR_VERSION      1
#define GNUSTEP_BASE_MINOR_VERSION      24
#define GNUSTEP_BASE_SUBMINOR_VERSION   9
#define GNUSTEP_BASE_GCC_VERSION        4.0.0

/* Do not use the following macros!
 */
#define OBJC_DEP(M) \
  ({ static BOOL beenHere = NO; if (beenHere == NO) {\
    beenHere = YES; fprintf(stderr, "%s:%d %s", __FILE__, __LINE__, (M));}})

#define OBJC_MALLOC(VAR, TYPE, NUM) \
   (OBJC_DEP("OBJC_MALLOC is deprecated ... use malloc\n"),(VAR) = (TYPE *) malloc ((unsigned)(NUM)*sizeof(TYPE)))
#define OBJC_VALLOC(VAR, TYPE, NUM) \
   (OBJC_DEP("OBJC_VALLOC is deprecated\n"),(VAR) = (TYPE *) valloc ((unsigned)(NUM)*sizeof(TYPE)))
#define OBJC_ATOMIC_MALLOC(VAR, TYPE, NUM) \
   (OBJC_DEP("OBJC_ATOMIC_MALLOC is deprecated\n"),(VAR) = (TYPE *) malloc ((unsigned)(NUM)*sizeof(TYPE)))
#define OBJC_REALLOC(VAR, TYPE, NUM) \
   (OBJC_DEP("OBJC_REALLOC is deprecated ... use realloc\n"),(VAR) = (TYPE *) realloc ((VAR), (unsigned)(NUM)*sizeof(TYPE)))
#define OBJC_CALLOC(VAR, TYPE, NUM) \
   (OBJC_DEP("OBJC_CALLOC is deprecated ... use calloc\n"),(VAR) = (TYPE *) calloc ((unsigned)(NUM), sizeof(TYPE)))
#define OBJC_FREE(PTR) (OBJC_DEP("OBJC_FREE is deprecated ... use free\n"), free (PTR))

#ifndef MAX
#define MAX(a,b) \
       ({__typeof__(a) _MAX_a = (a); __typeof__(b) _MAX_b = (b);  \
         _MAX_a > _MAX_b ? _MAX_a : _MAX_b; })
#endif

#ifndef MIN
#define MIN(a,b) \
       ({__typeof__(a) _MIN_a = (a); __typeof__(b) _MIN_b = (b);  \
         _MIN_a < _MIN_b ? _MIN_a : _MIN_b; })
#endif

#ifndef ABS
#define ABS(a) \
       ({__typeof__(a) _ABS_a = (a); \
         _ABS_a < 0 ? -_ABS_a : _ABS_a; })
#endif

#ifndef STRINGIFY
#define STRINGIFY(s) XSTRINGIFY(s)
#define XSTRINGIFY(s) #s
#endif

#ifndef OBJC_STRINGIFY
#define OBJC_STRINGIFY(s) OBJC_XSTRINGIFY(s)
#define OBJC_XSTRINGIFY(s) @#s
#endif

#ifndef PTR2LONG
#define PTR2LONG(P) (((char*)(P))-(char*)0)
#endif
#ifndef LONG2PTR
#define LONG2PTR(L) (((char*)0)+(L))
#endif

#if VSPRINTF_RETURNS_LENGTH
#define VSPRINTF_LENGTH(VSPF_CALL) (VSPF_CALL)
#else
#define VSPRINTF_LENGTH(VSPF_CALL) strlen((VSPF_CALL))
#endif /* VSPRINTF_RETURNS_LENGTH */

#if VASPRINTF_RETURNS_LENGTH
#define VASPRINTF_LENGTH(VASPF_CALL) (VASPF_CALL)
#else
#define VASPRINTF_LENGTH(VASPF_CALL) strlen((VASPF_CALL))
#endif /* VSPRINTF_RETURNS_LENGTH */

/* Evil hack to stop gcc-4.1 complaining about a dealloc method which
 * does not call the superclass implementation.
 */
#define	GSNOSUPERDEALLOC	if (0) [super dealloc]

#ifndef CF_EXCLUDE_CSTD_HEADERS
#include <sys/types.h>
#include <stdarg.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#endif

#if !__has_feature(objc_arc)
// NetBSD > 6 defines __weak in cdefs_elf.h
#ifdef __NetBSD__
#undef __weak
#endif
#  if !defined(__weak)
#    define __weak
#  endif
#  if !defined(__strong)
#    define __strong
#  endif
#endif

#ifndef __unsafe_unretained
#  if !__has_feature(objc_arc)
#    define __unsafe_unretained
#  endif
#endif
#ifndef __bridge
#  if !__has_feature(objc_arc)
#    define __bridge
#  endif
#endif

#if __has_builtin(__builtin_unreachable)
#  define GS_UNREACHABLE() __builtin_unreachable()
#else
#  define GS_UNREACHABLE() abort()
#endif

// #import <objc/objc.h>
// BOOL objc_create_block_classes_as_subclasses_of(Class super);

#endif	/* included_GSConfig_h */

