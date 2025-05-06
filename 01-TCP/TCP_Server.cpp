#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

int main() {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    sockaddr_in serverAddr, clientAddr;
    int clientSize = sizeof(clientAddr);
    char buffer[1024];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "WSAStartup Failed.\n";
        return 1;
    }

    // Create a TCP socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        cout << "Socket Creation Failed.\n";
        WSACleanup();
        return 1;
    }

    // Define server address and port
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any interface

    // Bind the socket to the specified IP and port
    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cout << "Binding Failed.\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 1) == SOCKET_ERROR) {
        cout << "Listening failed.\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "Waiting for client connection...\n";

    // Accept a client connection
    clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);
    if (clientSocket == INVALID_SOCKET) {
        cout << "Client Connection Failed.\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "Client Connected.\n";

    // Receive message from client
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesReceived < sizeof(buffer)) {
        buffer[bytesReceived] = '\0';  // Safely null-terminate if room allows
    }
    else {
        buffer[sizeof(buffer) - 1] = '\0';  // Prevent buffer overrun
    }

    // Send response to client
    const char* response = "Hello from Server!";
    send(clientSocket, response, strlen(response), 0);

    // Cleanup
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    system("pause");
}
