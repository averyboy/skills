#include"threadpool.h"
#include<cstdio>
#include<cstdlib>
#include<cstring>

threadpool_t *threadpool_create(int min_thr_num,int max_thr_num,int queue_max_num)
{
    threadpool_t* pool=NULL;
    do
    {
        if((pool=(threadpool_t*)malloc(sizeof(threadpool_t)))==NULL)
        {
            perror("malloc threadpool failed!");
            break;
        }
        pool->min_thr_num=min_thr_num;
        pool->max_thr_num=max_thr_num;
        pool->busy_thr_num=0;
        pool->live_thr_num=min_thr_num;
        pool->wait_exit_thr_num=0;
        pool->queue_front=0;
        pool->queue_tail=0;
        pool->queue_size=0;
        pool->queue_max_num=queue_max_num;
        pool->shutdown=0;
        if((pool->threads=(pthread_t*)malloc(sizeof(pthread_t)*max_thr_num))==NULL)
        {
            perror("malloc threads failed!");
            break;
        }
        memset(pool->threads,NULL,sizeof(pool->threads));
        pool->task_queue=(threadpool_task*)malloc(sizeof(threadpool_task)*queue_max_num);
        if(!pool->task_queue)
        {
            perror("malloc task_queue failed!");
            break;
        }
        int flag=1;
        flag=flag&&pthread_mutex_init(&(pool->lock),NULL);
        flag=flag&&pthread_mutex_init(&(pool->thread_counter),NULL);
        flag=flag&&pthread_cond_init(&(pool->queue_not_empty),NULL);
        flag=flag&&pthread_cond_init(&(pool->queue_not_full),NULL);
        if(!flag)
        {
            perror("init mutex or cond failed!");
            break;
        }
        for(int i=0;i<min_thr_num;i++)
        {
            pthread_create((pool->threads)+i,NULL,threadpool_thread,(void*)pool);
        }
        pthread_create(&(pool->admin_thread),NULL,threadpool_admin,(void*)pool);
        return pool;
    } while (0);
    threadpool_free(pool);
    return NULL;
}

void* threadpool_thread(void* threadpool)
{
    threadpool_t* pool=(threadpool_t*)threadpool;
    threadpool_task task;
    while(true)
    {
        pthread_mutex_lock(&(pool->lock));
        while((pool->queue_size==0) && !(pool->shutdown))
        {
            pthread_cond_wait(&(pool->queue_not_empty),&(pool->lock));
        }
    }
}