#include"threadpool.h"
#include<iostream>
using namespace std;
threadpool* threadpool_create(int max_thr_num,int queue_max_size)
{
    threadpool* pool;
    do
    {
        pool=(threadpool*)malloc(sizeof(threadpool));
        if(!pool)
        {
            perror("malloc threadpool failed!");
            break;
        }
        pool->shutdown=false;
        pool->max_thr_num=max_thr_num;
        pool->queue_max_size=queue_max_size;
        pool->queue_size=0;
        pool->threads=(pthread_t*)malloc(sizeof(pthread_t)*max_thr_num);
        if(!pool->threads)
        {
            perror("malloc threads failed!");
            break;
        }
        pool->task_queue=(threadpool_task*)malloc(sizeof(threadpool_task)*queue_max_size);
        if(!pool->task_queue)
        {
            perror("malloc task queue failed!");
            break;
        }
        bool flag=false;
        flag=flag&&pthread_mutex_init(&pool->lock,NULL);
        flag=flag&&pthread_cond_init(&pool->queue_not_empty,NULL);
        flag=flag&&pthread_cond_init(&pool->queue_not_full,NULL);
        if(flag)
        {
            perror("init mutex or condition variable failed!");
            break;
        }
        for(int i=0;i<max_thr_num;i++)
        {
            pthread_create((pool->threads)+i,NULL,threadpool_thread,(void*)pool);
        }
        return pool;
    } while(0); 
    threadpool_free(pool);
    return NULL;
}
void* threadpool_thread(void* pool)
{
    threadpool* p=(threadpool*)pool;
    threadpool_task task;
    while(true)
    {
        pthread_mutex_lock(&p->lock);
        while(p->queue_size==0 && !p->shutdown)
        {
            pthread_cond_wait(&p->queue_not_empty,&p->lock);
        }
        if(p->shutdown)
        {
            pthread_mutex_unlock(&p->lock);
            pthread_exit(NULL);
        }
        task=p->task_queue[(p->queue_head)];
        p->queue_head=(p->queue_head+1)%(p->queue_max_size);
        p->queue_size--;
        pthread_cond_signal(&p->queue_not_full);
        pthread_mutex_unlock(&p->lock);
        (task.func)(task.args);
    }
    return NULL;
}

int threadpool_add_task(threadpool* pool,void*(*func)(void*),void*(args))
{
    threadpool_task task={func,args};
    pthread_mutex_lock(&pool->lock);
    while(pool->queue_max_size==pool->queue_size && !pool->shutdown)
    {
        pthread_cond_wait(&pool->queue_not_full,&pool->lock);
    }
    if(pool->shutdown)
    {
        pthread_mutex_unlock(&pool->lock);
        return -1;
    }
    pool->task_queue[(pool->queue_head+pool->queue_size)%(pool->queue_max_size)]=task;
    pool->queue_size++;
    pthread_cond_signal(&pool->queue_not_empty);
    pthread_mutex_unlock(&pool->lock);
    return 0;
}

void threadpool_free(threadpool* pool)
{
    if(!pool)
    {
        return ;
    }
    pool->shutdown=true;
    pthread_mutex_lock(&pool->lock);
    pthread_cond_broadcast(&pool->queue_not_empty);
    pthread_mutex_unlock(&pool->lock);
    for(int i=0;i<pool->max_thr_num;i++)
    {
        pthread_join(pool->threads[i],NULL);
    }
    free(pool->task_queue);
    free(pool->threads);
    pthread_mutex_destroy(&pool->lock);
    pthread_cond_destroy(&pool->queue_not_empty);
    pthread_cond_destroy(&pool->queue_not_full);
    free(pool);
    pool=NULL;
    return ;
}
