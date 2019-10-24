#include <stdio.h>
#include <ctype.h>

/**********************************
 *
 * atof() Nibba
 *
 *
 **********************************/

#define FALSE 0
#define TRUE 1


float atof( char *cStr );

int main( int argc, char **argv ){

    char *tst = argv[1];

    printf( "%s\n", tst );

    if( argc > 1 )
        printf( "%f", atof( tst ) );
    
    
    return 0;
};

float atof( char *cStr ){
    if( cStr != 0 ){
        int c, num = 0, pow = 0, numCount = 0;
        _Bool dotApeard = FALSE, eApeared = FALSE, negPow = FALSE, negNum = FALSE; 


        // check if first character is -
        if( *cStr == '-' ){ negNum = TRUE; cStr++; }

        // Dude don't make this f****** mistake again you f****** moron
        // it is && not ||
        for( ; (c = *cStr) != '\0' && c != EOF ; cStr++ ){

            if( eApeared ) { 
               if( c != '-' ){ 
                pow *= 10; 
                pow += c - 48;
               }else{
                negPow = TRUE;
               }
            }
            eApeared = eApeared || (c == 'e' || c == 'E');
       
            if( dotApeard && !eApeared ) { ++numCount; }
            dotApeard = dotApeard || (c == '.');

            if( !eApeared && isdigit(c) ){
                num *= 10;
                num += c - 48;
            }
        
        }

        // Add number of digits after the dot
        pow = negPow?pow+numCount:pow-numCount; 
        if( pow < 0 ){
            pow *= -1;
            negPow = 1;
        }
        {
            // Calculate the power
            int _tmp = 1;
            for( ; pow-- > 0 ; ){ _tmp *= 10; }
            pow = _tmp;
        }

        num = negNum? num*(-1): num*1;
        return negPow?(float)num / pow: (float)num * pow; 
    }
    return 0;
}

