#include<pthread.h>
#include<cstdlib>
#include<cstdio>
#include<unistd.h>
#include<cstring>
struct threadpool_task
{
    void*(*func)(void*);
    void* args;
};
struct threadpool
{
    int max_thr_num;
    int queue_max_size;
    int queue_size;
    int queue_head;
    pthread_t *threads;
    threadpool_task* task_queue;
    pthread_mutex_t lock;
    pthread_cond_t queue_not_empty;
    pthread_cond_t queue_not_full;
    bool shutdown;
};
threadpool* threadpool_create(int max_thr_num,int queue_size);
void* threadpool_thread(void* pool);
int threadpool_add_task(threadpool* pool,void*(*func)(void*),void*(args));
void threadpool_free(threadpool* pool);
