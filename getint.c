#include <stdio.h>
#include <ctype.h>

int getint( int * );

int main(){
    int num, out;

    while( (out = getint( &num )) != EOF ){ printf( "%d\n%d\n", out, num ); };

    return 0;
}


int getch(void);
void ungetch(int);

// getint: get next integer from input into *pn
int getint( int *pn ){
    int c, sign;
    // skip whitepsace
    while( isspace(c = getch()) );

    if( !isdigit(c) && c != EOF && c != '+' && c != '-' ){
        // not a Number
        // Note: Do not ungetch if it is not a number it will cause a infinit loop\
        // of Zeros
//        ungetch(c);

        return 0;
    }

    sign = ( c == '-' )? -1: 1;
    if( c == '+' || c == '-' ){ c = getch(); }

    for( *pn = 0; isdigit(c); c = getch() ){ *pn = 10 * *pn +(c - '0'); }

    *pn *= sign;
    if( c != EOF ){ ungetch(c); }

    return c;
}

_Bool Buffull = 0;
int Buf;

int getch(){
    if( Buffull ){ Buffull = 0; return Buf; }
    else { return getchar(); }
}

void ungetch( int c ){
    if( !Buffull ){ Buffull = 1; Buf = c;}
}
