#include "_binary.h"

/******************************
 *
 *  bitcount counts all 1-bits
 *  in a given number
 *
 ******************************/

int bitcount( unsigned x );

int main(){
   unsigned x;
   _getUnum( &x, stdin );
   printf(" Read in:%lu\n counter 1-bit:%d", _utob(x), bitcount( x ));

    return  0;
}

int bitcount( unsigned x ){
    int counter;
    for( counter= 0; x; counter+= 1)
        (x &= (x-1));
    return counter;    
}
