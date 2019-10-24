#include <stdlib.h>

#include "mlinkedlist_int.h"

/*****************************************************************
//  mlinkedlist
//
// date: 28.09.2019
// name: Yahya Guezide
// a simple linked list for the exercises in the Book
// "The C programmng lanuage"
//
*****************************************************************/

void initList( struct _List *list ){
    list->start = NULL;
    list->length = 0;
}

void freeList( struct _List *list ){
    struct _Element *tmp, *elem= list->start;
    while( elem ){
        tmp = elem->nelem;
        free(elem);
        elem = tmp;
    }
}

struct _Element *
getElem(struct _List *, int);

// Return Zero if malloc cant allocate memory 
_Bool addElem( struct _List *list, int num ){
    struct _Element *elem, *elemp;

    if( (elem = (struct _Element*)malloc(sizeof(struct _Element))) == NULL ||
        list == NULL )
    {    return 0; }

    elem->num = num;
    elem->nelem = NULL;

    if( list->length == 0 ){
        list->start = elem;
    }else{
        if( (elemp = getElem( list, list->length - 1 )) == NULL )
            return 0;
        elemp->nelem = elem;
    }

    list->length++;
    
    return 1;
}

struct _Element *
getElem( struct _List *list, int i ){
    struct _Element *elem = list->start;
    if( i < list->length && i > 0 ){
        for( ; i-- > 0; )
            elem = elem->nelem;
    }
    return elem;
}

int getNum( struct _List *list, int i ){
    struct _Element *elem;
    return (elem= getElem( list, i ))!= NULL? elem->num: -1;
}

struct _Element *
delElem( struct _List *list, int i ){
    if( list != NULL && list->start != NULL && i < list->length ){
        struct _Element *tmp, *elem = list->start;

        if( i == 0 ){
            tmp = list->start;
            list->start = elem->nelem;
            elem = list->start;
        }else{
            for(; i-- > 1 && elem->nelem->nelem != NULL; elem = elem->nelem );

            tmp = elem->nelem;
            elem->nelem = tmp->nelem;
        }

        free(tmp);
        list->length--;
        return elem;
    }
    return NULL;
}
