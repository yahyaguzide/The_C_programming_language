//#include <stdlib.h>
#include <stdio.h>

/*****************************************************************
//  tableLookup
//
// date: 01.10.2019
// name: Yahya Guezide
// A algorithm that connects a name and a definition
// in a table where strings are saved as hashes, look searches for the right hash
//
*****************************************************************/

struct nlist{
    struct nlist *next;
    char *name;
    char *defn;
}

#define HASHSIZE  101;
static struct nlist *hashtab[HASHSIZE];


int main( int argc, char **argv ){

    return 0;
}

struct nlist *lookup(char *);
//char *strdup(char *);

struct nlist  *install( char *name, char *defn ){
    struct nlist *np;
    unsigned hashval;
    
    if( (np = lookup(name)) == NULL ){
        np = (struct nlist *)malloc(sizeof(*np));
        if( np == NULL || (np->name = strdup(name)) == NULL )
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }else
        free((void*) np->defn);
    if( (np->defn = strdup(defn)) == NULL )
        return NULL;
    return np;
}

unsigned hash( char *s ){
    unsigned hashval;
    for( hashval= 0; *s != '\0'; s++ )
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup( char *s ){
    struct nlist *np;
    for( np= hashtab[hash(s)]; np != NULL; np = np->next )
        if( strcmp( s, np->name ) == 0 )
            return np;// found
    return NULL;
}

//** 6-5 
void undef( char *s ){
    struct nlist *tmp= NULL, *np= hashtab[hash(s)];
    if( np ){
        if( strcmp( s, np->name ) == 0 ){
            tmp = np;
            hashtab[hash(s)] = tmp->next;
        }else
            for(; np->next != NULL; np = np->next ){
                if( strcmp( s, np->next->name ) == 0 ){
                    tmp = np->next;
                    np->next = tmp->next;
                }
            }
        if( tmp )
            free( (void*)tmp );
    }
}
//**
