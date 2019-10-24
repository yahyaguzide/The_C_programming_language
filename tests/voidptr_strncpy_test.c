#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*****************************************************************
//  voidptr_strncpy_test.c
//
// date: 28.09.2019
// name: Yahya Guezide

*****************************************************************/

int main( int argc, char **argv ){
    void *p, *p2;
    char *c= "helloWorld";

    p = malloc( strlen(c) );
    p2 = malloc( strlen(c) );
    strncpy( (char*)p, c, sizeof(*c) * strlen(c) );
    strncpy( (char*)p2, c, sizeof(*c) * strlen(c) );
   

    printf( "%d, %s\n", *(int*)p, p );
    printf( "%d, %s", *(int*)p2, p2 );

    return 0;
}

