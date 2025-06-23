#include "focus.h"

#include <windows.h>

namespace focus
{
    void FocusWindow(unsigned char* handleBuffer)
    {
        LONG_PTR handle = *reinterpret_cast<LONG_PTR*>(handleBuffer);
        HWND hWnd = (HWND)(LONG_PTR)handle;

        HWND hWndForeground = GetForegroundWindow();
        if (hWnd != hWndForeground)
        {
            DWORD windowThreadProcessId =
                GetWindowThreadProcessId(hWndForeground, LPDWORD(0));
            DWORD currentThreadId = GetCurrentThreadId();
            DWORD CONST_SW_SHOW = 5;
            AttachThreadInput(windowThreadProcessId, currentThreadId, true);
            BringWindowToTop(hWnd);
            ShowWindow(hWnd, CONST_SW_SHOW);
            AttachThreadInput(windowThreadProcessId, currentThreadId, false);
        }
    }
}
