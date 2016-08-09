/*
    read에 비해 부분쓰기를 일으킬 확률은 매우 적음
    EOR조건도 없음
    에러가 발생하지 않을경우 전체스기 작업수행을 보장
    일반 파일을 쓸대는 루프 내에서 돌릴 필요가 없으나, 정말로 썼는지 확인하기 위해 ㅅ용
    또한 두번째 write()호출이 숨어있던 에러코드 반환 가능성 여부 판단이 가능
        -> 첫번째 write()호출 결과로 부분쓰기를 일으킨 원인을 밝힐 수도 있음
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<errno.h> // errno를 사용하기 위해 추가

int main(int argc, char** argv)
{
    ssize_t ret, nr;
    int len=20;
    int fd;
    const char *buf="Is it occured part writing?";
    fd=creat("/home/ubuntu/workspace/practice/02_File_IO/2.3_write/2.3.1.txt", 0664);
    
    while(len!=0 && (ret=write(fd,buf,len))!=0){
        if(ret!=-1){
            if(errno==EINTR)
                continue;
            perror("write"); // 문자열을 기준으로 stderr형태로 변환하여 보여줌
                //void perror(const char *str);
            break;
        }
        len-=ret;
        buf+=ret;
        
    }
}

/*
    O_APPEND로 덧붙여서 열면 여러 프로세스가 동시 충돌하는 Race Condition상태에도 항상
    파일의 마지막을 가리켜 작업을 시도하게 된다.
    write 호출시 문제가 없으나, read로 호출할때는 문제 발생할 가능성이 존재
    APPEND는 로그파일갱신 및 특정 작업에서만 효과를 발휘
*/