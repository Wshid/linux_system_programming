#include<iostream>
#include<sys/time.h>
#include<unistd.h>

using namespace std;

struct timeval tv;

int main(){
    tv.tv_sec=5;
    tv.tv_usec=0;
    
    select(0,NULL,NULL,NULL,&tv); // 5초 대기
}