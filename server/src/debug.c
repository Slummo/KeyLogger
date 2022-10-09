#include "debug.h"

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