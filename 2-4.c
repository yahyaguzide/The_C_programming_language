#include <stdio.h>
#include <stdlib.h>

/***************************************
 *
 *  _squeeze(string1, string2 ) deletes 
 *  char's in string1 that matches with
 *  a cahr in string2
 *
 *  similar function is squeeze(s1, s2)
 *
 * *************************************/

#define TRUE 1
#define FALSE 0

int _squeeze( char s1[], char s2[] );

int main(){
    char s1[50];
    char s2[26];

    fgets(s1, 50, stdin);
    fgets(s2, 26, stdin);

    printf( "Read in\ns1:%ss2:%s", s1, s2);
    int i = _squeeze( s1, s2 );
    printf( " Num of EqualChars:%d\n Squeeze:%s", i, s1);
    return 0;
}

int _squeeze( char s1[], char s2[] ){
    int i, n = 0;
    _Bool _write;
    for( i= 0; s1[i] != '\0' && s1[i] != '\n'; i++ ){
        // set _write to TRUE if no equivalent char is found it will be written
        _write = TRUE;
        for( int j= 0; s2[j] != '\0' && s2[j] != '\n'; j++ ){
            if( s1[i] == s2[j] ){ n+= 1; _write = FALSE; break; }
        }//endFor
        // shift char to char that needs to be overwritten
        if( _write ){ s1[i - n] = s1[i]; }
    }// endFor
    s1[i - n] = '\0';
    return n;
}
