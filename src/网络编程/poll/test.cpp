#include<sys/poll.h>
#include<cstdio>
#include<sys/types.h>
#include<unistd.h>
#include<iostream>
using namespace std;
const int BUF_SIZE=1024;
char buf[BUF_SIZE];
int main()
{
    pollfd pfd[1];
    pfd[0].events=POLLIN;
    pfd[0].fd=0;
    while(true)
    {
        int res=poll(pfd,1,3000);
        if(res==-1)
        {
            perror("poll error!");
            break;
        }
        else if(res==0)
        {
            cout<<"timeout!"<<endl;
        }
        else
        {
            if(pfd[0].revents&POLLIN)
            {
                int len=read(0,buf,3);
                buf[len]=0;
            }
        }
    }
    return 0;
}