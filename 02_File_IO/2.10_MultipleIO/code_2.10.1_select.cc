#include<iostream>
#include<sys/time.h>
#include<unistd.h>

#define TIMEOUT 5
#define BUF_LEN 1024

using namespace std;

int main(void)
{
    struct timeval tv;
    fd_set readfds;
        /*
            typedef struct fd_set{ // 0과 1로 저장되는 비트 배열 // fd0 : 0 / fd1 : 1 / fd2 : 0, ...
                u_int fd_count; //설정하는 fd 번호
                SOCKET fd_array[FD_SETSIZE]; // 설정된 fd 배열
            }
        */
    int ret;
    
    /* 표준 입력에서 입력을 기다리기 위한 준비 */
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds); // STDIN_FILENO : 0
    
    
    /* select가 5초 대기, timeval 구조체 설정 */
    
    tv.tv_sec=TIMEOUT;
    tv.tv_usec=0;
    
    /* 입력 기다리기 */
    ret=select(STDIN_FILENO+1, &readfds, NULL, NULL, &tv);
    
    if(ret==-1){
        perror("select");
        return 1;
    }else if(!ret){ // ret=0
        cout<<TIMEOUT<<" seconds elapsed."<<endl;
        return 0;
    }
    
    /* 여기까지 오면 select > 0이므로, fd에서 즉시 읽기가 가능 */
    
    if(FD_ISSET(STDIN_FILENO, &readfds)){
        char buf[BUF_LEN+1];
        int len;
        
        /* read()는 블록되지 않음 */
        len=read(STDIN_FILENO, buf, BUF_LEN);
        if(len==-1){
            perror("read");
            return 1;
        }
        
        if(len){
            buf[len]='\0';
            cout<<"read : "<<buf<<endl;
        }
        return 0;
    }
    
    fprintf(stderr, "This should not happen!\n");
    return 1;
}