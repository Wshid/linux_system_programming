/* 3개의 벡터 세그먼트에 데이터를 쓰기, 각각 다른 크기의 문자열 포함 */

#include<stdio.h>
//#include<sys/types.h>
//#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<sys/uio.h>
#include<error.h>
#include<unistd.h>

int main()
{
    struct iovec iov[3]; // 배열 형태로 사용한다
    ssize_t nr;
    int fd, i;
    
    char* buf[]={
        "The term buccaneer comes from the word boucan.\n",
        "A boucan is a wooden frame used for cooking meat.\n",
        "Buccaneer is the West Indies name for a pirate.\n"};
    
    fd=open("/home/ubuntu/workspace/practice/04_High_level_File_IO/4.1_Vector_IO/out_4.1.1_buccaneer.txt", 
            O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if(fd==-1){
        perror("open");
        return 1;
    }
    
    /* iovec 구조체 값 채우기 */
    for(i=0;i<3;i++){
        iov[i].iov_base=buf[i];
        iov[i].iov_len=strlen(buf[i])+1;
    }
    
    /* 한번의 호출로 iovec 내용을 모두 쓴다 */
    nr=writev(fd, iov, 3);
    if(nr==-1){
        perror("writev");
        return 1;
    }
    printf("wrote %d bytes\n", (int)nr);
    
    if(close(fd)){
        perror("close");
        return 1;
    }
    return 0;
}