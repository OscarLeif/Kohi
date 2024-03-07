#include "platform.h"

// Windos platform layer.
#if KPLATFORM_WINDOWS

#include <windows.h>
#include <windowsx.h>  // param input extraction

typedef struct internal_state{
    HINSTANCE h_instace;
    HWND hwnd;
}internal_state;

b8 platform_startup(
    platform_state* plat_state,
    const char* application_name,
    i32 x,
    i32 y,
    i32 width,
    i32 heigth)
    {
        plat_state->internal_state=malloc(sizeof(internal_state));
        internal_state *state = (internal_state *)plat_state->internal_state;

        state->h_instace=GetModuleHandle(0);
    }

#endif