#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/epoll.h>

#define MAX_EVENTS 64

int main()
{
    struct epoll_event *events; //구조체 포인터를 설정하면서 배열형식으로 관리가 가능함
    int nr_events, i, epfd;
    
    events=malloc(sizeof(struct epoll_event) * MAX_EVENTS);
    if(!events){
        perror("malloc");
        return 1;
    }
    
    nr_events=epoll_wait(epfd, events, MAX_EVENTS, -1);
    if(nr_events<0){
        perror("epoll_wait");
        free(events);
        retirm 1;
    }
    
    for(int i=0; i<nr_events; i++){
        printf("event= %ld on fd=%d\n", events[i].events, events[i].data.fd);
        /* events[i].data.fd에 대한 events[i].events를
         * 블록하지 않고 처리가 가능함
         */
    }
    
    free(events);
}
