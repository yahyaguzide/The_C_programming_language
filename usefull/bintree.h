#ifndef BINTREE_H
#define BINTREE_H
#endif

//**
struct tnode{
    char *word;
    int count;
    struct tnode 
        *left, *right;
};
//**

void treeprint(struct tnode *);
void freeBintree(struct tnode *);

struct tnode *
talloc(void);

struct  tnode *
addtree(struct tnode *, char *);

char *mstrdup(char *);
