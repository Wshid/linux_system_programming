/* 사용자 영역에서 readv와 writev 구현하기 */

#include<unistd.h>
#include<sys/uio.h>

ssize_t naive_writev(int fd, const struct iovec *iov, int count)
{
    ssize_t ret=0;
    int i;
    
    for(int i=0;i<count;i++){
        ssize_t nr;
        
        errno=0;
        nr=write(fd, iov[i].iov_base, iov[i].iov_len);
        if(nr==-1){
            if(errno=EINTR) continue;
            ret=-1;
            break;
        }
        ret+=nr;
    }
    return ret;
}

/* 실장 readv와 wirtev의 리눅스 구현은 내부적으로 벡터 입출력 수행하도록 구현되어 있음
    리눅스 커널 내부의 모든 입출력은 벡터 입출력
    read()와 write()구현 역시, 하나의 세그먼트를 가지는 벡터 입출력으로 이루어짐 */