#include <stdio.h>

#define BUFFERSIZE 5

static int Buf[BUFFERSIZE];
static int bufp= 0;

int mgetch(){
        return  bufp > 0? Buf[--bufp]: getchar();
}

void mungetch( int c ){
    if( bufp < BUFFERSIZE ){
        Buf[bufp++] = c;
    }
}

