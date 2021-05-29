//
//  main.cpp
//  process
//
//  Created by 王天亮 on 2020/9/24.
//

#include <iostream>

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <ctype.h>
#define MAX_CHILD_NUMBER 10
#define SLEEP_INTEReVAL 100
int proc_number = 0; //子进程的编号
void do_someThing() {
    for(; ;) {
        printf("This is process NO.%d and its pid is %d\n", proc_number, getpid());
        sleep(SLEEP_INTEReVAL);
    }
}
int main(int argc, char *argv[]) {
    int child_proc_number = MAX_CHILD_NUMBER;
    int i, ch;
    pid_t child_pid;
    pid_t pid[10] = {0};
    if (argc > 1) {
        child_proc_number = atoi(argv[1]);
        child_proc_number = (child_proc_number > 10) ? 10 : child_proc_number;
    }
    for (int i = 0; i < child_proc_number; i++) {
        //填写代码，建立child_proc_number个子进程要执行
//        proc_number = i;
//        do_someThing();
//        父进程吧子进程id保存到pid[i]
//        child_pid = fork();
        switch (child_pid = fork()) {
            case 0:
                do_someThing();
                break;
            case -1:
                printf("失败");
            default:
                pid[i] = child_pid;
                proc_number++;
                break;
        }
//        if (fork_number == 0) { //创建成功
//            printf("successFork\n");
//            proc_number = i;
//            do_someThing();
//            pid[i] = getpid();
//        }
    }
    while((ch = getchar()) != 'q') {
        if (isdigit(ch)) {
            /*填写代码，向pid[ch - '0']发出信号sigterm*/
//            杀死该子进程
            kill(pid[ch - '0'], SIGTERM);
            pid[ch - '0'] = -1;
            printf("successKill");
        }
    }
    printf("准备杀死所有进程");
    for (int i = 0; i < child_proc_number; i++) {
        kill(pid[i], SIGTERM);
    }
    return 0;

}
//kill（int PID, int IID）
//pid是要杀死的进程号，IID为向将被杀死的进程发送的中断号。

