#include <stdio.h>

int main(){

    int c;
    long double Cc, Lc = 0;

    // pre or post incrementation in a for loop changes nothing
    for( Cc = 0; (c = getchar()) != EOF; Cc++ ){
        if( c == '\n' ) {Lc+= 1;}
    }

    printf( "LineCount: %.0Lf\nCharcount: %.0Lf\n", Lc, Cc );

    return 0;
}
