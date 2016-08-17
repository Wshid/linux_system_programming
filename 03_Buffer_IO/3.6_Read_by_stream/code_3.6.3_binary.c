/*
주어진 stream에서 일련의 바이트를 담고 있는 단일 엘리먼트 읽기
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
    FILE* stream=fopen("/home/ubuntu/workspace/practice/03_Buffer_IO/3.6_Read_by_stream/in_3.6.3_binary","r");
    char buf[10];
    size_t nr;
    nr=fread(buf,sizeof(buf),2,stream); // stream에서 buf크기만큼 buf에 읽어들임. 2번
    if(nr==0){
        fputs("ERROR!",stderr);
        exit(-1);
    }
    printf("%s\n",buf);
    printf("success reading binary file :)");
}