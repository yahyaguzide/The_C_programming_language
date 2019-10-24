#include <stdio.h>

/****************************************
 *
 * strend(s, t)
 * retruns 1 if t occurs at teh end of s
 * else returns 0
 * **************************************/

_Bool _strend(char *, char *);

int main(){

    return 0;
}

_Bool _strend( char *s, char *t ){
    char *s_ = s, *t_ = t;
    while( *s_ ){ s_++; }

    for( ;s < s_; s++ ){
        if( *s == *t_ ){
            t_++;
        }else{ t_ = t; }
    }
    
    return *t_? 0: 1;
}
