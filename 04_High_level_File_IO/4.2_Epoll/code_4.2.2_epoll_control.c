#include<sys/epoll.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    struct epoll_event event;
    int ret;
    
    int epfd;
    epfd=epoll_create1(0);
    if(epfd<0) perror("epoll create");
    
    /* epoll을 epfd에 추가하는 예제코드 */
    
    event.data.fd=fd; // 나중에 epoll_wait에서 반환됨
    event.events=EPOLLIN | EPOLLOUT;
    
    ret=epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &event);
    if(ret) perror("epoll_ctl");
    
    /* epfd에 연관된 fd의 구독 이벤트 변경시 */
    
    event.events=EPOLLIN;
    
    ret=epoll_ctl(epfd, EPOLL_CTL_MOD, fd, &event);
    if(ret) perror("epoll_ctl");
    
    /* epfd에 등록된 fd에 연관된 이벤트 삭제시 */
    
    ret=epoll_ctl(epfd, EPOLL_CTL_DEL, fd, &event);
    if(ret) perror("epoll_ctl")
        // 이경우에 event mask가 없기때문에 event=NULL이 될 수 있음
        // :v2.6.9에서는 그래도 설정을 해주어 하는 버그 존재
    
}