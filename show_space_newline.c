#include <stdio.h>

int main(){
    int c[2];
    _Bool SPECIAL_CHAR;

    // Set backlash for later usage, if Spezial Character occurs
    c[1] = '\\';

    for( ; (c[0] = getchar()) != EOF;  ){
        // True
        SPECIAL_CHAR = 1;

        // Tab ASCII -> 9
        if( c[0] == 9 ){
            c[0] = 't';
        }
        // Space 
        else if( c[0] == ' ' ){
            c[0]= 's';
        }
        // NewLine
        else if( c[0] == '\n' ){
            c[0] = 'n';
        }else{
            // False
            SPECIAL_CHAR = 0;
        }

        for( short i = (int)SPECIAL_CHAR; i >= 0; i-- )
            putchar( c[i] );

    }

    return 0;
}
