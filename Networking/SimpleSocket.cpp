 #include "SimpleSocket.h"

// Default contructor.
HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface) {
    // Define address structure
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    // Establish SOCKET.
    sock = socket(domin, service, protocol);
    test_connection(sock);
}

// Test connection virtual function.
 void HDE::SimpleSocket::test_connection(int item_to_test) {
    // Confirm that the socket or connection has been properly established.
    if (item_to_test < 0) {
        perror("Failed to connect...");
        exit(EXIT_FAILURE);
    }
 }

struct sockaddr_in HDE::SimpleSocket::get_address(){
    return this->address;
}
int HDE::SimpleSocket::get_sock(){
    return this->sock;
}
int HDE::SimpleSocket::get_connection(){
    return this->connection;
}

int HDE::SimpleSocket::set_connection(int connection) {
    this->connection = connection;
}