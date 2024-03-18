#include "BindingSocket.h"

HDE::BindingSocket::BindingSocket(int domain, int service, int protocol,
    int port, u_long interface) :
    SimpleSocket(domain, service, protocol, port, interface); {
    // Establish network connection.
    set_connection(connect_to_network(get_sock(), get_address()));
    test_connection(get_connection());
}

HDE::BindingSocket::connect_to_network(int sock, struct stockaddr_in address){
    return bind(sock, (struct sockaddr *)&address, sizeof(address));
}