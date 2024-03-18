#include "ConnectingSocket.h"

HDE::ConnectingSocket::ConnectingSocket(int domain, int service, int protocol,
    int port, u_long interface) :
    SimpleSocket(domain, service, protocol, port, interface); {
    // Establish network connection.
    set_connection(connect_to_network(get_sock(), get_address()));
    test_connection(get_connection());
}

HDE::ConnectingSocket::connect_to_network(int sock, struct stockaddr_in address){
    return connect(sock, (struct sockaddr *)&address, sizeof(address));
}