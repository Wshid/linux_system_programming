/* l,v : 리스트로 제공 | 벡터로 제공
        -> 가변인자로 parameter를 제공할 것인지 (...)
        -> 벡터형(배열)로 제공할 것인지 결정
 * p : file 인자값을 사용자의 실행 경로 변수에서 사용(PATH 참조)
 * e : 환경변수를 넘겨줄때 사용(벡터형으로 제공)
 */

/*
#include<unistd.h>

int execlp(const char *path, const char *arg, ...);
int execle(const char *path, const char *arg, ..., char *const envp[]);
int execv(const char *path, char * const argv[]);
int execvp(const char *file, char *const argv[]);
int execve(const char *filename, char *const argv[], char *const envp[]);
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<errno.h>

void code_execvp();

int main(int argc, char** argv)
{
    code_execvp();
}

void code_execvp()
{
    int ret;
    char *v[]={"vi", "/home/ubuntu/workspace/pratice/05_Process/5.3_New_process/out_5.3_exec.txt", 0};
    ret=execvp("/bin/vi", v);
    if(ret==-1)
        perror("execvp()");
}

/*
 * SGID나 SUID가 설정된 프로그램은 직접 셸을 실행하거나, 실행하는 작업을 하면 안 됨.
    -> 사용자가 환경변수를 변경하여 셸의 동작 조작이 가능해짐
    -> Path injection(경로 가로채기)
    
    공격자는 execlp가 원하는 바이너리를 실행하도록, PATH를 변경 후,
        해당 바이너리의 SGID 또는 SUID권한으로 프로그램 실행히 가능해짐
 
 * exec함수군에서 execve는 sys.call로 구현되어 있음
 */