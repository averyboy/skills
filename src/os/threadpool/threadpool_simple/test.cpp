#include"threadpool.h"
#include<bits/stdc++.h>
using namespace std;
void* func(void* args)
{
    char* str=(char*)(args);
    cout<<"thread_id"<<pthread_self()<<endl;
    cout<<"Hello,"<<str<<endl;
    return NULL;
}
int main()
{
    threadpool* pool=threadpool_create(10,10);
    threadpool_add_task(pool,func,(void*)"???");
    threadpool_free(pool);
    return 0;
}