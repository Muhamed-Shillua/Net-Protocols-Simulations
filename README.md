
# Network Protocols Simulations

This repository contains simulations of various networking protocols. Each protocol has its own folder with separate client and server implementations, as well as a README file explaining the protocol and its usage.

## Protocols Included

- **TCP**
- **UDP**
- **HTTP**
- **FTP**

Each protocol folder contains:
- **Client Code**: Simulates a client-side connection to the server.
- **Server Code**: Handles incoming client connections and responses.
- **README.md**: Provides detailed information about the protocol and instructions for usage.

## Directory Structure

```plaintext
Network_Protocols_Simulations/
    ├── TCP/
    │   ├── TCP_Client.cpp
    │   ├── TCP_Server.cpp
    │   └── README.md  <-- TCP protocol documentation
    ├── UDP/
    │   ├── UDP_Client.cpp
    │   ├── UDP_Server.cpp
    │   └── README.md  <-- UDP protocol documentation
    ├── HTTP/
    │   ├── HTTP_Client.cpp
    │   ├── HTTP_Server.cpp
    │   └── README.md  <-- HTTP protocol documentation
    ├── FTP/
    │   ├── FTP_Client.cpp
    │   ├── FTP_Server.cpp
    │   └── README.md  <-- FTP protocol documentation
    └── README.md  <-- Main repository documentation
```

## How to Run the Simulations

### Prerequisites
- **Windows Operating System** (since the code uses Winsock2 for socket programming)
- **Visual Studio** or any other C++ compiler that supports Winsock2.

### Setup
1. Clone the repository to your local machine:
    ```bash
    git clone https://github.com/Muhamed-Shillua/Net_Protocols_Simulation.git
    cd Net_Protocols_Simulation
    ```

2. Navigate to the desired protocol folder (e.g., TCP):
    ```bash
    cd TCP
    ```

3. Compile the client and server code using your C++ compiler (Visual Studio, GCC, etc.). In Visual Studio, simply open the `.cpp` files and compile them.

4. Run the **server** first, and then run the **client**:
    - **Server**: Execute `TCP_Server.exe` (or equivalent).
    - **Client**: Execute `TCP_Client.exe` (or equivalent).

5. You should see a message indicating the connection between the client and server.

### Protocol Details
Each protocol folder contains a `README.md` file explaining the protocol, its use cases, and additional details about the implementation.

- **TCP**: Simulates a simple client-server connection using the TCP protocol.
- **UDP**: Demonstrates a client-server connection with the UDP protocol (connectionless).
- **HTTP**: Implements a basic HTTP request-response simulation.
- **FTP**: Simulates file transfer using the FTP protocol.

## Contributing
Feel free to fork this repository and create pull requests with improvements, new protocol simulations, or bug fixes. Contributions are welcome!

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact
For any questions, feel free to reach out to me at: shilluamuhamed@egmail.com
