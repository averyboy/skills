#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#define MAXLINE 1024
int main(int argc,char **argv)
{
        //连接的地址
        const char *servInetAddr = "127.0.0.1";
        int socketfd;
        struct sockaddr_in sockaddr;
        char recvline[MAXLINE], sendline[MAXLINE];
        int n;
        unsigned short port=8888;
        if(argc >= 2)
        {
                //端口号由外部传入
                port=atoi(argv[1]);
        }
        socketfd = socket(AF_INET,SOCK_STREAM,0);
        memset(&sockaddr,0,sizeof(sockaddr));
        sockaddr.sin_family = AF_INET;
        sockaddr.sin_port = htons(port);
        //主机Ip=>网络Ip
        inet_pton(AF_INET,servInetAddr,&sockaddr.sin_addr);
        //连接服务端
        if((connect(socketfd,(struct sockaddr*)&sockaddr,sizeof(sockaddr))) < 0 )
        {
                printf("connect error :[%s] errno: %d\n",strerror(errno),errno);
                exit(0);
        }
        printf("send message to server\n");
        int cmp=0;
        while(true) {
                printf("input your mssage\n");
                fgets(sendline,1024,stdin);
                //判断输入，如果是exit则退出并关闭连接
                int cmp=strcmp(sendline,"exit\n");
                if(cmp==0) {
                        break;
                }
                //发送数据。
                if((send(socketfd,sendline,strlen(sendline),0)) < 0)
                {
                        printf("send mes error: [%s] errno : %d",strerror(errno),errno);
                        exit(0);
                }
                memset(sendline,0,sizeof(sendline));
        }
        close(socketfd);
        printf("exit\n");
        exit(0);
}