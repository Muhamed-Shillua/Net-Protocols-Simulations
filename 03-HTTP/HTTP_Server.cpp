#include <iostream>
#include <string>
#include <winsock2.h>
#include <fstream>
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
        cout << "WSAStartup failed.\n";
        return 1;
    }

    // Create a socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        cout << "Socket creation failed.\n";
        WSACleanup();
        return 1;
    }

    // Define server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9090);             // Port 9090
    serverAddr.sin_addr.s_addr = INADDR_ANY;       // Accept any incoming address

    // Bind the socket to the address and port
    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cout << "Binding failed.\n";
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
        cout << "Client connection failed.\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "Client connected.\n";

    // Read the HTML file content
    ifstream htmlFile("Simulation.html");
    string htmlContent((istreambuf_iterator<char>(htmlFile)), istreambuf_iterator<char>());

    // Construct the HTTP response headers + body
    string response = "HTTP/1.1 200 OK\r\n";
    response += "Content-Type: text/html\r\n";
    response += "Content-Length: " + to_string(htmlContent.size()) + "\r\n";
    response += "Connection: close\r\n";
    response += "\r\n"; // End of headers
    response += htmlContent; // HTML page content

    // Send the full HTTP response to the client
    send(clientSocket, response.c_str(), response.size(), 0);

    // Close the sockets and cleanup
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    system("pause");
}
