#include <stdio.h>
#include "_binary.h"

/********************************
 *  
 *  invert (x, p, n) returns x
 *  with n bits starting from p
 *  inverted
 *
 ********************************/

unsigned invert( unsigned x, unsigned p, unsigned n );

int main(){
    unsigned x;

     _getUnum( &x, stdin );
    printf( " Read in:%lu\n inverted 4 to 3:%lu", _utob(x), _utob(invert( x, 4, 3)) );
    return 0;

}

unsigned invert( unsigned x, unsigned  p, unsigned n ){
    if( p >= n ){
        return ( x^( ~(~0 << n) << (p-n) ) );
    }
    return  0;
}
