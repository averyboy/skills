#include "stdio.h"
//socket相关函数需要
#include <sys/types.h>
#include <sys/socket.h>
//close函数需要
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <errno.h>
#include <arpa/inet.h>
#include <thread>
#include <iostream>
#include "SocketThread.h"
using namespace std;

#define MAXLINE 1024

int main(int argc,char ** argv){
        int connfd;
        char buff[MAXLINE];
        int n;
        //创建一个socket
        int sock=socket(AF_INET,SOCK_STREAM,0);
        if(sock==-1) {
                printf("create socket failed\n" );
        }
        //监听的端口
        unsigned short bindPort=8888;
        if(argc>=2) {
                //如果外部自定义了端口，则用外部自定义的端口
                bindPort=atoi(argv[1]);
        }
        printf("create socket success! %d\n", sock);
        struct sockaddr_in sockaddr;
        memset(&sockaddr,0,sizeof(sockaddr));
        sockaddr.sin_family=AF_INET;
        sockaddr.sin_addr.s_addr=htonl(INADDR_ANY);
        sockaddr.sin_port=htons(bindPort);
        //开始绑定
        //这里要注意要使用::  这样就调用的全局的bind函数，而不是std中的bind
        ::bind(sock,(struct sockaddr *)&sockaddr,sizeof(sockaddr));
        //监听，最多支持10个连接
        listen(sock,10);
        char cilentIp[20];
        while (true) {
                /* code */
                struct sockaddr_in sockaddrClient;
                int clientl=sizeof(sockaddrClient);
                printf("wait for client connect\n" );
                //不关心客户端的信息
                // if((connfd = accept(sock,NULL,NULL))==-1) {
                //接受客户端连接的同时，获取客户端的信息
                if((connfd = accept(sock,(struct sockaddr*)&sockaddrClient,(socklen_t *)&clientl))==-1) {
                        printf("accpet socket error: %s errno :%d\n",strerror(errno),errno);
                }
                //获取端口
                unsigned short port= ntohs(sockaddrClient.sin_port);
                //网络Ip=>主机Ip
                const char *ip=inet_ntop(AF_INET,(void *)&sockaddrClient.sin_addr,cilentIp,16);
                printf("client %s:%d\n",cilentIp,port);
                //使用线程
                SocketThread* st=new SocketThread(connfd);
                thread t(&SocketThread::run,st);
                t.detach();
        }
        int ret=close(sock);
        if(ret==-1) {
                printf("socket close failed\n");
        }else{
                printf("%d close success!\n",sock );
        }
        return 0;
}