#include <stdio.h>
#include <ctype.h>

#define STRINGERSIZE(s) #s

char *ascii_spc[] = {  
    "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS", "TAB", "LF", "VT", 
    "FF", "CR", "SO", "SI", "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
    "CAN", "EM", "SUB", "Esc", "FS", "GS", "RS", "US", "SP" };

_Bool inSpecial( int n ){
    for( int i= 0; i <= 32; i++  ) /* 32  for ASCII SP */
        if( n == i )
            return 1;
    return 0;
}

int main( int argc, char **argv ){
    int c;
    _Bool numeric = 0;

    if( argc > 0 )
        for( int i= 1; i < argc; i++ ){
            if( numeric || (*argv[i] == '-' && *(argv[i]+1) == 'n') ){
                if( argc < i+1 || (!numeric && argc == i+1) ){ 
                    printf( "Error: no input given" );
                    return 1;
                }

                c = atoi(argv[numeric? i: ++i]);
                if( inSpecial(c) )
                    printf( "%s\t: %d\n", ascii_spc[c], c );
                else
                    printf( "%c\t: %d\n", c, c );
                numeric = 1;
            }else
                for( int j= 0; (c= argv[i][j]) != '\0'; j++ )
                    printf( "%c\t: %d\n", c, c );
        }

    return 0;
}
