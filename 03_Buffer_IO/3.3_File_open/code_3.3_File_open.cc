/*
#include<stdio>

FILE *fopen(const char *path, const char *mode);
    path는 파일 경로
    mode는
        r : 읽기 모드, 스트림은 파일 시작 지점
        r+ : 읽기/쓰기 모드, 스트림은 파일 시작 지점
        w : 쓰기 모드, 파일 이미 존재시 0으로, 파일 시작지점
        w+ : 읽기/쓰기, 파일 이미 존재시 0으로, 파일 시작지점
        a : 덧붙이기+쓰기모드, 파일 존재 x시 만듦, 파일 끝지점
        a+ : 덧붙이기+읽기/쓰기모드, 파일 존재x시 만듦, 파일 끝지점
    b도 포함할 수 있으나, 리눅스에서는 무시
        => txt나 b나 전부 같이 처리하기 때문

성공시 FILE 포인터, 실패시 NULL, errno

*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
    FILE* stream;
    stream=fopen("/home/ubuntu/workspace/practice/03_Buffer_IO/3.3_File_open/in_3.3_fopen.txt", "r");
    if(!stream){
        fputs("do not read the file", stderr);
        exit(0);
    }
    printf("open this file :)");
    return 0;
}