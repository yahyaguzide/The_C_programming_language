#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*****************************************************************
//  6-6
//
// date: 03.10.2019
// name: Yahya Guezide
// simple version of the #define processor
// suitable for use with c programs
//
*****************************************************************/

struct nlist{
    struct nlist *next;
    char *name;
    char *defn;
};

#define WORDSIZE 100
#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];

int getPragma(char *, char *);
void printTable(void);
struct nlist *install(char *, char *);
int main( int argc, char **argv ){
    char name[WORDSIZE], defn[WORDSIZE];

    while( getPragma(name, defn) < 1 ){
        if( install(name, defn) == NULL)
            return 1;
    }

    printTable();
    return 0;
}

void printTable(){
    struct nlist *np;
    for( int i= 0; i < HASHSIZE; i++ ){
        for( np= hashtab[i]; np != NULL; np= np->next ){
            printf( "\t%s : %s\n", np->name, np->defn );
        }
        printf( "_*_*_*_*_*_*_*_*_*_*_*_*_*" );
    }
}

int getPragma( char *name, char *defn ){
    int c;
    char *p;

    while( (c= getch()) != '#' ){ if( c == EOF ){ return -1; } };
    p = name;
    while( !isspace(c= getch()) && c != EOF ){
        if( isdigit(c) )
            return 0;
        *p++ = c;
    }
    *p = '\0';
    ungetch(c);

    while( isspace(c= getch()) );
    ungetch(c);
    p = defn;
    while( !isspace(c= getch()) && c != EOF ){
        *p++ = c;
    }
    *p = '\0';
    ungetch(c);

    if( !*name || !*defn )
        return 0;
    return name[0];
}


//** Hash form hash value for string
unsigned hash( char *s ){
    unsigned hashval;
    for( hashval = 0; *s != '\0'; s++ )
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup( char *s ){
    struct nlist *np;
    for( np = hashtab[hash(s)]; np != NULL; np = np->next )
        if( strcmp(s, np->name) == 0 )
            return np; // found
    return NULL; // nnot found
}

char *mstrdup(char *);
struct nlist *install( char *name, char *defn ){
    struct nlist *np;
    unsigned hashval;
    if( (np = lookup(name)) == NULL ){ // not found
        np = (struct nlist *)malloc(sizeof(*np));
        if( np == NULL || (np->name = mstrdup(name)) == NULL )
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }else // already in there
        free( (void*) np->defn); // free previus defn
    if( (np->defn = mstrdup(defn)) == NULL )
        return NULL;
    return np;
}

char *mstrdup( char *s ){
    if( s )
        return (char*)malloc(sizeof(*s));
    return NULL;
}
