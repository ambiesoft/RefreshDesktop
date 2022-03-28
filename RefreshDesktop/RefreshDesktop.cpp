#include <Windows.h>
#include <Shlobj.h>

#include <string>
#include <sstream>

#include "../../lsMisc/CommandLineParser.h"

#include "gitrev.h"
#include "RefreshDesktop.h"

#pragma comment(lib, "Shell32.lib")

using namespace Ambiesoft;
using namespace std;

wstring getAppNameAndVersion()
{
    wstringstream ss;
    ss << APP_NAME << L" v" << APP_VERSION;
    return ss.str();
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    CCommandLineParser parser(I18N(L"Refreshes desktop icons"), L"RefreshDesktop");
    int nWait = 0;
    parser.AddOption(L"-wait",
        ArgCount::ArgCount_One,
        &nWait,
        ArgEncodingFlags::ArgEncodingFlags_Default,
        I18N(L"Waits for N secs before refreshing desktop"));

    bool bHelp = false;
    parser.AddOptionRange({ L"-h",L"--help",L"-v",L"--version",L"/?", L"/h" },
        ArgCount::ArgCount_Zero,
        &bHelp,
        ArgEncodingFlags_Default,
        I18N(L"Shows Help"));

    bool bShowGitrev = false;
    parser.AddOption(L"-gitrev",
        ArgCount::ArgCount_Zero,
        &bShowGitrev,
        ArgEncodingFlags_Default,
        I18N(L"Shows Help"));
    
    parser.Parse();

    if (bHelp)
    {
        MessageBox(nullptr, 
            parser.getHelpMessage().c_str(),
            getAppNameAndVersion().c_str(),
            MB_ICONINFORMATION);
        return 0;
    }
    if (bShowGitrev)
    {
        MessageBox(nullptr,
            GITREV::GetHashMessage().c_str(),
            getAppNameAndVersion().c_str(),
            MB_ICONINFORMATION);
        return 0;
    }

    if (nWait > 0)
        Sleep(nWait * 1000);

    SHChangeNotify(0x8000000, 0x1000, 0, 0);
    return 0;
}
