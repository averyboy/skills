#include<bits/stdc++.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/time.h>
#include<unistd.h>
#include<pthread.h>
using namespace std;
const int TCP_PORT=6666;
const int BUF_SIZE=1024;
void* io(void *arg)
{
    int fd=((int*)arg)[0];
    char buf[BUF_SIZE];
    char s[]="over";
    while(true)
    {
        read(fd,buf,sizeof(buf));
        cout<<buf<<endl;
        if(strcmp(buf,s)==0)
        {
            break;
        }
    }
    close(fd);
    return NULL;
}
int main()
{
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
    {
        cout<<"create socket failed!"<<endl;
        return 2;
    }
    sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(TCP_PORT);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    socklen_t servlen=sizeof(servaddr);
    if(bind(sockfd,(struct sockaddr*)&servaddr,servlen)<0)
    {
        cout<<"bind failed!";
        cout<<errno<<endl;
        return 2;
    }
    if(listen(sockfd,10)<0)
    {
        cout<<"listen failed!"<<endl;
        return 2;
    }
    while(true)
    {
        int connfd=accept(sockfd,NULL,NULL);
        if(connfd<0)
        {
            cout<<"connect failed!"<<endl;
            return 2;
        }
        pthread_t tid;
        if(pthread_create(&tid,NULL,io,(void*)&connfd)<0)
        {
            cout<<"create thread failed!"<<endl;
            return 2;
        }
        pthread_detach(pthread_self());
    }
    close(sockfd);
    return 0;
}