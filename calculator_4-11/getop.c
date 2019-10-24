#include <stdio.h>
#include <ctype.h>
#include "calc.h"

#define NUMBER '0'

static int _charBuf = 0;
static _Bool  _Bufrdy = 0; 

static int _getch(){
    if( _Bufrdy ){
        _Bufrdy = 0;
        return _charBuf;
    }
    else
        return getchar();
}

int getop(char s[]){
    int i, c;

    while( (s[0] = c = _getch()) == ' ' || c == '\t' );

    s[1] = '\0';
    if( !isdigit(c) && c != '.' ){ return c; }

    i = 0;
    if( isdigit(c) )
        while( isdigit(s[++i] = c = _getch()) );

    if( c == '.' )
        while( isdigit(s[++i] = c = _getch()) );

    s[i] = '\0';

    if( c != EOF ){
        if( !_Bufrdy ){
            _charBuf = c; _Bufrdy = 1;         
        }else{
            printf( "error: Buffer full\n" );
        }
    }
    
    return NUMBER;
}
