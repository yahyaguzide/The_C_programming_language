#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/*****************************************************************
//  6-3
//
// date: 28.09.2019
// name: Yahya Guezide
// Cross-refrencer that prints out a list
// of words and for each word a list
// of line numbers where it occurs, noise words
// like 'the', 'and' etc are removed
//
*****************************************************************/

#define MAXWORD 100

struct tnode;

struct tnode *
    addtree(struct tnode *, char *, int  *);
void treeprint(struct tnode *);
void freeBintree(struct tnode *);
int mgetword(char *, int);

int main(){
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;

    char c;
    int line= 1;
    while( (c= mgetword(word, MAXWORD)) != EOF ){
        if( c == '\n' )
            line++;
        else if( isalpha(word[0]) )
            root = addtree(root, word, &line);
    }
    treeprint( root );

    freeBintree( root );

    return 0;
}

int mgetword( char *word, int lim ){
 int c, mgetch(void);
    void mungetch(int);
    char *w = word;

    while (isspace(c = mgetch())){
        if( c == '\n' ){
            *w = '\0';
            return c;
        }
    };

    if (c != EOF)
        *w++ = c;
   if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim >0; w++)
        if (!isalnum(*w = mgetch())) {
            mungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
   
}
