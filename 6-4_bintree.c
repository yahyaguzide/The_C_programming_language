#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "bintree.h"

/**************************************************
//  bintree
//
// date: 26.09.2019
// name: Yahya Guezide
// A Binary Tree concept wich can hold words
// and the number of occurences
//
***************************************************/

void treeprint( struct tnode *p ){
    if( p != NULL ){
        treeprint(p->left);
        printf( "%4d %s\n", p->count, p->word );
        treeprint(p->right);
    }
}

void freeBintree( struct tnode *node ){
    if( node ){
        freeBintree( node->left );
        freeBintree( node->right );
        free( node );
    }
}

struct tnode *
talloc(void);
char *mstrdup(char *);

struct tnode *
addtree( struct tnode *p, char *w ){
    int cond;
    do{


    }while( p != NULL && cond == 0 )
    if( p == NULL ){
        p = talloc();
        p->word = mstrdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }else if( (cond = strcmp(w, p->word)) == 0 ){
        p->count++;
    }
        p->left = addtree( p->left, w );
        p->right = addtree( p->right, w );
    return p;
}

// get space for a tree node
struct tnode *
talloc(void){
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *mstrdup( char *s){
    char *p;
    p=(char *)malloc(strlen(s)+1);
    if( p != NULL ){
        strcpy(p,s);
    }
    return p;
}
