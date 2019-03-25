#include<bits/stdc++.h>
#include<sys/select.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/time.h>
using namespace std;
const int BUF_SIZE=1024;

int main()
{
    char buf[BUF_SIZE];
    fd_set rds,tmps;
    timeval t;
    FD_ZERO(&tmps);
    FD_SET(0,&tmps);
    while(true)
    {
        t.tv_sec=3;
        t.tv_usec=0;
        rds=tmps;
        int res=select(1,&rds,NULL,NULL,&t);
        if(res==-1)
        {
            perror("select error!");
            break;
        }
        else if(res==0)
        {
            cout<<"timeout"<<endl;
        }
        else
        {
            if(FD_ISSET(0,&rds))
            {
                int len=read(0,buf,BUF_SIZE);
                cout<<buf;
            }
        }
    }
    return 0;
}