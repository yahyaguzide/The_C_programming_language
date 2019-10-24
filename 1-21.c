#include <stdio.h>

/*********************************
*   
*   replace strings of
*   blanks with tabs
*
**********************************/

#define MAXLENGTH 20
#define TAB_SPACE 8

int main(){
    char buffer[MAXLENGTH];
    int c, t = 0, n = 0;

    for( ; (c = getchar()) != EOF; ){
        if( c == ' ' ){
            if( (n - t) >= (TAB_SPACE - 1) ){
                buffer[t] = '\t';
                n = t+= 1;
            }else{
                buffer[n] = c;
                n+= 1;
            }// endIf
        }else{
            buffer[n] = '\0';
            printf( "%s%c", buffer, c );
            t = n = 0;
        }// endIf
    }// endFor

    return 0;
}
