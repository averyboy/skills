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
}