#include<bits/stdc++.h>
#include<functional>
#include<mutex>
#include<condition_variable>
using namespace std;
class Threadpool
{
public:
    Threadpool(int num_threads=1):pool(make_shared<Pool>())
    {
        pool->shutdown=false;
        for(int i=0;i<num_threads;i++)
        {
            thread([=]{
                unique_lock<mutex> lk(pool->mtx);
                while(true)
                {
                    while(pool->task.empty() && !pool->shutdown)
                    {
                        pool->cond.wait(lk);
                    }
                    if(pool->shutdown)
                    {
                        break;
                    }
                    auto _task=move(pool->task.front());
                    pool->task.pop();
                    lk.unlock();
                    _task();
                    lk.lock();
                }
            }).detach();
        }
    }
    Threadpool(Threadpool&&)=default;
    ~Threadpool()
    {
        if(pool)
        {
            lock_guard<mutex>(pool->mtx);
            pool->shutdown=true;
        }
        pool->cond.notify_all();
    }
    template<class T>
    void execute(T&& task)
    {
        {
            lock_guard<mutex> lk(pool->mtx);
            pool->task.emplace(forward<T>(task));
        }
        pool->cond.notify_one();
    }
private:
    struct Pool{
        queue<function<void()> > task;
        mutex mtx;
        condition_variable cond;
        bool shutdown;
    };
    shared_ptr<Pool> pool;
};