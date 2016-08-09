/* 
논블록 입출력
    읽을 데이터가 없을때 read()호출이 블록되지 않게 하려면,
    블록되는 대신 읽을 데이터가 없다는 사실을 알려주기 위해 호출이 즉시 반환되도록 함
    애플리케이션이 잠재적으로 다중 파일 입출력을 수행하도록 함
        -> 특정 파일에서 블록되는 바람에 다른 파일에서 사용 가능한 데이털르 놓치는 일이 X
    errno=EAGAIN을 점검해야 함(open()플래그에서 O_NONBLOCK이용)
        논블록 상태에서 파일을 열었지만 데이터가 없을때 ret=-1, errno=EAGAIN반환
    
    실상 예제는 사용하기보다 보여주기 위한 식. 사용하지 않는편이 좋음(필요없는 부하 발생)
*/

#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

using namespace std;

#define BUFSIZ 15



int main()
{
    char buf[BUFSIZ];
    ssize_t nr;
    
    start:
    nr=read(fd, buf, BUFSIZ);
    if(nr==-1){
        if(errno==EINTR)
            goto start;
        if(errno=EAGAIN)
            /* 나중에 다시 시도 */
        else
            /* 에러 발생 */
    }
}
