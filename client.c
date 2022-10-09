#include <winsock2.h>
#include "debug.h"
#pragma comment(lib,"ws2_32.lib") //Winsock Library
//flag -lws2_32

int main(int argc , char *argv[])
{
    //Variables
    WSADATA data;
    SOCKET sock;
    short port = 80;
    const char* ip = "127.0.0.1";
    struct sockaddr_in server;

    //Get and check argv
    int doDebug = 0;
    const char* true = "true";
    if(argc != 2) debug(1, 0, "[-]Too many or too short argumets! (client.exe [<boolean> debug])", -1);
    if(strcmp(argv[1], true) == 0) doDebug = 1;

    //Initialize Winsock
    if (WSAStartup(MAKEWORD(2,2),&data) != 0)
    debug(doDebug, 0, "[-]Error in WSAStartup().", WSAGetLastError());
    else debug(doDebug, 1, "[+]WinSock initialized.\n", 0);

    //Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == INVALID_SOCKET)
    debug(doDebug, 0, "[-]Error in socket().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Socket created.\n", 0);

    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    //Connect to remote server
    if (connect(sock, (struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
    debug(doDebug, 0, "[-]Error in connect().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Connected succesfully to the server.\n", 0);

    //TODO
    char buf[100];
    FILE* log = fopen("../../logger/bin/logs/log.txt", "a+");
    if(log == NULL)
    debug(doDebug, 0, "[-]File can't be opened.", -1);
    else debug(doDebug, 1, "[+]log.txt opened correctly\n", 0);

    while (fgets(buf, 100, log) != NULL);

    if(send(sock, buf, sizeof(buf), 0) == SOCKET_ERROR)
    debug(doDebug, 0, "[-]Error in send().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Data sent succesfully to the server.\n", 0);

    fclose(log);

    //Close the socket
    if(closesocket(sock) == INVALID_SOCKET)
    debug(doDebug, 0, "[-]Error in closesocket().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Socket closed succesfully.\n", 0);

    //Close and cleanup WinSock
    if(WSACleanup() == SOCKET_ERROR)
    debug(doDebug, 0, "[-]Error in WSACleanup().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Winsock cleanup was succesful.\n", 0);
    return 0;
}