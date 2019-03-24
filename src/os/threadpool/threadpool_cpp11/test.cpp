#include"threadpool.h"
#include<unistd.h>
mutex mtx;
int main()
{
    Threadpool pool(10);
    pool.execute([=]{mtx.lock();cout<<this_thread::get_id()<<endl;cout<<"Helloworld 1"<<endl;mtx.unlock();});
    pool.execute([=]{mtx.lock();cout<<this_thread::get_id()<<endl;cout<<"Helloworld 2"<<endl;mtx.lock();});
    sleep(2);
    return 0;
}