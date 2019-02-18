#include<bits/stdc++.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
using namespace std;
const int TCP_PORT=6666;
int main()
{
    int client_socket=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server_addr;
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    server_addr.sin_port=htons(TCP_PORT);
    connect(client_socket,(struct sockaddr*)&server_addr,sizeof(server_addr));
    char buffer[1024];
    read(client_socket,buffer,sizeof(buffer)-1);
    cout<<buffer<<endl;
    close(client_socket);
    return 0;
}