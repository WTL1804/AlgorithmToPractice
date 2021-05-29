//
//  main.cpp
//  生产者消费者
//
//  Created by 王天亮 on 2020/10/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#define M 10
#define P(x) sem_wait(x)
#define V(x) sem_post(x)
int in = 0;
int out = 0;
int buff[M] = {0};
sem_t *emptySem;
sem_t *fullSem;
sem_t *buffSem;
pthread_mutex_t mutex;
void print() {
    int i;
    for(i = 0; i < M; i++)
        printf("%d ", buff[i]);
    printf("\n");
}
void sem_mutex_init() {
    emptySem = sem_open("yoursemss",O_CREAT|O_EXCL, S_IRUSR | S_IWUSR, M); //初始化信号量为32
    fullSem = sem_open("yoursemdd",O_CREAT|O_EXCL, S_IRUSR | S_IWUSR, 0);//初始值为0，小于0会阻塞
    buffSem = sem_open("buffsemdd",O_CREAT|O_EXCL, S_IRUSR | S_IWUSR, 1);//初始值为0，小于0会阻塞
//    emptySem = sem_init(&emptySem, 0, M);
//    fullSem = sem_init(&emptySem, 0, 0);
    int init3 = pthread_mutex_init(&mutex, NULL);
    if(init3 != 0)
    {
       printf("mutex init failed \n");
       exit(1);
    }
}
void *producer(void *) {
    for(;;) {
        sleep(1);
        P(emptySem);
        P(buffSem);
//        pthread_mutex_lock(&mutex);
        in = in % M;
//        printf("%p", pthread_self());
        printf("(+)produce a product. buffer:");
        buff[in] = 1;
        print();
        ++in;
       // pthread_mutex_unlock(&mutex);
        V(fullSem);
        V(buffSem);

    }
    return 0;
}
void *consumer(void *) {
    for(;;) {
        sleep(2);
//
//        P(fullSem);
//        P(buffSem);
//        pthread_mutex_lock(&mutex);
//        P(fullSem);
//        pthread_mutex_lock(&cust);
        out = out % M;
//        printf("%p", pthread_self());
        printf("(-)consume a product. buffer:");
        buff[out] = 0;
        print();
        ++out;
       // pthread_mutex_unlock(&mutex);
//        V(emptySem);
//        V(buffSem);
    }
    return 0;
}
//单生产者、单消费者
void proAndConsumer(void) {
    pthread_t id1;
    pthread_t id2;
    int ret;

    sem_mutex_init();

    /*create the producer thread*/
    ret = pthread_create(&id1, NULL, producer, NULL);
    if(ret != 0)
    {
        printf("producer creation failed \n");
        exit(1);
    }

    /*create the consumer thread*/
    ret = pthread_create(&id2, NULL, consumer, NULL);
    if(ret != 0)
    {
        printf("consumer creation failed \n");
        exit(1);
    }

    pthread_join(id1,NULL);
    pthread_join(id2,NULL);
//    sem_close(emptySem);
//    sem_close(fullSem);
//    sem_unlink("yoursemss");
//    sem_unlink("yoursemdd");

    exit(0);
}
////多生产者、多消费者
//#define PTHREAD_NUM 10
//int main(void) {
//    pthread_t id1;
//    pthread_t id2;
//    int ret;
//
//    sem_mutex_init();
//
//    pthread_t pthread[PTHREAD_NUM];
//    void *retval[PTHREAD_NUM];
//    for (int i = 0; i < PTHREAD_NUM; i++) {
//        ret = pthread_create(&pthread[i++], NULL, producer, NULL);
//        ret = pthread_create(&pthread[i], NULL, consumer, NULL);
//    }
//    for (int i = 0; i < PTHREAD_NUM; i++) {
//        pthread_join(pthread[i], &retval[i]);
//    }
//    sem_close(emptySem);
//    sem_close(fullSem);
//    sem_close(buffSem);
//    sem_unlink("yoursemss");
//    sem_unlink("yoursemdd");
//    sem_unlink("buffsemdd");
//    printf("执行结束");
//    exit(0);
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//int A;
//int B = 0;
//int C = 2;
//static int D;
//static int E = 0;
//static int F = 4;
//static int G = 5;
//static int H = 6;
//int main (void) {
//    int a, b = 0, c = 2;
//    static int d, e = 0, f = 4, g = 5;
//    char char1[] = "abcde";
//    char *cptr = "123456";
//    int *heap = (int *)malloc(sizeof(int) * 4);
//    printf("PID is : %d\n\n", getpid());
//
//    printf("int A add = %p\n",&A);
//    printf("int B = 0 add = %p\n", &B);
//    printf("int C = 2 add = %p\n", &C);
//    printf("static int D add = %p\n", &D);
//    printf("static int E = 0 add = %p\n", &E);
//    printf("static int F = 4 add = %p\n", &F);
//    printf("static int G = 5 add = %p\n", &G);
//    printf("static int H = 6 add = %p\n", &H);
//    printf("\n");
//
//    printf("int a add = %p\n",&a);
//    printf("int b = 0 add = %p\n", &b);
//    printf("int c = 2 add = %p\n", &c);
//    printf("static int d add = %p\n", &d);
//    printf("static int e = 0 add = %p\n", &e);
//    printf("static int f = 4 add = %p\n", &f);
//    printf("static int g = 5 add = %p\n", &g);
//    printf("\n");
//
//    printf("char char1[] = 'abcde'\t\t\t addr = %p\n", char1);
//    printf("char char1[] = 'abcde'\t\t\t addr = %p\n", &char1);
//
//    printf("char *cptr = '1'\t\t\t addr = %p", &cptr);
//    printf("value of cptr cptr_value = 0x%p\n", cptr);
//
//    printf("value of %p \t\t\t value_ox%p = %d\n", cptr, cptr, &cptr);
//    printf("int *heap = malloc  head_addr = %p\n", heap);
//    printf("int *heap = malloc head_addr = %p", &heap);
//    pause();
//    free(heap);
//    return 0;
//}


