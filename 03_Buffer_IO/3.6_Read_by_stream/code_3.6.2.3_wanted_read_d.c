#include<stdio.h>
#include<stdlib.h>

#define DELIMETER 'l' //DELIMETER를 기준으로 구분 문자를 정한다.

int main(int argc, char** argv)
{
    int n=20;
    FILE* stream=fopen("/home/ubuntu/workspace/practice/03_Buffer_IO/3.6_Read_by_stream/in_3.6.2_read_line.txt","r");
    char *s;
    char str[n];
    int c=0;
    s=str;
    
    while(--n>0 && (c=fgetc(stream))!=EOF && (*s++=c)!=DELIMETER)
        ;
    
    if(c==DELIMETER)
        *--s='\0';
    else
        *s='\0';
    
    printf("%s\n",str);
    
    return 0;
}

/* 전위 연산은 해당 구문을 만나기 전에 미리 수행되며,
    후위 연산은 해당 구문을 수행한 후 다음 구문 직전에 실행된다.
    
    전위 연산의 경우 연산후 스택에 값을 집어 넣고,
    후위 연산의 경우 스택에 넣고 연산을 진행한다.
*/