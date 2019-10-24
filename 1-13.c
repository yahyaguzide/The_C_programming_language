#include <stdio.h>

/********************************************
 *
 *  Prints out a Histogram which displays
 *  word lenght's relative to the longest
 *
 *********************************************/

#define OUT 0
#define IN 1


int main(){
    unsigned int wordCount = 0, longestWord = 0, _wLength = 0;
    int c, precision  = 10;
    _Bool STATE = OUT;

    // find Longest word and get total number of Word's
    for( ; (c = getchar()) != EOF; ){
        if( c == ' ' || c == '\n' || c == '\t' ){
            if( _wLength > longestWord ){ longestWord = _wLength; }

            // If we reached the end of a Word, increment wordCount
            if( STATE == IN ){ wordCount+= 1; }

            STATE = OUT;
            _wLength = 0;
        }else{
            STATE = IN;
            _wLength+= 1;
        }

    }// endFor

    // Set up Array, 0 to longestWord-1 resamble the different Word Length's
    int arr[longestWord];
    {//##### Start Init arr #####
    for( int i = 0; i < longestWord; i++  ){
        arr[i] = 0;
    }
    }//##### End Init arr #####

    STATE = OUT;
    _wLength = 0;
    // ToDo: find a way to buffer the Data
    for( ; (c = getchar()) != EOF; ){
        if( c == ' ' || c == '\n' || c == '\t' ){
            if( STATE == IN ){ arr[_wLength - 1]+= 1; } 

            STATE = OUT;
            _wLength = 0;
        }else{
            STATE = IN;
            _wLength+= 1;
        }
    }// endFor
    
    for( ; longestWord > 0 ; longestWord-- ){
        printf( "%d, %d", longestWord, arr[longestWord - 1]);
        for( int i = 0;  i < ((arr[longestWord - 1] * 10)/wordCount); i++  ){
            putchar( '#' );
        }// endFor

        putchar('\n');
    }// endFor

}// endMain
