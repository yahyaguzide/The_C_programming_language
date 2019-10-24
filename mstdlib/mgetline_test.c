#include "mstdlib.h"
#include <stdio.h>

int main(){
    char s[20];
    int i;
    while( (i= _getline( s, 20 )) != 0 ){ 
        printf( "input: %s , len: %d\n", s, i );
    }
}
