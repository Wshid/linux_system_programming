/*
    #include<unistd.h>
    #include<sys/types.h>
    
    int ftruncate(int fd, off_t len);
        - 쓰기모드로 열린 fd에 대해 동작한다.
    int truncate(const char* path, off_t len);
        - 쓰기권한이 있는 파일 경로에 대하여 동작한다.
        
    성공하면 0
    실패하면 -1, errno
    
    만약 파일이 확장된다면, 확장된 바이트는 으로 채워진다.
    파일 오프셋은 갱신하지 않는다.
    
    파일을 len 크기만큼 잘라낸다

*/

#include<iostream>
#include<unistd.h>

using namespace std;

int main(int argc, char** argv)
{
    int ret;
    ret=truncate("/home/ubuntu/workspace/practice/02_File_IO/2.9_file_truncation/in_2.9.txt",45);
        //해당 파일이 45바이트의 내용으로 잘려서 재저장된다.
    if(ret==-1)
    {
        perror("truncate");
        return -1;
    }
    cout<<ret<<endl;
    return 0;
}