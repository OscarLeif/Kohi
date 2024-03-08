#include "platform.h"

// Windos platform layer.
#if KPLATFORM_WINDOWS

#include <windows.h>
#include <windowsx.h>  // param input extraction

typedef struct internal_state{
    HINSTANCE h_instace;
    HWND hwnd;
}internal_state;

LRESULT CALLBACK win32_process_message(HWND hwnd, u32 msg, WPARAM w_param, LPARAM l_param);

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

        //setup and register windows class
        HICON icon = LoadIcon(state->h_instace, IDI_APPLICATION);
        WNDCLASS wc;
        memset(&wc,0,sizeof(wc));
        wc.style = CS_DBLCLKS; //Get double-clicks
        wc.lpfnWndProc = win32_process_message;
        wc.cbClsExtra=0;
        wc.cbWndExtra=0;
        wc.hInstance = state->h_instace;
        wc.hIcon = icon;
        wc.hCursor= LoadCursor(NULL, IDC_ARROW); //NULL; //Manage the cursor manually
        wc.hbrBackground = NULL; // Transparent
        wc.lpszClassName = "kohi_windows_class";

        if(!RegisterClassA(&wc))
        {
            MessageBox(0,"Windows registration failed", "Error",MB_ICONEXCLAMATION | MB_OK);
            return FALSE;
        }

        // create window

        u32 client_x=x;
        u32 client_y=y;
        u32 client_width = width;
        u32 client_height = heigth;

    }

#endif