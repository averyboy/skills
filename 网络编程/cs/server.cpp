#include<bits/stdc++.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/time.h>
#include<unistd.h>
#include<netinet/in.h>

using namespace std;
const int TCP_PORT=6666;
const int BUF_SIZE=1024;
void init()
{
    return ;
}
int main()
{
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    servaddr.sin_port=htons(TCP_PORT);
    socklen_t len=sizeof(servaddr);
    bind(sockfd,(struct sockaddr*)&servaddr,len);
    listen(sockfd,10);
    int connfd=accept(sockfd,NULL,NULL);
    char s[]="over";
    while(true)
    {
        char buf[BUF_SIZE];
        read(connfd,buf,sizeof(buf));
        cout<<buf<<endl;
        if(strcmp(buf,s)==0)
            break;
    }
    close(connfd);
    close(sockfd);
    return 0;
}