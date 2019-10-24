#include <stdio.h>

int mgetline( char *s, int maxline ){
    int i = 0;
    static char buf = 'a';

    if( buf == EOF ){ return -1; }
    for( ; i < maxline && (*s = getchar()) != '\n' && *s != EOF; s++, i++ );
  
    buf = *s;
    *s = '\0';

    return i;
}
