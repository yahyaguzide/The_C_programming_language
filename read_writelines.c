#include <stdio.h>
#include <string.h>

#include "mstdlib/mstdlib.h"

#define MAXLINES 5000

char *lineptr[MAXLINES];


char *alloc(int);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

int main(){
    int nlines; /* number of input lines read */

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
//        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}


#define  MAXLEN 1000

char *alloc(int);

int readlines( char *lineptr[], int maxlines ){
    int len, nlines = 0;
    char *p, line[MAXLINES];

    while( (len = _getline(line, MAXLEN)) > 0 ){
        if( nlines >= maxlines || (p = alloc(len)) == NULL ){ return -1; }
        else{
            line[len-1] = '\0'; // delete newline ~ '\n'
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
   return nlines;
}

void writelines( char *lienptr[], int nlines ){
    int i;

    for( i = 0; i < nlines; i++ ){
        printf( "%s\n", lineptr[i] );
    }
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else /* not enough room */
        return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
    if (p >= allocbuf &&p <allocbuf + ALLOCSIZE)
        allocp = p;
}
