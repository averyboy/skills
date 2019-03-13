#include<bits/stdc++.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
using namespace std;
const int TCP_PORT=6666;
const int BUF_SIZE=1024;
int main(int aargc,char* argv[])
{
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
    {
        cout<<"create socket failed"<<endl;
        return 1;
    }
    sockaddr_in cliaddr;
    memset(&cliaddr,0,sizeof(cliaddr));
    cliaddr.sin_family=AF_INET;
    cliaddr.sin_port=htons(TCP_PORT);
    cliaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    socklen_t clilen=sizeof(cliaddr);
    if(connect(sockfd,(sockaddr*)&cliaddr,clilen)<0)
    {
        cout<<"connect failed!"<<endl;
        return 1;
    }
    while(true)
    {
        char buf[BUF_SIZE];
        char s[]="over";
        scanf("%s",buf);
        write(sockfd,buf,strlen(buf)+1);
        if(strcmp(buf,s)==0)
        {
            cout<<"over"<<endl;
            break;
        }
    }
    close(sockfd);
    return 0;
}