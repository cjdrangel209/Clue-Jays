#include <iostream>
#include <string>
#include <cstdlib>

//Includes for Linux/MacOS
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <unistd.h>

//Includes for Windows
#include <WinSock2.h>
#include <Ws2tcpip.h>
#include <io.h>

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    char opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = { 0 };
    std::string message = "Program executed successfully\n";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    
    //EXECUTE THE PROGRAM
    system("./../x64/Release/Clue-Jays.exe");

    send(new_socket, message.c_str(), message.length(), 0);
    close(new_socket);
    close(server_fd);
    return 0;
}