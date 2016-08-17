/*
#include<stdio.h>

char* fgets(char *str, int size, FILE *stream);

stream에서 size-1만큼을 str에 저장
    마지막 바이트를 읽고 난후 NULL(\0) 저장
    EOF나 개행문자일 시 읽기 중단
    개행문자를 읽으면 str에 \n 저장
    
성공하면 str, 실패하면 NULL

*/

#include<stdio.h>
#include<stdlib.h>
//#include<limits.h> // LINE_MAX 정의, POSIX 행처리 인터페이스가 다룰 수 있는 입력행의 최대 길이
    //-> 실제로는 에러밖에 안나네..
#define LINE_MAX 30
    /*
        linux의 c lib.에서는 행길이 제한이 없지만,
            안전성, 이식성을 높이기 위해 상대적으로 높은 값인 LINE_MAX이용
        linux에서만 사용한다면 행 길이따위 신경 안써도 됨.
    */

int main(int argc, char** argv)
{
    FILE* stream;
    
    stream=fopen("/home/ubuntu/workspace/practice/03_Buffer_IO/3.6_Read_by_stream/in_3.6.2_read_line.txt","r");
    
    char buf[LINE_MAX];
    if(!fgets(buf, LINE_MAX, stream)){
        fputs("ERROR!",stderr);
        exit(-1);
    }else
        printf("%s",buf);
}