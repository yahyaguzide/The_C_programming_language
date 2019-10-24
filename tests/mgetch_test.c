//#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/*****************************************************************
//  mgetch_test
//
// date: 30.09.2019
// name: Yahya Guezide
//
*****************************************************************/

int mgetch();
//void ungetch(int);

int main( int argc, char **argv ){
        
    int c;
    while( (c = mgetch()) != EOF ){
        printf( "%c:%d ", (c=='\n')? '\"':c, isalpha(c) );
        if( c=='\n' ){ printf( "\n" ); }

    }

    return 0;
}

