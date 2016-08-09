/*
    #include<unistd.h>
    ssize_t write(int fd, const void *buf, size_t count);
        // count 바이트 만큼 fd에서 참조하는 현재위치에 buf 내용을 기입한다.
    에러 발생시 ret=-1, errno=에러값
    ret=0일 수 있지만, 이는 단순히 0바이트를 썼다는 의미를 가진다.
    
*/
#include<stdio.h> // 기본적인 C언어 입출력
#include<stdlib.h> // exit함수를 정상적으로 사용하기 위해
#include<fcntl.h> // 이미 열려있는 파일 특성 제어
#include<unistd.h> // 프로세스 조작 관련
#include<string.h> //필요한 헤더파일은 총 5개

int main(int argc, char** argv)
{
    int fd;
   
   /*
   // part 1
    const char *buf="My ship is solid!";
    ssize_t nr;
    
    
    //fd=open("/home/ubuntu/workspace/practice/02_File_IO/2.3_write/2.3_write.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
    fd=creat("/home/ubuntu/workspace/practice/02_File_IO/2.3_write/2.3_write_2.txt", 0664);
    
    if(fd==-1){
        printf("open 에러 발생\n");
        exit(-1);
    }

    nr=write(fd, buf, strlen(buf));
    if(nr==-1)
    {
        printf("write 에러 발생\n");
        return -1;
    }
    */
    
    //part2
    unsigned long word=1720;
    size_t count;
    ssize_t nr;
    
    count=sizeof(word);
    nr=write(fd, &word, count);
    if(nr==-1){
        printf("write 에러 발생");
        exit(-1);
    }else if(nr!=count){
        //에러일 가능성은 있으나, errno는 설정되지 않음
        printf("able to occur part writing");
        exit(-1);
    }
    
    
}