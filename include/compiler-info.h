#ifndef PIKAXE_COMPILER_INFO_H
#define PIKAXE_COMPILER_INFO_H

/**
 * Header that gives info about availabilities in the C
 * distribution.
 */

#if defined(__STDC__)
#  if defined(__STDC_VERSION__)
#    if (__STDC_VERSION__ >= 199409L)
#        if (__STDC_VERSION__ >= 199901L)
#           if (__STDC_VERSION__ >= 201112L)
#              define PIKAXE_CVERS_11
#           else // !(__STDC_VERSION__ >= 201112L)
#              define PIKAXE_CVERS_99
#           endif // (__STDC_VERSION__ >= 201112L)
#        else // !(__STDC_VERSION__ >= 199901L)
#           define PIKAXE_CVERS_94
#        endif // (__STDC_VERSION__ >= 199901L)
#    else // (__STDC_VERSION__ >= 199409L)
#       define PIKAXE_CVERS_90
#    endif // !(__STDC_VERSION__ >= 199409L)
#  else // defined(__STDC_VERSION__)
#    define PIKAXE_CVERS_89
#  endif // !defined(__STDC_VERSION__)
#else // defined(__STDC__)
#  ifdef _WIN32
#     pragma message("__STDC__ is not defined, this is a non-standard C version.")
#  else
#     warn "__STDC__ is not defined, this is a non-standard C version."
#  endif
#endif

#include <limits.h>

#ifdef _MSC_VER
typedef __int8 int8_t;
typedef __int16 int16_t;
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef unsigned __int8 uint8_t;
typedef unsigned __int16 uint16_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int64 uint64_t;
#else // _MSC_VER
#   ifdef HAVE_STDINT
#      include <stdint.h>
#   else // !HAVE_STDINT
       // Determine integer sizes by limits.h
#      if defined(UINT_MAX) && UINT_MAX == 0xffffffff
           typedef int int32_t;
           typedef unsigned int uint32_t;
#      endif
#   endif
#endif // !_MSC_VER

#ifdef UINT_MAX
#  if UINT_MAX == 0xffffffff
#      define PIKAXE_INT_IS_32B
#  endif
#endif

#ifdef HABE_STDBOOL
#  include <stdbool.h>
#else
#   define true 1
#   define false 0
#   define bool int
#endif


#endif // PIKAXE_COMPILER_INFO_H
