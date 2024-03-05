#pragma once

#include "defines.h"

// Disable assertions by commenting out the bellow line.
#define KASSERTIONS_ENABLED

#ifdef KASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugBreak()
#else
#define debugBreak() __builtin_trap()
#endif

void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define KASSERT(expr)
{
    if(expr){
    }else{
        report_assertion_failure(#expr, "", __FILE__,__LINE__);
        debugBreak();
    }
}