#include <stdio.h>

/********************************************
*
*  Print's input while exchanging 
*  Tab's with '\t'
*  Backspaces with '\b'
*  Backslashes with '\\'
*  ~extra spaces with '\s'
*
********************************************/

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
        // Backspace ASCII -> 8
        else if( c[0] == 8 ){
            c[0]= 'b';
        }
        // Backslash ASCII -> 92
        else if( c[0] == 92 ){
            c[0] = '\\';
        }
        // Space ASCII -> dunno look it up -_o_-
        else if( c[0] == ' ' ){
            c[0] = 's';
        }
        else{
            // False
            SPECIAL_CHAR = 0;
        }

        for( short i = (int)SPECIAL_CHAR; i >= 0; i-- )
            putchar( c[i] );;

    }

    return 0;
}
