#include <stdio.h>

/********************************
 *
 *  Replace Tabstops with
 *  the right amount of spaces
 *
 *******************************/

#define MAXLENGTH 1000


int  main(){
    int c, n = 8;
    char buffer[MAXLENGTH];
    
    for( int i = 0; (c = getchar()) != EOF; i++ ){
        if( c == '\t' ){
            for( ;i % 8 > 0; i++ ){
                putchar( ' ' );
            }
        }else
            putchar( c );

        if( c == '\n' ){
            i = 0;
        }
    }

    return 0;
}


