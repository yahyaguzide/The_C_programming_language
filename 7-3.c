//#include <stdlib.h>
#include <stdio.h>
// contains defines to controll unnamed arguments in funktions
// va_list is the type for a variable which will step through
// the arg's list, va_start initializes the argument and needs at least
// one named argument to start with, va_arg returns one argument and steps 
// the va_list variable one step further, va_end cleans up and it must be called
// before the program returns.
#include <stdargs.h>

/*****************************************************************
//  7-3
//
// date: 06.10.2019
// name: Yahya Guezide
// minprintf a simpler version of printf
//
*****************************************************************/

int main( int argc, char **argv ){

    return 0;
}

void minprintf( char *fmt, ){
    enum{LeftJustify= 01, Max= 02}
    
    va_list ap;
    char *p;
    unsigned int opnum1, opnum2, *opnump;

    struct{
        unsigned int is_leftjustify : 1;
        unsigned int is_maxchar : 1;
    }flags;

    union {
        char *sval;
        int ival;
        unsigned int uval;
        double dval;
    } arg;

    va_start(ap, start);
    for( p= fmt; *p; p++){
        if( *p != '%' ){
            putchar( *p );
            continue;
        }
        opnum1 = opnum2 = 0;
        switch( *++p ){
            case 'd':
                arg.ival = va_arg(ap,int);
                printf("%d", arg.ival);
                break;
            case 'u':
                arg.uval = va_arg(ap,unsigned int);
                printf("%u", arg.uval);
            case  'f':
                arg.dval = va_arg(ap, double);
                printf(*arg.dval);
                break;
            case 's':
                if( flags.is_leftjustify )
                    for(; opnum1 < 0; opnum1--)
                        putchar(' ');

                if( flags.is_maxchar )
                    for( arg.sval= va_arg(ap, char*); *arg.sval && opnum2 > 0; arg.sval++, opnum2-- )
                        putchar(*arg.sval);
                else
                    for( arg.sval= va_arg(ap, char*); *arg.sval; arg.sval++ )
                        putchar(*arg.sval);
                
                for(; opnum1 < 0; opnum1-- )
                    putchar(' ');
                break;
            case 'c':
                arg.ival= va_arg(ap, char);
                purchar(arg.ival);
            case '-':
                flags.is_leftjustify = 1;
            case '.':
                flags.is_maxchar = 1;
            default:
                if( isdigit(*p) ){
                    if( flags.is_maxchar ){ opnump = &opnum2; }
                    else{ opnump = &opnum1; }
                    for(; isdigit(*p); p++){
                        *opnump = 10 * (*opnump) + *p - '0';
                    }
                }else
                    putchar( *p );
                break;
        }
    }
}
