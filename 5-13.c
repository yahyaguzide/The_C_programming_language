#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "mstdlib.h"

_Bool isnumber( char *s ){
    for(; *s != '\0'; s++ ){
        if( !isdigit(*s) ){
            return 0;
        }
    }
    return 1;
}

void mgetlines( int nlines );
void mwritelines(void);

void errormsg(char *s, char *r){
    if( r == NULL )
        printf( "error: %s %s\n", s, r );
    else
        printf( "error: %s\n", s );
}

int main(int argc, char *argv[]){
    int i = 1, nlines= 10;
    
    for(; i < argc; i++ ){
        if( mstrcmp(argv[i], "-n") == 0 ){
            nlines = atoi( argv[++i] );
        }else{
            errormsg( "wrong argument", argv[i] );
            return 1;
        }
    }

    mgetlines( nlines );
    mwritelines();

    return  0;
}

#define DEFAULTLEN 100
#define BUFSIZE 1000
#define MAXLINES 10

char *rotBuf(void);
int initBuf(int);

void mgetlines( int nlines ){
    int maxlen, len;
    maxlen = initBuf( nlines );
    
    char line[maxlen];

    while( (len = mgetline( line, maxlen)) != 0 ){
        line[len==maxlen? len-1: len] = '\0';
        mstrcpy( rotBuf(), line );
    }
}

void mwritelines(){
    char *p, *start;
    int i= 0;

    start = p = rotBuf();
    do{
        if( mstrlen( p ) )
            printf( "%d: %s\n", i, p );
        p = rotBuf();
        i++;
    }while( p != start );
}

char buf[BUFSIZE];
int bufi= 0, bufEnd= 0;
int jmpsize= DEFAULTLEN;

char *rotBuf(){
    char *tmp= &buf[bufi];
    // if we reach the End of the Ring, jump to the head
    bufi = (bufi+jmpsize) >= bufEnd? 0: bufi+jmpsize;
    return tmp;
}

int initBuf( int nlines ){
    if( nlines > MAXLINES ){ nlines = MAXLINES; }

        jmpsize = BUFSIZE / nlines;
        bufEnd = nlines*jmpsize;
        bufi = 0;

        // clear buffer
        char *p, *s; 
        s = p = rotBuf();
        do{
            *p = '\0';
        }while( (p = rotBuf()) != s );

        return jmpsize;
}
