#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>

int main(int argc, char** argv)
{
    struct stat sb;
    off_t len;
    char *p;
    int fd;
    
    if(argc<2){
        fprintf(stderr, "usage : %s <file>\n", argv[0]);
        return 1;
    }
    
    fd=open(argv[1], O_RDONLY);
    if(fd==-1){
        perror("oepn");
        return 1;
    }
    
    if(fstat(fd, &sb)==-1){ //파일에 대한 정보를 반환하는 함수
        perror("fstat");
        return 1;
    }
    
    if(!S_ISREG(sb.st_mode)){ // 파일 맵핑 전에 일반 파일인지 점검(디렉터리, 디바이스파일이 아닌)
        fprintf(stderr, "%s is not a file\n", argv[1]);
        return 1;
    }
    
    p=mmap(0, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
    
    if(p==MAP_FAILED){
        perror("mmap");
        return 1;
    }
    
    if(close(fd)==-1){
        perror("close");
        return 1;
    }
    
    for(len=0 ;len<sb.st_size;len++)
        putchar(p[len]);
    
    
    if(munmap(p, sb.st_size)==-1){
        perror("munmap");
        return 1;
    }
    return 0;
}