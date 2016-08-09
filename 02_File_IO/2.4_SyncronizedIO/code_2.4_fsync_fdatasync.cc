/*
    데이터가 디스크에 기록되도록 확인할 수 있는 방법
    fsync와 fdatasync 이용하기
    반드시 fd의 경우 쓰기 모드로 열려야 함
    
    int fsync(int fd);
    int fsyncdata(int fd);
    
    fsync() : inode에 포함된 meta-data를 모두 디스크에 기록
            : 하드디스크에 데이터와 메타가 성공적으로 기록될 때까지 반환 x 기다림.
    fsyncdata() : 데이터만 기록 // 메타데이터 기록하지 않음
                : 기록하는 내용이 적기때문에 상대적으로 빠름
                : 대부분 fsync없이 fsyncdata만 사용해도 충분함
    
    두 함수 모두 변경된 파일이 포함된 디렉터리 엔트리에 대한 디스크 동기화 보장 x
    이 역시 동기화 하려면 디렉터리 자체를 대상으로 연 fd를 fsync에 인자로 넘겨야 함
    
    몇몇 리눅스 배포한에는 fsyncdata는 지원하지만, fsync 지원 안하는 경우가 있음
    특정 어플리케이션에는 fsync가 EINVAL을 반환할 경우 fdatasync를 호출함
    
    POSIX에서 fsync는 필수, fsyncdata는 선택, 일반적인 리눅스에서는 fsync는 구현되어야 함
    
    동기화할 메타데이터가 존재 x, 특별한 file system에서는 fdatasync만 구현하기도 함
                
*/

#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

using namespace std;

int main(int argc, char** argv)
{
    int fd;
    fd=creat("/home/ubuntu/workspace/practice/02_File_IO/2.4_syncronizedIO/out_2.4_fsync_fsyncdata.txt", 0664);
    
    if(fsync(fd)==-1){
        if(errno==EINVAL){
            if(fdatasync(fd)==-1)
                perror("fdatasync");
            else
                perror("fsync");
        }
    }
}