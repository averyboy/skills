#include<bits/stdc++.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
const int TCP_PORT=6666;
using namespace std;
void ssendmsg(int fd)
{
    for(int i=0;i<10;i++)
    {
        char buffer[100];
        sprintf(buffer,"message from server %d of 10",i);
        // cout<<buffer<<endl;
        write(fd,buffer,sizeof(buffer));
    }
    return ;
}
int main()
{
    int sock_lis=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in  ser_add;
    memset(&ser_add,0,sizeof(ser_add));
    ser_add.sin_family=AF_INET;
    ser_add.sin_addr.s_addr=inet_addr("127.0.0.1");
    ser_add.sin_port=htons(TCP_PORT);
    ::bind(sock_lis,(struct sockaddr*)&ser_add,sizeof(ser_add));
    listen(sock_lis,1024);
    struct sockaddr_in cli_add;
    socklen_t cli_addr_len=sizeof(cli_add);
    while(true)
    {
        int sock_con=accept(sock_lis,(struct sockaddr*)&cli_add,&(cli_addr_len));
        if(sock_con<0)
        {
            cout<<"connect failed!"<<endl;
            break;
        }
        else
        {
            int pid;
            while((pid=fork())==-1);
            // cout<<"pid"<<pid<<endl;
            if(!pid)
            {
                ssendmsg(sock_con);
            }
        }
        close(sock_con);
    }
    return 0;
}