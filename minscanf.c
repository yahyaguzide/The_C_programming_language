//#include <stdlib.h>
#include <stdio.h>
#include <stdargs.h>

/*****************************************************************
//  minscanf
//
// date: 08.10.2019
// name: Yahya Guezide
// a minimal version of scanf
// scanf scans a string from stdinput and put them in the given variables
//
*****************************************************************/

void minscanf(char*,);
int main( int argc, char **argv ){

    return 0;
}

void minscanf( char *fmt, ){
    va_list ap;
    char *p;
    int *c;
    union{
        int *ip;
        float *fp;
        char *cp;
    } u;

    va_start(ap,fmt);
    for(p= fmt; *p; p++){
        if( *p != '%' ){
            continue;
        }
        switch(*++p){
            case 'd':
                u.ip = va_arg(ap,int*);
                while( !isdigit(mgetch(c)) );
                *u.ip = c - '0';
                while( isdigit(getch(c)) )
                    *u.ip = *u.ip * 10 + c -'0';
                ungetch(c);
                break;
            case 'f':
                u.fp = va_arg(ap,float*);
                while( !isdigit(getch(c)) );
                *u.fp = c - '0';
                while( isdigit(getch(c)))
                    *.u.fp = *u.fp * 10 + c -'0';
                if( c == '.')
                    for(int i= 10; isdigit(getch(c)); i++)
                        *u.fp += ((float)c -'0') / i;
                ungetch(c);
                break;
            case 'c':
                u.cp = va_arg(ap, char*);
                while( isspace(getch(c)));
                *u.cp = c;
            case 's':
                u.cp = va_arg(ap, char*);
                while( isspace(getch(c)));
                *u.cp = c;
                for( int i= sizeof(u.cp)/sizeof(*u.cp); !isspace(getch(c)) && i-->0;)
                        *(++u.cp) = c;
                break;
        }
    }
}








