#ifndef MLINKEDLIST_INT_H
#define MLINKEDLIST_INT_H
#endif

struct _Element{
    int num;
    struct _Element *nelem;
};

struct _List{
    struct _Element *start;
    int length;
};

void initList(struct _List *);
void freeList(struct _List *);
_Bool addElem(struct _List *, int);

struct _Element *
getElem(struct _List *, int);

int getNum(struct _List *, int);

struct _Element *
delElem(struct _List *, int);
