#include <windows.h>
#include <commctrl.h>
#include <string.h>
#include <gl/glew.h>
#include <gl/wglew.h>



char* Title;
int Width, Height;
HWND hWnd;
HGLRC hGLRC;

HWND  slider1;
HWND  slider2;
HWND  slider3;
HWND  slider4;


LRESULT CALLBACK WndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR sCmdLine, int iShow);


bool InitOpenGL()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);

    return true;
}

void Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, Width, Height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)Width / (float)Height, 0.125f, 512.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 2.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);


    LRESULT result1 = SendMessage(slider1, TBM_GETPOS, 0, 0);
    LRESULT result2 = SendMessage(slider2, TBM_GETPOS, 0, 0);
    LRESULT result3 = SendMessage(slider3, TBM_GETPOS, 0, 0);

    static float rot_x = 0;
    static float rot_y = 0;
    static float rot_z = 0;

    rot_x += (result1 / 100.0) * 2 - 1;
    rot_y += (result2 / 100.0) * 2 - 1;
    rot_z += (result3 / 100.0) * 2 - 1;

    glRotatef(rot_x, 1.0f, 0.0f, 0.0f);
    glRotatef(rot_y, 0.0f, 1.0f, 0.0f);
    glRotatef(rot_z, 1.0f, 0.0f, 0.0f);


    LRESULT result4 = SendMessage(slider4, TBM_GETPOS, 0, 0);

    float scale = 0.25 + 1.5 * (result4 / 100.0);

    glScalef(scale, scale, scale);

    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);

    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);

    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);

    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);

    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);

    glEnd();
}



bool InitWindow(HINSTANCE hInstance, char* title, int width, int height)
{
    Title = title;
    Width = width;
    Height = height;

    WNDCLASSEX WndClassEx;

    memset(&WndClassEx, 0, sizeof(WNDCLASSEX));

    WndClassEx.cbSize = sizeof(WNDCLASSEX);
    WndClassEx.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    WndClassEx.lpfnWndProc = WndProc;
    WndClassEx.hInstance = hInstance;
    WndClassEx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClassEx.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    WndClassEx.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClassEx.lpszClassName = "Win32OpenGLWindow";

    if (RegisterClassEx(&WndClassEx) == 0)
    {
        return false;
    }

    DWORD Style = WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

    hWnd = CreateWindowEx(WS_EX_APPWINDOW, WndClassEx.lpszClassName, Title, Style, 0, 0, Width, Height, NULL, NULL, hInstance, NULL);

    if (hWnd == NULL)
    {
        return false;
    }

    DWORD dwExStyle = WS_EX_CLIENTEDGE | WS_EX_DLGMODALFRAME;
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE | SS_SUNKEN;

    slider1 = CreateWindow(TRACKBAR_CLASS, "", WS_CHILD | WS_VISIBLE | TBS_HORZ,
        10, 525, 180, 50, hWnd, 0, hInstance, NULL);
    slider2 = CreateWindow(TRACKBAR_CLASS, "", WS_CHILD | WS_VISIBLE | TBS_HORZ,
        210, 525, 180, 50, hWnd, 0, hInstance, NULL);
    slider3 = CreateWindow(TRACKBAR_CLASS, "", WS_CHILD | WS_VISIBLE | TBS_HORZ,
        410, 525, 180, 50, hWnd, 0, hInstance, NULL);
    slider4 = CreateWindow(TRACKBAR_CLASS, "", WS_CHILD | WS_VISIBLE | TBS_HORZ,
        610, 525, 180, 50, hWnd, 0, hInstance, NULL);

    SendMessage(slider1, TBM_SETPOS, TRUE, 50);
    SendMessage(slider2, TBM_SETPOS, TRUE, 50);
    SendMessage(slider3, TBM_SETPOS, TRUE, 50);
    SendMessage(slider4, TBM_SETPOS, TRUE, 50);


    HDC hDC = GetDC(hWnd);

    if (hDC == NULL)
    {
        return false;
    }

    PIXELFORMATDESCRIPTOR pfd;

    memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;
    pfd.iLayerType = PFD_MAIN_PLANE;

    int PixelFormat = ChoosePixelFormat(hDC, &pfd);

    if (PixelFormat == 0)
    {
        return false;
    }

    if (SetPixelFormat(hDC, PixelFormat, &pfd) == FALSE)
    {
        return false;
    }

    hGLRC = wglCreateContext(hDC);

    if (hGLRC == NULL)
    {
        return false;
    }

    if (wglMakeCurrent(hDC, hGLRC) == FALSE)
    {
        return false;
    }

    if (glewInit() != GLEW_OK)
    {
        return false;
    }

    if (WGLEW_EXT_swap_control)
    {
        wglSwapIntervalEXT(0);
    }

    return InitOpenGL();
}

void ShowWindow()
{
    MoveWindow(hWnd, 100, 100, 800, 600, FALSE);
    ShowWindow(hWnd, SW_SHOWNORMAL);
}

void MessageLoop()
{
    MSG Msg;

    while (GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
}

void OnPaint()
{
    PAINTSTRUCT ps;

    HDC hDC = BeginPaint(hWnd, &ps);

    Render();

    SwapBuffers(hDC);

    EndPaint(hWnd, &ps);

    InvalidateRect(hWnd, NULL, FALSE);
}

void Destroy()
{
    wglDeleteContext(hGLRC);
    DestroyWindow(hWnd);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uiMsg)
    {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;

    case WM_PAINT:
        OnPaint();
        break;
    default:
        return DefWindowProc(hWnd, uiMsg, wParam, lParam);
    }

    return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR sCmdLine, int iShow)
{
    const char* AppName = "Cube rendering, rotating and lighting";

    if (InitWindow(hInstance, (char*)AppName, 800, 600))
    {
        ShowWindow();
        MessageLoop();
    }

    Destroy();

    return 0;
}