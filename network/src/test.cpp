#include<bits/stdc++.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
using namespace std;
int main()
{
    int fd=open("./test.out",O_RDWR|O_CREAT,0600);
    write(fd,"HELLO WORLD!",12);
    char buf[10]={0};
    lseek(fd, 0, SEEK_SET);
    read(fd,buf,9);
    cout<<buf<<endl;
    close(fd);
    return 0;
}