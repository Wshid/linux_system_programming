/*
#include<unistd.h>
int execl(const char *path, const char *arg, ...);
    //현재 ps를 path가 가리키는 프로그램으로 대체
    //arg : path에 명시된 프로그램 인자
    //가변 인자 목록은 반드시 NULL로 끝나야함
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void edit_txt();
void edit_txt_parameter();

int main(int argc, char** argv)
{
    edit_txt();
    edit_txt_parameter();
    return 0;
}

void edit_txt()
{
    int ret;
    ret=execl("/bin/vi", "vi", NULL);
    if(ret==-1)
        perror("execl");
}

/* 실행파일의 경로인 path의 마지막 요소인 vi를 첫번째 인자로 두기
    fork/exec에서 argv[0]를 검사하여 바이너리 이미지를 찾을 수 있도록 함
        sys유틸중 몇개는 같은 프로그램 이지만
            하드 링크를 통해 다른이름으로 사용자에게 제공
*/

void edit_txt_parameter() // 파라미터를 넘길 수 있음, 특정 인자 주기
{
    int ret;
    ret=execl("/bin/vi", "vi", "/home/ubuntu/workspace/practice/05_Process/5.3_New_Process/out_5.3.1.2_execl.txt",NULL);
    if(ret!=-1)
        perror("execl");
}

/*
 * 반환값이 없음
    이전 실행했던 코드는 ps의 주소공간에 존재하지 않음
    에러 발생시, -1, errno 값조정됨
 
 * 대기중인 시그널 사라짐
 * ps가 받은 시그널은 디폴트로 처리됨
 * 메모리 락 해제
 * 스레드의 속성은 모두 기본값
 * ps통계 대부분 재설정
 * 메모리 주소공간과 관련된 모든 내용 사라짐
 * 사용자 영역에만 존재하는 모든 내용 사라짐
 
 변경되지 않는 속성 : pid, ppid, 우선순위, 소유자와 그룹
 
 
 일반적으로는 exec호출 과정에서 그대로 상속
    -> 보통은 exec 호출 전에 close()하는 방식 사용
 fcntl 활용해서 커널이 이과정으로 자동적으로 수행하도록 지시
 */