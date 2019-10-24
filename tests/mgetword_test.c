//#include <stdlib.h>
#include <stdio.h>

/*****************************************************************
//  mgetword_test
//
// date: 30.09.2019
// name: Yahya Guezide
//
*****************************************************************/

#define MAXWORD 100

int main( int argc, char **argv ){

    char word[MAXWORD], c;
    while( (c= mgetword( word, MAXWORD)) != EOF ){
        printf( "\t%s\t%d\n ", word, (c=='\n')? 1:0 );
    }

    return 0;
}

