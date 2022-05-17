#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>


int main(int argc, char * argv[]) {
    int portnumber = atoi(argv[1]);

    int sock_decs, client, bind_decs, recieve;

    struct sockaddr_in server_addr, client_addr;
    char message[80];

    sock_decs = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_decs < 0) {
        printf("Socket failed\n");
        exit(sock_decs);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portnumber);
    server_addr.sin_addr.s_addr = inet_addr("172.19.49.101");

    bind_decs = bind(sock_decs, (struct sockaddr *) &server_addr, sizeof(server_addr));

    if (bind_decs < 0) {
        printf("Bind failed\n");
        exit(bind_decs);
    }

    listen(sock_decs, 3);

    int client_size = sizeof(client_addr);
    int client_socket = accept(sock_decs, (struct sockaddr*) &client_addr, &client_size);
    printf("Client connected at IP: %s and port: %i\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while (recv(client_socket, message, sizeof(message), 0)) {
        printf("%s", message);
    }

    close(client_socket);
    close(sock_decs);

}
