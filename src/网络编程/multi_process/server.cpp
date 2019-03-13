#include<bits/stdc++.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/time.h>
using namespace std;
const int BUF_SIZE=1024;
const int TCP_PORT=6666;
int main()
{
    char s[]="over";
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    servaddr.sin_port=htons(TCP_PORT);
    socklen_t len =sizeof(servaddr);
    bind(sockfd,(struct sockaddr*)&servaddr,len);
    listen(sockfd,10);
    while(true)
    {
        sockaddr_in cliaddr;
        socklen_t len_cli=sizeof(cliaddr);
        int connfd=accept(sockfd,(struct sockaddr*)&cliaddr,&len_cli);
        if(connfd==-1)
        {
            cout<<"accept failed!"<<endl;
            exit(2);
        }
        int pid=fork();
        if(pid==-1)
        {
            cout<<"fork failed!"<<endl;
            exit(2);
        }
        if(pid==0)
        {
            while(true)
            {
                char buf[BUF_SIZE];
                int sz=recv(connfd,buf,sizeof(buf),0);
                // buf[sz]=0;
                cout<<"sz: "<<sz<<endl;
                if(strcmp(buf,s)==0)
                {
                    cout<<"over!"<<endl;
                    break;
                }
                cout<<buf<<endl;
            }
            close(connfd);
        }
        else
        {
            close(connfd);
        }
    }
    close(sockfd);
    return 0;
}