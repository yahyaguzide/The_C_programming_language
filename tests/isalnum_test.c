#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**************************************************
//  isalnum_test
//
// date: 24.09.2019
// name: Yahya Guezide
// testing alnum
***************************************************/

int main( int argc, char **argv ){
    
    int i= 33;
   
    for(; i <=126; i++ )
        printf("%c : %s\n", i, isalnum(i)? "true": "false");

    return 0;
}

