/*
개행문자가 아닌 원하는 길이만큼, 원하는 구분자로 구분하려면?
    -> fgetc를 이용하여 fgets() 대체하기
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
    int c, n=10;
    char *s;
    char str[n];
    
    s=str;
    
    FILE* stream=fopen("/home/ubuntu/workspace/practice/03_Buffer_IO/3.6_Read_by_stream/in_3.6.2_read_line.txt","r");
    
    while(--n>0 && (c=fgetc(stream))!=EOF)
        *s++=c;
    *s='\0';
    
    printf("%s\n",str); //s로 하면 왜 아무것도 안뜨지
    //printf("%p\n", s);
    //printf("%p", &str);
}