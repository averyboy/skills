#include "pool.h"
#include<cstdio>
#include<cstdlib>
#include<unistd.h>

void* work(void* arg)
{
    char *p = (char*) arg;
    printf("threadpool callback fuction : %s.\n", p);
    sleep(1);
}

int main(void)
{
    struct threadpool *pool = threadpool_init(10, 20);
    threadpool_add_job(pool, work, (void*)"1");
    threadpool_add_job(pool, work, (void*)"2");
    threadpool_add_job(pool, work, (void*)"3");
    threadpool_add_job(pool, work, (void*)"4");
    threadpool_add_job(pool, work, (void*)"5");
    threadpool_add_job(pool, work, (void*)"6");
    threadpool_add_job(pool, work, (void*)"7");
    threadpool_add_job(pool, work, (void*)"8");
    threadpool_add_job(pool, work, (void*)"9");
    threadpool_add_job(pool, work, (void*)"10");
    threadpool_add_job(pool, work, (void*)"11");
    threadpool_add_job(pool, work, (void*)"12");
    threadpool_add_job(pool, work, (void*)"13");
    threadpool_add_job(pool, work, (void*)"14");
    threadpool_add_job(pool, work, (void*)"15");
    threadpool_add_job(pool, work, (void*)"16");
    threadpool_add_job(pool, work, (void*)"17");
    threadpool_add_job(pool, work, (void*)"18");
    threadpool_add_job(pool, work, (void*)"19");
    threadpool_add_job(pool, work, (void*)"20");
    threadpool_add_job(pool, work, (void*)"21");
    threadpool_add_job(pool, work, (void*)"22");
    threadpool_add_job(pool, work, (void*)"23");
    threadpool_add_job(pool, work, (void*)"24");
    threadpool_add_job(pool, work, (void*)"25");
    threadpool_add_job(pool, work, (void*)"26");
    threadpool_add_job(pool, work, (void*)"27");
    threadpool_add_job(pool, work, (void*)"28");
    threadpool_add_job(pool, work, (void*)"29");
    threadpool_add_job(pool, work, (void*)"30");
    threadpool_add_job(pool, work, (void*)"31");
    threadpool_add_job(pool, work, (void*)"32");
    threadpool_add_job(pool, work, (void*)"33");
    threadpool_add_job(pool, work, (void*)"34");
    threadpool_add_job(pool, work, (void*)"35");
    threadpool_add_job(pool, work, (void*)"36");
    threadpool_add_job(pool, work, (void*)"37");
    threadpool_add_job(pool, work, (void*)"38");
    threadpool_add_job(pool, work, (void*)"39");
    threadpool_add_job(pool, work, (void*)"40");

    sleep(5);
    threadpool_destroy(pool);
    return 0;
}