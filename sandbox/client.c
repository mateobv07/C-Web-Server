#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s <ip of the host>\n", argv[0]);
        return 0;
    }
    struct sockaddr_in serverInfo = {0};
    serverInfo.sin_family = AF_INET;
    serverInfo.sin_addr.s_addr = inet_addr(argv[1]);
    serverInfo.sin_port = htons(5555);

    int fd = socket(PF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        return -1;
    }
    // Connect
    if (connect(fd, (struct sockaddr*)&serverInfo, sizeof(serverInfo)) == -1) {
        perror("connect");
        close(fd);
        return -1;
    }
    close(fd);
}

