/*
    ssize_t read(int fd, void *buf, size_t len);
    - Read()의 반환값 // 실상 읽은 바이트 수를 반환한다
        ret= len : len바이트 전체를 읽어서 buf에 저장
        0 < ret < len : SIG로 인한 중단, 에러발생시, len읽기전 EOF도달.
                        읽은 데이터는 buf애 저장된다.
        0 : EOF, 더 이상 읽을 데이터가 없음
            * Nonblock 상태일때는 읽을 데이터가 없을때도 파일이 블록되지 않음
        ret=-1, errno=EINTR : 바이트 읽기전 SIG도착, 재호출을 하면 됨
        ret=-1, errno=EAGAIN : 읽을 데이터 x, 나중에 다시 읽기 요청, nonblock일때만 발생
        ret=-1, errno=기타에러 : 치명적 오류 발생
*/

#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

using namespace std;

int main()
{
    ssize_t ret;
    
    while(len!=0 && (ret=(read(fd, buf, len)))!=0){
        if(ret==-1){
            if(errno==EINTR)
                continue;
            perror("read");
            break;
        }
        len-=ret;
        buf+=ret;
        }
    }
}