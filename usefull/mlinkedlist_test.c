#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**************************************************
//  bintree
//
// date: 26.09.2019
// name: Yahya Guezide
// A Binary Tree concept wich can hold words
// and the number of occurences
//
***************************************************/

//** cahnged version, holds a integer list
struct tnode{
    char *word;
    int count;
    struct  _List list;

    struct tnode 
        *left, *right;
};
//**

void treeprint( struct tnode *p ){
    if( p != NULL ){
        treeprint(p->left);
        printf( "%s %4d\n", p->word, p->count );

        struct _Elem elem;
        for( int i = 0; elem = getElem( &p->list, i ) != NULL; i++ ){
            printf( "   %s", elem->num );
            if( i % 5 == 0 )
                printf( "\n" );
        }
        treeprint(p->right);
    }
}

struct tnode *
    talloc(void);
char *mstrdup(char *);

// changed version, add's line number to list
struct tnode *
addtree( struct tnode *p, char *w, int line ){
    int cond;
    if( p == NULL ){
        p = talloc();
        p->word = mstrdup(w);
        p->count = 1;
        p->left = p->right = NULL;
        addElem( &p->list, line );
    }else if( (cond = strcmp(w, p->word)) == 0 ){
        p->count++;
        addElem( &p->list, line );
    }else if( cond < 0 ){
        p->left = addtree( p->left, w );
    }else{
        p->right = addtree( p->right, w );
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
