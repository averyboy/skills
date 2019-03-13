#include<bits/stdc++.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/time.h>
const int TCP_PORT=6666;
const int BUF_SIZE=1024;
using namespace std;
int main()
{
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    sockaddr_in cliaddr;
    memset(&cliaddr,0,sizeof(cliaddr));
    cliaddr.sin_family=AF_INET;
    cliaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    cliaddr.sin_port=htons(TCP_PORT);
    socklen_t len=sizeof(cliaddr);
    if(connect(sockfd,(sockaddr*)&cliaddr,len)<0)
    {
        cout<<"connect failed!"<<endl;
        exit(2);
    }
    char buf[BUF_SIZE];
    char s[]="over";
    while(true)
    {
        cout<<"send: ";
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)-1]=0;
        write(sockfd,buf,strlen(buf));
        if(strcmp(buf,s)==0)
        {
            cout<<"over!"<<endl;
            break;
        }
    }
    close(sockfd);
    return 0;
}