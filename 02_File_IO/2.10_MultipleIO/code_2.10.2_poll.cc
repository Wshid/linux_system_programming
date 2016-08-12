#include<iostream>
#include<unistd.h>
#include<poll.h>
#define TIMEOUT 5

using namespace std;

int main(void)
{
    struct pollfd fds[2];
    int ret;
    
    /*STDIN에 대한 이벤트 감시 준비 */
    fds[0].fd=STDIN_FILENO;
    fds[0].events=POLLIN;
    
    /*STDOUT에 대한 쓰기가 가능한지 준비 (거의 항상 참) */
    fds[1].fd=STDOUT_FILENO;
    fds[1].events=POLLOUT;
    
    /* 블록 시키기 */
    ret=poll(fds, 2, TIMEOUT*1000);
    if(ret==-1){
        perror("poll");
        return 1;
    }
    
    if(!ret){
        cout<<TIMEOUT<<" seconds elapsed.\n"<<endl;
        return 0;
    }
    
    if(fds[0].revents & POLLIN)
        cout<<"stdin is readable"<<endl;
    
    if(fds[1].revents & POLLOUT)
        cout<<"stdout is writable"<<endl;
        
    return 0;
}