/*
    파일 오프셋이 파일 끝을 넘어가게 되면
    마지막 오프셋과 새로운 오프셋 사이에 공간이 만들어지며 0으로 채워진다.
    
    이를 구멍이라고 하며, 물리적인 디스크 공간을 차지하지 않음
    구멍이 생긴 파일을 spare file(성긴 파일)이라고 한다.
    
    구멍에 읽기 요청을 하면 적절한 개수 만큼 0으로 채워진 값을 반환
*/

#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

using namespace std;

int main(int argc, char** argv)
{
    int ret;
    int fd=open("/home/ubuntu/workspace/practice/02_File_IO/2.7_Lseek/in_2.7_lseek.txt",0664);
    
    ret=lseek(fd, (off_t) 1688, SEEK_END);
    if(ret==(off_t)-1){
        perror("lseek error");
        exit(-1);
    }
    else
        cout<<ret<<endl;
        
}