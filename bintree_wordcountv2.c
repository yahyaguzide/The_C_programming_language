#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/*****************************************************************
//  bintree_wordcountv2.c
//
// date: 27.09.2019
// name: Yahya Guezide
// bine tree where parts are modular
// eg. in different c files
//
*****************************************************************/

#define MAXWORD 100

struct tnode *
addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int mgetword(char *, int);

int main( int argc, char **argv ){
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;

    while( mgetword(word, MAXWORD) != EOF )
        if( isalpha(word[0]) )
            root = addtree(root, word);
    treeprint( root );

    return 0;
}

