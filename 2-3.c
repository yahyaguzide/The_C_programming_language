#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/****************************
 *
 *  Converts a string of Hex
 *  into Integer values
 *
 ****************************/

#define FALSE 0
#define TRUE 1
#define LINE 10

int htoi( char *s );

int main(){
    char buffer[LINE];

    fgets( buffer, LINE, stdin );
    printf("~=%d", htoi( buffer ) );

    return 0;
}

int htoi( char *s){
    int c, n = 0;
    _Bool _inHex;

    for( int i= 0; ( c = tolower(s[i]) ) != '\0' && c != '\n'; i++ ){
        _inHex = _inHex || (c!= '0' && c != 'x') ? TRUE : FALSE;
        if( _inHex ){
            n*= 16;
            if( c >= '0' && c <= '9' ){ n+= c - '0'; }
            else if( c >= 'a' && c <= 'f' ){ n+= 10 + c - 'a'; }
            // not a valid Hex, return -1
            else { return -1; }
        }
    }

    return n;
}
