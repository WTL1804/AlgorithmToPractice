//
//  main.cpp
//  ThreadTest
//
//  Created by 王天亮 on 2020/10/15.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
/*开启16个线程*/
#define PTHREAD_NUM 16
unsigned long sum = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void * thread(void *arg) {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < 100000; i++) {
        sum += 1;
    }
    pthread_mutex_unlock(&mutex);
    
    return 0;
}
int main(int argc, const char * argv[]) {
    printf("before .... sum = %lu\n", sum);
    pthread_t pthread[PTHREAD_NUM];
    int ret;
    void *retval[PTHREAD_NUM];
    for (int i = 0; i < PTHREAD_NUM; i++) {
        ret = pthread_create(&pthread[i], NULL, thread, NULL);
        if (ret != 0) {
            perror("cause:");
            printf("creat pthread %d faild. \n",i + 1);
        }
    }
    for (int i = 0; i < PTHREAD_NUM; i++) {
        pthread_join(pthread[i], &retval[i]);
    }
    printf("after.....sum = %lu\n", sum);
    return 0;
}
