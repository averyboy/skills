#include "threadpool.h"
#include<errno.h>
#include<stdio.h>
// #include<bits/stdc++.h>
ThreadPool* threadpool_init(int num_thread,int queue_max_job_num)
{
    if(num_thread  <=0 || queue_max_job_num<=0)
    {
        perror("invalid input args!");
        return NULL;
    }
    ThreadPool* pool=new ThreadPool();
=======
#include<pthread.h>
#include<cstdio>
#include<cstdlib>
ThreadPool* threadpool_init(int num_thread,int queue_max_job_num)
{
    if(num_thread<=0 || queue_max_job_num<=0)
    {
        perror("invalid args!");
        return NULL;
    }
    ThreadPool *pool=(ThreadPool*)malloc(sizeof(ThreadPool));
    if(NULL==pool)
    {
        perror("cannot to malloc threadpool!");
        return NULL;
    }
    pool->num_thread=num_thread;
    pool->queue_max_job_num=queue_max_job_num;
    pool->queue_cur_num_job=0;
    pool->head=NULL;
    pool->tail=NULL;
    if(pthread_mutex_init(&(pool->mutex),NULL))
    {
        perror("failed to init mutex!");
        free(pool);
        pool=NULL;
        return NULL;
    }
    if(pthread_cond_init(&(pool->queue_empty),NULL))
    {
        perror("failed to init queue_empty!");
        free(pool);
        pool=NULL;
        return NULL;
    }
    if(pthread_cond_init(&(pool->queue_not_empty),NULL))
    {
        perror("failed to init queue_not_empty!");
        free(pool);
        pool=NULL;
        return NULL;
    }
    if(pthread_cond_init(&()))
