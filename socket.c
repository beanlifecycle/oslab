// socket client

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    int cli_sfd, nbytes;
    socklen_t addr_size;
    char buffer[1024];
    struct sockaddr_in serverAddr;

    cli_sfd = socket(AF_INET, SOCK_DGRAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8084); 
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
    addr_size = sizeof(serverAddr);

    while (1) {
        write(1, "CLIENT> ", 8);
        fgets(buffer, 1024, stdin);
        sendto(cli_sfd, buffer, strlen(buffer), 0, (struct sockaddr *)&serverAddr, addr_size);
        nbytes = recvfrom(cli_sfd, buffer, 1024, 0, (struct sockaddr *)&serverAddr, &addr_size);
        buffer[nbytes] = '\0';
        printf("SERVER> %s\n", buffer);
    }

    return 0;
}


// socket server

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    int ser_sfd, nbytes, addr_len;
    char buffer[1024];
    struct sockaddr_in servaddr, clientaddr;

    ser_sfd = socket(AF_INET, SOCK_DGRAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[1]));
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    bind(ser_sfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    addr_len = sizeof(clientaddr);

    while (1) {
        nbytes = recvfrom(ser_sfd, buffer, 1024, 0, (struct sockaddr *)&clientaddr, &addr_len);
        write(1, "CLIENT> ", 8);
        write(1, buffer, nbytes);
        write(1, "SERVER> ", 9);
        fgets(buffer, 1024, stdin);
        sendto(ser_sfd, buffer, strlen(buffer), 0, (struct sockaddr *)&clientaddr, addr_len);
    }

    return 0;
}
