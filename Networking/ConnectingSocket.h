#ifndef BindingSocket_h
#define BindingSocket_h
#include <stdio.h>
#include <iostream>

#include "SimpleSocket.h"

namespace HDE {
    class ConnectingSocket: public SimpleSocket {
        ConnectingSocket(int domain, int service, int protocol,
            int port, u_long interface);

        int connect_to_network(int sock, struct stockaddr_in address);
    }
}