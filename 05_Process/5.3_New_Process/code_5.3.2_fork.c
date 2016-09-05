#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char** argv)
{
    pid_t pid;
    if(pid>0)
        fprintf(stdout, "I am the parent of pid = %d\n",pid);
    else if(!pid)
        fprintf(stdout, "pid : %d \n I am the child\n",pid);
    else if(pid==-1)
        perror("fork");
    return 0;
}