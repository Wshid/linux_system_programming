#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<inttypes.h> //intmax_t를 typedef로 지정한 헤더 파일

/*
#include<sys/types.h>
#include<unistd.h>

pid_t getpid(void); // 호출한 ps의 pid를 반환
pid_t getppid(void); // 호출한 ps의 ppid를 반환

//두 함수 모두 에러를 반환하지 않음

printf("My pid=%jd\n", (intmax_t) getpid());
printf("Parent's pid=%jd\n", (intmax_t) getppid());
    //intmax_t : 시스템에서 지원하는 singed 정수라도 저장할 수 있도록 함
    // 시스템의 모든 signed형 정수형보다 크거나 같은 정수형 타입
    // %j : typedef로 표현되는 정수를 문제없이 출력하도록 함

*/
int main(int argc, char** argv)
{
    printf("My pid=%jd\n", (intmax_t) getpid());
    printf("Parent's pid=%jd\n", (intmax_t) getppid());
}