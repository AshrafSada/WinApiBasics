#include <Windows.h>
#include <iostream>
#include <WinUser.h>

// 6- create a window procedure to handle messages of interest

/// <summary>
/// Window procedure for handling messages, and interactions
/// </summary>
/// <param name="hWnd">A handle to the window</param>
/// <param name="uMsg">The message id</param>
/// <param name="wParam">Additional message information</param>
/// <param name="lParam">Additional message information</param>
/// <returns>the result of the message processing, and depends on the message sent</returns>
LRESULT CALLBACK WndProc(
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam) {
    switch (uMsg) {
        case WM_CLOSE:
            PostQuitMessage(69);
            break;
        /*case WM_QUIT:
            DestroyWindow(hWnd);
            break;*/
        default:
            break;
    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI CALLBACK  WinMain(HINSTANCE hInstance,
                             HINSTANCE hPrevInstance,
                             LPSTR lpCmdLine,
                             int nCmdShow) {
    const auto pClassName = L"MyWindow";
    // 1- Define a class
    WNDCLASSEX wc = { 0 };
    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = nullptr;
    wc.hCursor = nullptr;
    wc.hbrBackground = nullptr;
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = pClassName;
    wc.hIconSm = nullptr;

    // 2- Register window class
    RegisterClassEx(&wc);

    // 3- Create the window instance
    HWND hWndInstance = CreateWindowEx(0, pClassName, L"Happy Hard Window",
                                       WS_CAPTION |
                                       WS_MINIMIZEBOX |
                                       WS_SIZEBOX |
                                       WS_MAXIMIZEBOX |
                                       WS_SYSMENU,
                                       200, 200,
                                       640, 480,
                                       nullptr,
                                       nullptr,
                                       hInstance,
                                       nullptr);

    // 4- Show the window
    ShowWindow(hWndInstance, SW_SHOW);

    // 5- Handle messages (get, translate, dispatch, process messages of interest => close/destroy)
    MSG msg;
    BOOL gResult;
    while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

       
    }

    if (gResult == -1) {
        return -1; // error
    } else {
        return msg.wParam;
    }

   // 6- Goto Top

  
}
