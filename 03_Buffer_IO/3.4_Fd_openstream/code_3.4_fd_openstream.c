/*
    이미 열린 fd를 통해 스트림 생성
    모드 호환이 되어야함(전에 열었던 mode가 포함되도록 설정해주어야함)
    
    #include<stdio.h>
    FILE *fdopen(int fd, const char *mode);
        mode는 fopen과 동일
        w와 w+ 지정이 가능하지만 파일을 잘라먹지는 않음
            fd가 가리키는 위치에서 바로 시작
    
    fd가 스트림으로 변환시 fd를 통해 직접 입출력 금지
        => 가능은 함
        => fd가 중복되지 않으며, 새로운 스트림과 연결
        => stream을 닫아버리면 fd도 같이 닫힘
    
    성공시 유효한 fd, 실패시 NULL, errno
    
*/

#include<stdio.h>
#include<stdlib.h> //exit를 사용하기 위함
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char** argv)
{
    FILE* stream;
    int fd;
    
    fd=open("/home/ubuntu/workspace/practice/03_Buffer_IO/3.4_Fd_openstream/in_3.4_fd_openstream.txt", O_RDONLY);
            
    if(fd==-1){
        fputs("error on open RDONLY", stderr);
        exit(1);
    }
    
    stream=fdopen(fd, "r");
    if(!stream){
        fputs("error on fdopen",stderr);
        exit(0);
    }
    printf("success opening the file :)");
    return 0;
}