#include <stdio.h>

/********************************************
 *
 *  Counting Tab's Blanklines' and NewLines 
 *
 ********************************************/

int main(){

    int c, pre_c = 0;
    long double Tc = 0, BLc = 0, NLc = 0;

    // pre or post incrementation in a for loop changes nothing
    for( ; (c = getchar()) != EOF; ){
        if( c == '\n' ) {
            if( pre_c == '\n' ){ 
                // increment BlankLine count
                BLc+= 1; 
            }
            // incremetn Line count
            NLc+= 1;
        }else if( c == 9 ){ // check for Horizontal tab -> 09
            Tc+= 1;
        }
        // set pre_c as the char we read earlier
        pre_c = c;
    }

    printf( "TabCount: %.0Lf\nBlankLinecount: %.0Lf\nNewLinecount: %.0Lf\n", Tc, BLc, NLc );

    return 0;
}
