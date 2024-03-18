#ifndef BindingSocket_h
#define BindingSocket_h
#include <stdio.h>
#include <iostream>

#include "SimpleSocket.h"

namespace HDE {
    class BindingSocket: public SimpleSocket  {
        public: {
            BindingSocket(int domain, int service, int protocol,
            int port, u_long interface);

            int connect_to_network(int sock, struct stockaddr_in address);
        }
    }
}