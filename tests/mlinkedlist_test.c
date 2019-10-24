#include <stdlib.h>
#include <stdio.h>

#include "../usefull/mlinkedlist_int.h"

/*****************************************************************
//  mlinkedlist_test.c
//
// date: 28.09.2019
// name: Yahya Guezide

*****************************************************************/

_Bool addElem(struct _List *, int);
struct _Element *
getElem(struct _List *, int);
struct _Element *
delElem(struct _List *, int);

int main( int argc, char **argv ){
    struct _List list;
    initList( &list );

    _Bool b;
    struct _Element *elem;
    for( int i= 0 ; i < 11 ; i++ ){
        b = addElem( &list, i );
        elem = getElem( &list, i ); 
        printf( "--added Element--\
                \n status: %d\
                \n length: %d\
                \n number: %d\n", b, list.length, elem->num );
    }

    printf( "\n" );

    for( int i= 0; i < 11; i++ ){
        printf( "%d ", getNum(&list, i) );
        if( i%5 == 0 )
            printf( "\n" );
    }

    printf( "\n" );
 
    for( int i= 0; i++ < 11; elem = delElem( &list, list.length - 1 ) ){
        printf( "--deleted Element-- \
                \n index:   %d \
                \n last:    %d\n", i, elem!= NULL? elem->num: 0 );
    }

    return 0;
}

