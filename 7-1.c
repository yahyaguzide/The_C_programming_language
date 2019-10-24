//#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*****************************************************************
//  7-1
//
// date: 04.10.2019
// name: Yahya Guezide
// a program that converts to upper or lower case dependng
// on the name it is invoked with, ->  argv[0]
//
*****************************************************************/

#define LOWERstr "lower"

int (*fpt)(int);

//!! does not work if invoked in linux with ./lower will always do toupper but hey
//  the function pointer is neat
int main( int argc, char **argv ){
    int c;

    if( strncmp( argv[0], LOWERstr, strlen(LOWERstr)+1 ) == 0  )
        fpt= &tolower;
    else
        fpt= &toupper;

    while( (c= getchar()) != EOF )
            putchar((*fpt)(c));

    return 0;
}

