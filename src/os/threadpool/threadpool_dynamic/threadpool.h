#include<pthread.h>
struct threadpool_task
{
    void*(*func)(void*);
    void* args;
};
struct threadpool_t
{
    pthread_mutex_t lock;
    pthread_mutex_t thread_counter;
    pthread_cond_t queue_not_empty;
    pthread_cond_t queue_not_full;

    pthread_t* threads;
    pthread_t admin_thread;
    threadpool_task* task_queue;

    int min_thr_num;
    int max_thr_num;
    int live_thr_num;
    int busy_thr_num;
    int wait_exit_thr_num;

    int queue_front;
    int queue_tail;
    int queue_size;
    int queue_max_num;

    int shutdown;
};

threadpool_t* threadpool_create(int min_thr_num,int max_thr_num,int queue_max_num);
void* threadpool_thread(void* threadpool);
int threadpool_add_task(threadpool_t* pool,void*(*func)(void* args));
void* threadpool_admin(void* pool);
int threadpool_free(threadpool_t* pool);
int threadpool_destory(threadpool_t* pool);
