#include <stdio.h>
#include <ctype.h>


int _getUnum( unsigned  *num, FILE *stream ){
    *num = 0;
    int i;
    char buffer[100];
    fgets( buffer, 100, stream );
    for( i= 0; i< 100 &&  buffer[i] != '\0' && buffer[i] != EOF; i++ ){
        if( isdigit(buffer[i]) ){
            *num = (*num)*10 + buffer[i] - '0';
        }else{ return -1; }
    }// endFor
    return i;
}

unsigned long _utob( unsigned num ){
    unsigned long i = 1;
    unsigned s = 1, b = 0;
    while( s< num ){ s *= 2; i *= 10; }
    for(; s != 0; s /= 2 ){
        if( s <= num ){
            num -= s;
            b += i;
        }// end if
        i /= 10;
    }// endFor
    return b;
}
