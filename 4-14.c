#include <stdio.h>


/*************************************
 *
 * Preprocessor operations
 * swap(t, x, y)
 * swaps variable x and y from type t
 *
 * ***********************************/


#define swap(t, x, y)   {\
                        t buf= x;\
                        x= y;\
                        y= buf;\
                        }

int main(){
    int x= 0, y= 1;

    printf( " x= %d\n y= %d\n-------\n", x, y );

    swap( int, x, y );

    printf( " x= %d\n y= %d\n", x, y );
    return 0;
}
