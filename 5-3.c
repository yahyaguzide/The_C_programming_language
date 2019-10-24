#include <stdio.h>


/******************************
 *
 * strcat(s, t)
 * concats t to the end of s
 *
 * ****************************/

void _strcat(char *, char *);

int main(){
    char s[30], t[] = "World!", c[] = "Hello ";
    for( int i = 0; (s[i] = c[i]); i++ );

    _strcat( s, t );
    
    printf( "%s", s );

    return 0;
}

void _strcat( char *s, char *t ){
    // skip to the end of s
    while( *s ){ s++; };

    // this will cause a stack smash
    while( (*s++ = *t++) );
}
