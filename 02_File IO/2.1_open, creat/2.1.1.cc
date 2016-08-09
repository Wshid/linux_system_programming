#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

using namespace std;

int main()
{
    int fd;
    unsigned long word;
    ssize_t nr;
    
    fd=open("/home/ubuntu/workspace/test/1",O_RDONLY); //숫자 0이아니라 대문자 O
    //fd=open("/home/ubuntu/workspace/test/1",O_TRUNC, O_WRONLY);
    if(fd==-1)
        cout<<("aa")<<endl;
    
    nr=read(fd, &word, sizeof(unsigned long));
    cout<<nr<<endl;
    if(nr==-1)
        cout<<"error"<<endl;
    return 0;
}