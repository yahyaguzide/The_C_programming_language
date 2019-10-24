#include <stdio.h>


/*****************************
 *  Recursiv
 *
 *  reverse(s) 
 *  reverses a given string
 *  **************************/

void reverse( char[] );

int main(){
    
    char s[] = "reverse";
    printf( "%s\n", s );

    reverse(s);

    printf( "%s\n", s );

    return 0;
}

void reverse( char s[] ){
    static int i = 0 , j = 0, buf;
    
    if( s[++i] != '\0' ){ reverse( s ); }

    if( j < i ){
        i--;
        buf = s[i];
        s[i] = s[j];
        s[j] = buf;

        j++;
    }

}
