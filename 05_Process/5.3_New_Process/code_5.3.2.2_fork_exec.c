#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    pid_t pid;
    pid=fork();
    if(pid==-1)
        perror("fork");
    
    if(!pid){
        char *const args[]={"ls", "/home/ubuntu/workspace","-a", NULL};
        int ret;
        
        ret=execv("/bin/ls", args);
        if(ret==-1){
            perror("execv");
            exit(EXIT_FAILURE);
        }
    }
}