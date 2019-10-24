#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "usefull/mlinkedlist_int.h"

/**************************************************
//  bintree
//
// date: 26.09.2019
// name: Yahya Guezide
// A Binary Tree concept wich can hold words
// and the number of occurences
//
***************************************************/

//** changed version, added a linked list
struct tnode{
    char *word;
    int count;
    struct _List list;

    struct tnode 
        *left, *right;
};
//**

void freeBintree( struct tnode *node ){
    if( node ){
        freeBintree( node->left );
        freeBintree( node->right );
        freeList( &node->list );
        free(node);
        node = NULL;
    }
}

//** changed version, prints out list of lines
void treeprint( struct tnode *p ){
    if( p != NULL ){
        treeprint(p->left);
        printf( "\n%4d %s:\n\t", p->count, p->word );
        for( int i= 0; i < p->list.length; i++ ){
            printf( "%d ", getNum( &p->list, i) );
            if( (i+1)%5 == 0 )
                printf( "\n\t" );
        }

        treeprint(p->right);
    }
}
//**

struct tnode *
    talloc(void);
char *mstrdup(char *);

//** changed version, add's line to list
struct tnode *
addtree( struct tnode *p, char *w, int *line ){
    int cond;
    if( p == NULL ){
        p = talloc();
        p->word = mstrdup(w);
        p->count = 1;
        p->left = p->right = NULL;

        initList( &p->list );
        addElem( &p->list, *line );
    }else if( (cond = strcmp(w, p->word)) == 0 ){
        p->count++;
        addElem( &p->list, *line );
    }else if( cond < 0 ){
        p->left = addtree( p->left, w, line );
    }else{
        p->right = addtree( p->right, w, line );
    }
    return p;
}
//**

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
