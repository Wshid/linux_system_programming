/* 비동기식 입출력 수행시, 커널의 최하위 레벨에서 부터 자원 필요
    POSIX 1003.1-2003에서는 aio 인터페이스 제공 
    aio lib.    비동기식 입출력을 요청하고, 작업 완료시 알림을 받음 */
    
#include <aio.h>

/* 비동기식 입출력 제어 블록 */
struct aiocb{
    int aio_fildes; /* fd */
    int aio_lio_opcode; /* 수행할 작업 */
    int aio_reqprio; /* 요청 우선순위 오프셋 */
    volatile void *aio_buf; /* 버퍼에 대한 포인터 */
    size_t aio_nbytesl /* 연산의 크기 */
    struct sigevent aio_sigevent; /* 시그널 번호와 값 */
    
    /* 내부적으로 사용하는 프라이빗 멤버 */
}

int aio_read(struct aiocb *aiocbp);
int aio_write(struct aiocb *aiocbp);
int aio_error(const struct aiocb *aiocbp);
int aio_return(struct aiocb *aiocbp);
int aio_cancel(int fd, struct aiocb *aiocbp);
int aio_fsync(int op, struct aiocb *aiocbp);
int aio_suspend(const struct aiocb *const cblist[], int n,
                    const struct timespec *timeout);