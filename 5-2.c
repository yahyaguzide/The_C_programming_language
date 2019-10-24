#include <stdio.h>
#include <ctype.h>

/****************************
 *
 * getfloat( float * )
 * reads next float in input
 *
 * **************************/


int getfloat( float * );

int main(){
    float num;

    while( getfloat( &num ) != EOF ){ printf( "---\n%f\n", num  ); }

    return 0;
}


int getch( void );
void ungetch( int );

int getfloat( float *pn ){
    int c, sign;

    while( isspace(c = getch()) );

    if( !isdigit(c) && c != EOF && c != '+' && c != '-' ){ return 0;}
    
    sign = ( c == '-' )? -1: 1;
    if( c == '+' || c == '-' ){ c = getch(); }

    for( *pn = 0; isdigit(c); c = getch() ){ *pn = 10 * *pn +(c- '0'); }

    if( c == '.' ){
        int numerator = 10;
         for( ; isdigit(c = getch()); ){ 
             *pn += (float)(c- '0')/numerator; 
             numerator *= 10; 
         }
    }

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

