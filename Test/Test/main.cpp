
#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

typedef char * (WINAPI* MY_FUNC)(void);
MY_FUNC func;
int main( int argc, char *argv[], char *envp[] )
{
    HMODULE  g_hDll = LoadLibrary(L"SndDrv_x64.dll");

    if (g_hDll)
        func = (MY_FUNC)GetProcAddress(g_hDll, "SoundSysDesc");
    printf("%s", func());
    while (1) {
        Sleep(1000);
        printf("___\n");
    }

	return 0;
}