#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <io.h>
#include <iostream>
#include <string>
#include <cstdlib>

//Includes for Linux/MacOS
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <unistd.h>

#pragma comment (lib, "Ws2_32.lib")

int main()
{
    WSADATA wsaData;
    if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        return 1;
    }

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(serverSocket == INVALID_SOCKET)
    {
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8080);
    if(bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    if(listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
    {
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    SOCKET clientSocket = accept(serverSocket, NULL, NULL);
    if(clientSocket == INVALID_SOCKET)
    {
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    system("./Program.exe");

    while(true){
        char buffer[1024];
        int valread = recv(clientSocket, buffer, sizeof(buffer), 1024);
        if(valread <= 0)
        {
            std::cout << "Client disconnected or error occurred." << std::endl;
            break;
        }

        std::string command(buffer, valread);
        //std::string result = exec(command.c_str());
        send(clientSocket, buffer, valread, 0);
    }
    /*char buffer[1024];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    if(bytesReceived > 0)
    {
        send(clientSocket, buffer, bytesReceived, 0);
    }
*/
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}