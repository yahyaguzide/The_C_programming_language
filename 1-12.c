#include <stdio.h>

/********************************************
*
*  Print's out every word on a new Line
*  does not print new Lines
*
********************************************/

#define IN 1
#define OUT 0

int main(){
    _Bool STATE = OUT;
    int c;

    while( (c = getchar()) != EOF ){

        if( c == ' ' || c == '\n' || c == '\t' ){
            if( STATE == IN ){
                STATE = OUT;
                c = '\n';
            }else{
                STATE = OUT;
                continue;
            }
                
        }else
            STATE = IN;

        putchar( c );
    }


}
