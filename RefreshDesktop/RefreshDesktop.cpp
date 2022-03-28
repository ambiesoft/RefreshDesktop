#include <Windows.h>
#include <Shlobj.h>

#pragma comment(lib, "Shell32.lib")

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    SHChangeNotify(0x8000000, 0x1000, 0, 0);
    return 0;
}
