#include <windows.h>
#include <windowsx.h>
#include <tchar.h>

// windows windowProc function prototype

LRESULT CALLBACK WindowProc(HWND hWnd,UINT message, WPARAM wParam,
                            LPARAM lParam);

// entry point for any windows program
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    LPTSTR lpCmdline,int nCmdShow)
{
    // handle for window, filled by a function
    HWND hWnd;
    // this struct holds information for the window class
    WNDCLASSEX wc;

    // clear out the window class for use
    ZeroMemory(&wc, sizeof(WNDCLASSEX));
    //fill in the struct with needed info
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc =  WindowProc;
    wc.hInstance=hInstance;
    wc.hCursor=LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = _T("WindowClass01");

    //register the window class
    RegisterClassEx(&wc);

    //create the window and use the result as handle

    hWnd =  CreateWindowEx(0,
                            _T("WindowClass01"), //name of window class
                            _T("iEnGine"),//title
                            WS_OVERLAPPEDWINDOW,//windos style
                            400,//x-postion of window
                            400,//y-postion of window
                            800,//width
                            600,//height
                            NULL,//no parent window
                            NULL,// no menu
                            hInstance,//application handle
                            NULL);// used with mutiple windows, NULL
    
    // disply window on screen
    ShowWindow(hWnd,nCmdShow);

    //enter main loop

    //this struct holds windows event messages
    MSG msg;
    //wait for next message in queue, store the result in msg
    while(GetMessage(&msg,NULL,0,0)){
        //translate keystroke to the WindowProc func
        TranslateMessage(&msg);
        //send message to WindowProc func
        DispatchMessage(&msg);

    }
    //return this part of the WM_QUIT message to window
    return msg.wParam;

}

// main message handler for program

LRESULT CALLBACK WindowProc(HWND hWnd,UINT message, WPARAM wParam,
                            LPARAM lParam)
{
    //sort through and find what code to run for the message given
    switch (message){

        // draw a simple rectangle
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd,&ps);
            RECT rec = {20,20,60,80};
            HBRUSH brush = (HBRUSH) GetStockObject(BLACK_BRUSH);

            FillRect(hdc,&rec,brush);

            EndPaint(hWnd,&ps);
        }break;
        // this message read when window is closed
        case WM_DESTROY:
        {
            //Close the application extirely
            PostQuitMessage(0);
            return 0;
        } break;
    }

    return DefWindowProc(hWnd,message,wParam,lParam);
        

}