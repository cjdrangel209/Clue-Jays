#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0600
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <cstring>

#pragma comment (lib, "Ws2_32.lib")

int main() {
    char buffer[1024];
    // Initialize Winsock
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
        return 1;
    }

    // Create a socket
    SOCKET connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (connectSocket == INVALID_SOCKET) {
        std::cerr << "Error creating socket: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    // Resolve server address and port
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080); 
    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr); 

    // Connect to server
    iResult = connect(connectSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress));
    if (iResult == SOCKET_ERROR) {
        std::cerr << "Error connecting: " << WSAGetLastError() << std::endl;
        closesocket(connectSocket);
        WSACleanup();
        return 1;
    }

    while(true)
    {
        std::cout << "Enter command: ";
        std::string command;
        std::getline(std::cin, command);
        send(connectSocket, command.c_str(), command.length(), 0);
        int valread = recv(connectSocket, buffer, sizeof(buffer), 1024);
        if(valread <= 0)
        {
            std::cout << "Server disconnected or error occurred." << std::endl;
            break;
        }
        std::cout << "Server response:\n" << std::string(buffer, valread) << std::endl;
        memset(buffer, 0, sizeof(buffer));
    }

    /*
    // Send data
    const char* sendData = "Hello from client!";
    iResult = send(connectSocket, sendData, strlen(sendData), 0);
    if (iResult == SOCKET_ERROR) {
         std::cerr << "Error sending data: " << WSAGetLastError() << std::endl;
        closesocket(connectSocket);
        WSACleanup();
        return 1;
    }
    std::cout << "Data sent: " << sendData << std::endl;

    // Receive data
    char recvbuf[512];
    iResult = recv(connectSocket, recvbuf, 512, 0);
     if (iResult > 0) {
        std::cout << "Bytes received: " << iResult << std::endl;
        std::cout << "Data received: " << std::string(recvbuf, iResult) << std::endl;
    } else if (iResult == 0) {
        std::cout << "Connection closed" << std::endl;
    } else {
        std::cerr << "recv failed: " << WSAGetLastError() << std::endl;
    }
*/
    // Close socket and cleanup
    closesocket(connectSocket);
    WSACleanup();

    return 0;
}