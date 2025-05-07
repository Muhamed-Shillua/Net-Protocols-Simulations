// UDP_Server.cpp
#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    WSADATA wsaData;
    SOCKET serverSocket;
    sockaddr_in serverAddr, clientAddr;
    int clientLen = sizeof(clientAddr);
    char buffer[1024];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "WSAStartup Failed.\n";
        return 1;
    }

    // Create UDP socket
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        cout << "Socket creation Failed.\n";
        WSACleanup();
        return 1;
    }

    // Configure server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8888);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cout << "Binding Failed.\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "Waiting for Messages...\n";

    // Receive message
    int bytesReceived = recvfrom(serverSocket, buffer, sizeof(buffer) - 1, 0, (sockaddr*)&clientAddr, &clientLen);
    if (bytesReceived == SOCKET_ERROR) {
        cout << "Recvfrom() Failed.\n";
    }
    else {
        buffer[bytesReceived] = '\0';  // Null-terminate
        cout << "Received: " << buffer << endl;
    }

    closesocket(serverSocket);
    WSACleanup();
    

    system("pause");
}
