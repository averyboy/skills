#include<pthread.h>
struct Job
{
    void* (*func)(void *arg);//回调函数
    void *arg;//参数
    Job* next;
};
struct ThreadPool
{
    int num_thread;//最大线程数目
    int queue_max_job_num;//最大任务数目
    Job* head;//任务头指针
    Job* tail;//任务尾指针
    pthread_t* pthrads;//线程队列
    pthread_mutex_t mutex;//互斥信号量
    pthread_cond_t queue_empty;//队列为空的条件变量
    pthread_cond_t queue_not_empty;//队列不为空的条件变量
    pthread_cond_t queue_not_full;//队列不满的条件变量
    int queue_cur_num_job;//目前的任务数
    int queue_close;//队列是否关闭
    int pool_close;//进程池是否已经关闭
};
ThreadPool* threadpool_init(int thread_num,int queue_max_job_num);//初始化线程池
int threadpool_add_job(ThreadPool* pool,void* (*func)(void*),void* arg);//向线程池中添加任务
void* func(void* arg);//线程函数
int threadpool_destroy(ThreadPool* pool);
