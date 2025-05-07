# UDP Simulation

This is a basic simulation of the **User Datagram Protocol (UDP)**. It demonstrates how a connectionless data transfer works, where the server receives datagrams from a client without establishing a persistent connection.

![Result](02-UDP/Result)

## How to Run the Simulation

### 1. **UDP Server**
   - Compile the Server:
     ```bash
     g++ UDP/UDP_Server.cpp -o UDP_Server -lws2_32
     ```
   - Run the Server:
     ```bash
     ./UDP_Server
     ```

### 2. **UDP Client**
   - Compile the Client:
     ```bash
     g++ UDP/UDP_Client.cpp -o UDP_Client -lws2_32
     ```
   - Run the Client:
     ```bash
     ./UDP_Client
     ```

## Contributions
Feel free to fork this repository and contribute by adding simulations for other network protocols or enhancing existing ones.

## License
MIT License
