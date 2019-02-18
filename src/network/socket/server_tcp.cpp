#include<bits/stdc++.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
using namespace std;
const int TCP_PORT=6666;
int main()
{
    int server_socket=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server_addr;
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    server_addr.sin_port=htons(TCP_PORT);
    bind(server_socket,(struct sockaddr*)&server_addr,sizeof(server_addr));
    listen(server_socket,20);
    struct sockaddr_in clinet_addr;
    socklen_t client_addr_size=sizeof(clinet_addr);
    int client_socket=accept(server_socket,(struct sockaddr*)&client_socket,&client_addr_size);
    char buffer[]="Hello World!";
    write(client_addr_size,buffer,sizeof(buffer));
    close(client_socket);
    close(server_socket);
    return 0;
}