#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*****************************************************************
//  6-2
//
// date: 26.09.2019
// name: Yahya Guezide
// Reads in a C program and prints out groups of variable names
// that are identical in the first 6 characters
// in alphabetical order
//
*****************************************************************/

#define MAXWORD 100

//**
struct tnode{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};
//**

struct tnode *
addNtree( struct tnode *, char *, int );
void treeprint(struct tnode *);
int mgetword(char *, int);

int main( int argc, char **argv ){
    int n = 6;
    
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    while( mgetword( word, MAXWORD ) != EOF )
        if( isalpha( word[0]) )
            root = addNtree( root, word, n );
    treeprint( root );
    return 0;
}

