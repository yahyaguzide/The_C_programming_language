#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right,
        int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort input lines */
main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int numeric = 0, reverse= 0; /* 1 if numeric sort */

    if( argc > 1 ){
        if ( strcmp(argv[1], "-n") == 0){
        numeric = 1;
        }else if( strcmp(argv[1], "-r") ){
            reverse = 1;
        }else if( strcmp(argv[1], "-nr") || strcmp(argv[1], "-rn") ){
            numeric = 1;
            reverse = 1;
        }

    }
    // readlines here not included
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort((void**) lineptr, 0, nlines-1,
                (int (*)(void*,void*))(numeric ? numcmp : strcmp));
                
            if( reverse ){
                // reverse not added here
                mreverse( lineptr, nlines );
            }
            
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right,
        int (*comp)(void *, void *))
{
    int i, last;

    void swap(void *v[], int, int);

    if (left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) <0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1, comp);
    qsort(v, last+1, right, comp);
}

#include <stdlib.h>

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 <v2)
        return -1;
    else if (v1 >v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j;)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
