//#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**************************************************
//  mgetword
//
// date: 26.09.2019
// name: Yahya Guezide
// simple algorythm to get words
// discluding c comments
// mgetch and mungetch is used
//
***************************************************/

/* mgetword: get next word or character from input */
int mgetword(char *word, int lim){
    int c, mgetch(void);
    void mungetch(int);
    char *w = word;

    while (isspace(c = mgetch()));

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

