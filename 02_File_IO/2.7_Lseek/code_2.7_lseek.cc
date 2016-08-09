#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

using namespace std;

int main(int argc, char ** argv)
{
    int fd=open("/home/ubuntu/workspace/practice/02_File_IO/2.7_Lseek/in_2.7_lseek.txt",O_RDONLY);
    off_t ret;
    
    /*
    ret=lseek(fd, (off_t)1825, SEEK_SET); // 파일의 실제 크기가 얼마든 간에 정상적으로 열리기만 하면 리턴
    if(ret==(off_t) -1)
    {
        //에러 발생
        perror("rea");
        exit(-1);
    }
    cout<<"===\t"<<ret<<"\t==="<<endl;*/
    
    ret=lseek(fd,0,SEEK_END); // 파일 크기 확인 가능
    if(ret==(off_t)-1){
        perror("lseek error");
        exit(-1);
    }else{
        cout<<"position : "<<ret<<endl;
    }
}