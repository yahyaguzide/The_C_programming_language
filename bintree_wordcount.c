#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**************************************************
//  bintree_wordcount
//
// date: 26.09.2019
// name: Yahya Guezide
// counting words with the help
// of a binarytree
//
***************************************************/

#define MAXWORD 100

struct tnode{
    char *word;
    int count;
    struct tnode 
        *left, *right;
};

struct tnode *
    addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int mgetword(char *, int);

int main(){
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;

    while( mgetword(word, MAXWORD) != EOF )
        if( isalpha(word[0]) )
            root = addtree(root, word);
    treeprint( root );

    return 0;
}

struct tnode *
    talloc(void);
char *mstrdup(char *);

struct tnode *
addtree( struct tnode *p, char *w ){
    int cond;
    if( p == NULL ){
        p = talloc();
        p->word = mstrdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }else if( (cond = strcmp(w, p->word)) == 0 ){
        p->count++;
    }else if( cond < 0 ){
        p->left = addtree( p->left, w );
    }else{
        p->right = addtree( p->right, w );
    }
    return p;
}

void treeprint( struct tnode *p ){
    if( p != NULL ){
        treeprint(p->left);
        printf( "%4d %s\n", p->count, p->word );
        treeprint(p->right);
    }
}

// get space for a tree node
struct tnode *
talloc(void){
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *mstrdup( char *s ){
    char *p;
    p=(char *)malloc(strlen(s)+1);
    if( p != NULL ){
        strcpy(p,s);
    }
    return p;
}
