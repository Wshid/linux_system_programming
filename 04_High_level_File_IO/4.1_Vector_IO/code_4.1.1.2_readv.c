#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/uio.h>

int main()
{
    char foo[48], bar[51], baz[49];
    struct iovec iov[3];
    ssize_t nr;
    int fd, i;
    
    fd=open("/home/ubuntu/workspace/practice/04_High_level_File_IO/4.1_Vector_IO/out_in_4.1.1_buccaneer.txt",
                O_RDONLY);
    
    if(fd==-1){
        perror("open");
        return 1;
    }
    
    /* iov 구조체 초기화 */
    iov[0].iov_base=foo;
    iov[0].iov_len=sizeof(foo);
    iov[1].iov_base=bar;
    iov[1].iov_len=sizeof(bar);
    iov[2].iov_base=baz;
    //iov[2].iov_len=strlen(baz); // sizeo가 아닌 strlen해도 될까? -> 에러남
    iov[2].iov_len=sizeof(baz);
    
    nr=readv(fd, iov, 3);
    if(nr==-1){
        perror("readv");
        return 1;
    }
    
    for(i=0;i<3;i++)
        printf("%d : %s", i, (char*) iov[i].iov_base); // (void*)형이므로 캐스팅 해주어야 함
    
    if(close(fd)){
        perror("close");
        return 1;
    }
    return 0;
}