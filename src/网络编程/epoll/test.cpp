#include <stdio.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <iostream>
using namespace std;
const int BUF_SIZE=1024;
int main(void)
{
    char buf[BUF_SIZE];
    int epfd,nfds;
    struct epoll_event ev,events[5]; //ev用于注册事件，数组用于返回要处理的事件
    epfd = epoll_create(1); //只需要监听一个描述符——标准输入
    ev.data.fd = STDIN_FILENO;
    ev.events = EPOLLIN|EPOLLET; //监听读状态同时设置ET模式
    epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &ev); //注册epoll事件
    while(true)
    {
        nfds = epoll_wait(epfd, events, 5, 3000);
        if(nfds==-1)
        {
            perror("epoll error!");
            break;
        }
        else if(nfds==0)
        {
            cout<<"timeout"<<endl;
        }
        else
        {
            for(int i = 0; i < nfds; i++)
            {
                if(events[i].data.fd==STDIN_FILENO)
                {
                    int len=read(STDIN_FILENO,buf,BUF_SIZE);
                    buf[len]=0;
                    cout<<buf;
                }
            }   
        }
    }
    return 0;
}