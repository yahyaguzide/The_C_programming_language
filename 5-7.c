#include "mstdlib.h"

#include <string.h>
#include <stdio.h>

#define MAXLEN 1000
#define MAXSTOR 5000

int readlines( char *lineptr[], char *, int );

int main(){
    char *lineptr[MAXSTOR/MAXLEN];
    char linestore[MAXSTOR];
    int nlines;

    nlines = readlines( lineptr, linestore, MAXSTOR/MAXLEN);

    for( ; --nlines >= 0; ){
        printf( "%s\n", lineptr[nlines] );
    }
    return 0;
}

int readlines( char *lineptr[], char *linestor, int maxlines ){
    int len, nlines;
    char line[MAXLEN];
    char *p = linestor;
    char *linestop = linestor + MAXSTOR;

    nlines = 0;
    while( (len = mgetline( line, MAXLEN )) > 0 ){
        if( nlines >= maxlines || p+len > linestop ){ return -1; }
        else{
//            line[len-1] = '\0';
            mstrcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}
