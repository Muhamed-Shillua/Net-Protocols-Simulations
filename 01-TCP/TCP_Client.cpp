#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    WSADATA wsaData;
    SOCKET clientSocket;
    sockaddr_in serverAddr;
    char buffer[1024];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "WSAStartup Failed.\n";
        return 1;
    }

    // Create a TCP socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        cout << "Socket Creation Failed.\n";
        WSACleanup();
        return 1;
    }

    // Define server address and port
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &(serverAddr.sin_addr)); // Convert IP string to binary

    // Connect to the server
    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cout << "Connection Failed.\n";
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    cout << "Connected to Server.\n";

    // Send a message to the server
    const char* message = "Hello from Client!";
    send(clientSocket, message, strlen(message), 0);

    // Receive a response from the server
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesReceived > 0) {
        // Safely null-terminate the received data
        if (bytesReceived < sizeof(buffer)) {
            buffer[bytesReceived] = '\0';
        }
        else {
            buffer[sizeof(buffer) - 1] = '\0';  // Prevent buffer overflow
        }
        cout << "Received from Server: " << buffer << endl;
    }

    // Cleanup
    closesocket(clientSocket);
    WSACleanup();

    system("pause");
}
