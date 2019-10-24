#include <stdio.h>

int mgetline( char *s, int maxline ){
    int i = 0;

    for( ; i < maxline && (*s = getchar()) != '\n' && *s != EOF; s++, i++ );
    
    *s = '\0';

    return i;
}
