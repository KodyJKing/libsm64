#pragma once

#include "libsm64.h"
#include <stdio.h>

extern SM64DebugPrintFunctionPtr g_debug_print_func;
extern SM64DebugLineFunctionPtr g_debug_line_func;
extern SM64DebugPointFunctionPtr g_debug_point_func;
extern SM64DebugWorldTextFunctionPtr g_debug_world_text_func;

#define DEBUG_DEFAULT_DURATION 200

#define DEBUG_PRINT( ... ) do { \
    if( g_debug_print_func ) { \
        char debugStr[1024]; \
        sprintf( debugStr, __VA_ARGS__ ); \
        g_debug_print_func( debugStr ); \
    } \
} while(0)

#define DEBUG_LINE( x1, y1, z1, x2, y2, z2, color, duration ) do { \
    if( g_debug_line_func ) \
        g_debug_line_func( (x1), (y1), (z1), (x2), (y2), (z2), (color), (duration) ); \
} while(0)

#define DEBUG_POINT( x, y, z, color, duration ) do { \
    if( g_debug_point_func ) \
        g_debug_point_func( (x), (y), (z), (color), (duration) ); \
} while(0)

#define DEBUG_WORLD_TEXT( x, y, z, color, text, duration ) do { \
    if( g_debug_world_text_func ) \
        g_debug_world_text_func( (x), (y), (z), (color), (text), (duration) ); \
} while(0)
