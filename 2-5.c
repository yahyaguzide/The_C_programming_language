#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/************************************
 *  
 *  any(s1, s2) return first index in
 *  s1 that matches with any char
 *  in s2, -1 else
 *  -> similar to strpbrk which
 *  returns a pointer to the Position
 *
 * **********************************/

int _any(char *s1, char *s2);

int main(){
    char s1[50];
    char s2[50];

    fgets(s1, 50, stdin);
    fgets(s2, 50, stdin);
    printf("Read in\n s1:%s s2:%s first matched Index:%d", s1, s2, _any(s1,s2) );

    return 0;
}

int _any(char *s1, char *s2){
    int index;
    for( index= 0; index < 100 && *(s1+ index) != '\0' && *(s1+ index) != '\n'; index++ ){
        for( int j= 0; j< 100 && *(s2+ j) != '\0' && *(s2+ j) != '\n'; j++ ){
            // if a match is found return index of char
            if( *(s1+ index) == *(s2+ j) ){ return index; }
        }
    }
    // if for loop is run through the string was either too long,
    // or no matches whre found
    return -1;
}

