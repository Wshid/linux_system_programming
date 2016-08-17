/*
    fgetc()함수로 구현
    
    #include<stdio.h>
    
    int fgetc(FILE *stream);
    
    stream -> unsigned char -> int
    
    stream에서 다음 문자를 읽고 unsigned char -> int로 변환
        => 파일 끝이나 에러를 알려줄 수 있도록 하기 위함
        => 에러일때 EOF 반환
    
    반드시 반환값을 int type으로 지정해야함
    
        *** char타입으로 설정시 에러값을 볼 수 없음
        
    === 3.6.1.2 return a character already read
    
    스트림을 확인했을때 원하는 문자인지 확인후, 원하는 문자 아닐 시 그 문자 되돌림 
    
    int ungetc(int c, FILE* stream);
    
    호출때마다 c를 unsigned char로 변환 후, stream으로 되돌림
    성공하면 c, 실패하면 EOF
    
    여러문자 되돌렸을때, 역순으로 반환(LIFO)
    
    몇몇은 되돌리기를 한번만 구현하나,
        리눅스는 메모리가 허용하는 범위 내에서 무제한 되돌리기 허용
    
    ungetc()호출 후 중간탐색함수(p130) 호출 후
        읽기 요청 안했을 경우 되돌린 모든 문자 drop
    
    thread는 버퍼를 공유하므로 단일 ps에서 여러 thread 사용시에도 동일한 현상 발생
    

*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
    FILE* stream;
    int c;
    stream=fopen("/home/ubuntu/workspace/practice/03_Buffer_IO/3.6_Read_by_stream/in_3.6.1_one_character.txt","r");
    c=fgetc(stream);
    if(c==EOF){
        printf("The File is EOF\n");
        exit(-1);
    }
    else{
        printf("c = %c\n", (char) c);
    }
    
    c=ungetc((int)'e', stream);
    c=ungetc((int)'=', stream);
    //일치하지 않을경우 일치하지 않는 문자 반환, 아예 에러가 나야 EOF
    if(c==EOF){
        printf("ungetc error\n");
        exit(-2);
    }else{
        printf("ungetc = %c\n", (char) c);
    }
    return 0;
}