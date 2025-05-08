#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <fstream>  // File handling
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    WSADATA wsaData;
    SOCKET clientSocket;
    sockaddr_in serverAddr;
    char buffer[4096]; // Large buffer for HTML content

    // Step 1: Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "WSAStartup failed.\n";
        return 1;
    }

    // Step 2: Create client socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        cout << "Socket creation failed.\n";
        WSACleanup();
        return 1;
    }

    // Step 3: Set server address (localhost:9090)
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9090);
    inet_pton(AF_INET, "127.0.0.1", &(serverAddr.sin_addr));

    // Step 4: Connect to the server
    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cout << "Connection failed.\n";
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    cout << "Connected to server.\n";

    // Step 5: Send simple HTTP GET request
    const char* httpRequest = "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n";
    send(clientSocket, httpRequest, strlen(httpRequest), 0);

    // Step 6: Receive response and save to file
    ofstream outFile("Simulation.html");
    int bytesReceived;
    while ((bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytesReceived] = '\0';
        outFile << buffer;
    }
    outFile.close();

    // Step 7: Open HTML file in browser
    system("start Simulation.html");

    // Step 8: Cleanup
    closesocket(clientSocket);
    WSACleanup();

    system("pause");
}
