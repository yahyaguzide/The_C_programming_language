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

//**
struct tnode{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};
//**

void treeprint( struct tnode *p ){
    if( p != NULL ){
        treeprint(p->left);
        printf( "%4d %s\n", p->count, p->word );
        treeprint(p->right);
    }
}

static struct tnode *
    talloc(void);
static char *mstrdup(const char *, int);

struct tnode *
addNtree( struct tnode *p, char *w, int n ){
    int cond;
    if( p == NULL ){
        p = talloc();
        p->word = mstrdup(w, n);
        p->count = 1;
        p->left = p->right = NULL;
    }else if( (cond = strncmp(w, p->word, n)) == 0 ){
        p->count++;
    }else if( cond < 0 ){
        p->left = addNtree( p->left, w, n );
    }else{
        p->right = addNtree( p->right, w, n );
    }
    return p;
}

// get space for a tree node
static struct tnode *
talloc(void){
    return (struct tnode *)malloc(sizeof(struct tnode));
}

static char *mstrdup( const char *s, int n ){
    char *p;
    int m = strlen(s)<n? strlen(s): n;
    // only n characters are to be copied, or less!!
    p=(char *)malloc( m+1 );    
    if( p != NULL ){
        strncpy(p,s,sizeof(*p)*(m+1)); // weee overflow safe, here a Bird-> _(;>
        p[m] = '\0';
    }
    return p;
}

