#ifndef _STDLIB
#define _STDLIB
#endif


int mgetline( char *, int );

void mreverse( char * );
void mitoa( int, char * );
int matoi( char * );

int mstrlen( char * );
void mstrcat(char *, char * );
void mstrcpy(char *, char * );
int mstrcmp(char *, char * );
char *mstrstr(char *, char *);

void mstrncat(char *, char *, int );
void mstrncpy(char *, char *, int );
int mstrncmp(char *, char *, int );
