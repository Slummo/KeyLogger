#include <winsock2.h>
#include "debug.h"
#pragma comment (lib, "ws2_32.lib") //Winsock Library
//flag -lws2_32

int main(int argc , char *argv[])
{
    //Variables
    WSADATA data;
    SOCKET listen_sock, new_sock;
    short port = 80;
    const char* ip = "127.0.0.1";
    struct sockaddr_in server, client;

    //Get and check argv
    int doDebug = 0;
    const char* true = "true";
    if(argc != 2) debug(1, 0, "[-]Too many or too short argumets! (server.exe [<boolean> debug])", -1);
    if(strcmp(argv[1], true) == 0) doDebug = 1;

    //Initialize Winsock
    if (WSAStartup(MAKEWORD(2,2),&data) != 0)
    debug(doDebug, 0, "[-]Error in WSAStartup().", WSAGetLastError());
    else debug(doDebug, 1, "[+]WinSock initialized.\n", 0);

    //Create a socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_sock == INVALID_SOCKET)
    debug(doDebug, 0, "[-]Error in socket().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Listening socket created.\n", 0);

    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    //Bind the infos to the listening socket
    if(bind(listen_sock, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
    debug(doDebug, 0, "[-]Error in bind().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Binded succesfully to the listening socket.\n", 0);

    //Set the socket to listen for connections
    //SOMAXCONN = Max number of connection in the queue
    if(listen(listen_sock, SOMAXCONN) == SOCKET_ERROR)
    debug(doDebug, 0, "[-]Error in listen().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Socket set to listen succesfully.\n", 0);

    //Wait for a connection
    int client_size = sizeof(client);

    //(Connect client socket with the listening server socket)
    new_sock = accept(listen_sock, (struct sockaddr*)&client, &client_size);
    if (new_sock == INVALID_SOCKET)
    debug(doDebug, 0, "[-]Error in accept().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Accepted a new connection.\n[+]Connection estabilished between the new socket and the client socket.\n", 0);

    //Close listening socket
    if(closesocket(listen_sock) == INVALID_SOCKET)
    debug(doDebug, 0, "[-]Error in closesocket().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Listening socket closed succesfully.\n", 0);

    //TODO
    char buf[100];

    if(recv(new_sock, buf, sizeof(buf), 0) == SOCKET_ERROR)
    debug(doDebug, 0, "[-]Error in recv().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Data received succesfully from the client.\n", 0);
    printf("buf = %s\n", buf);
    
    //Close the new socket
    if(closesocket(new_sock) == INVALID_SOCKET)
    debug(doDebug, 0, "[-]Error in closesocket().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Socket closed succesfully.\n", 0);

    //Close and cleanup WinSock
    if(WSACleanup() == SOCKET_ERROR)
    debug(doDebug, 0, "[-]Error in WSACleanup().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Winsock cleanup was succesful.\n", 0);

    return 0;
}