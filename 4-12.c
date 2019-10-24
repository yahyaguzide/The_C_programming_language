#include <stdio.h>
#include <stdlib.h>

/*************************************
 *  Recursiv 
 *  
 *  itoa
 *  converts int to ascii  and
 *  saves them in an given char array
 * **********************************/

#define MAXSIZE 5

_Bool itoa( char[], int, int );

int main(){
    
    char s[MAXSIZE], input[10];

    gets( input, 10 );
    
    itoa( s, MAXSIZE, atoi( input ) );
    printf( "%s", s );

    return 0;
}

_Bool  itoa( char s[],int length, int n ){
    static int i = 0;
    
    if( n / 10  && !itoa( s, length, n / 10 ) ){ return 0; }

    if( i >= length - 1 ){ 
        printf( "error: not enough space\n");
        return 0;
    }

    s[i] = n % 10 + '0';
    s[++i] = '\0';
    return 1;
}
