#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


#include "usefull/bintree.h"

/*****************************************************************
//  6-4
//
// date: 01.10.2019
// name: Yahya Guezide
// Prints out distinct words in its input sorted into
// decreasing order of frequency of ocurrence
//
*****************************************************************/

#define MAXWORD 100

int mgetword(char *, int);

int main( int argc, char **argv ){
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;

    while( mgetword(word, MAXWORD) != EOF )
        if( isalpha(word[0]) )
            root = addtree(root, word);
    treeprint( root );

    freeBintree( root );
    return 0;
}

