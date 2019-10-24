#include <stdio.h>

/********************************************
*
*  Only print's on NewLine if more than 
*  2 Newlines got read
*
 ********************************************/

int main(){
    int c, NLc = 0;

    for( ; (c = getchar()) != EOF;  ){
        if( c == '\n' ){
            NLc+= 1;
        }else{
            NLc= 0;
        }

        if( NLc < 3 )
           putchar( c );

    }

    return 0;
}
