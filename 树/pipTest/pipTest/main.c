//
//  main.c
//  pipTest
//
//  Created by 王天亮 on 2020/12/8.
//

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
//void func(int * b) {
//    int a = 5;
//    *b = a;
//    return ;
//}
//int main(void) {
//    int *c = NULL;
//    int a = 2;
//    c = &a;
//    func(c);
//    printf("%d", *c);
//}
int main()
{
    int fd[2]={0};
    if(pipe(fd)==-1)
    {
        perror("pipe");
        return 1;
    }

    pid_t pid;
    pid=fork();
    if(pid==-1)
    {
        perror("fork");
        return 2;
    }

    if(pid==0)
    {
        //child
        close(fd[0]);
        int a=5;
        char *buf="Hello, I am your child";
        while(a--)
        {
            write(fd[1], buf, strlen(buf));
            sleep(1);
        }
    }
    else
    {
        //Parent
        close(fd[1]);
        while(1)
        {
            char buf[1024]={0};
            ssize_t s = read(fd[0], buf, sizeof(buf)-1);
            buf[s]=0;
            if(s>0)
            {
                printf("Parent: %s\n", buf);
            }
            else if(s==0)
            {
                printf("quit\n");
                break;
            }else
            {
                perror("read");
                return 3;
            }
        }
    }
    return 0;
}
