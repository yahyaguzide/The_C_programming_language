#include <stdio.h>

/*****************************************
 *
 *  This program removes trailing blanks, 
 *  blanks and tabs
 *
 ****************************************/

#define TRUE 1
#define FALSE 0
#define MAXLENGTH 1000

int _getline( char line[], int maxlegth);


int main(){
int len; 
char line[MAXLENGTH];

    while( (len = _getline(line, MAXLENGTH)) >= 0 ){
        for( int i = 0; i < len; i++ )
            putchar( line[i] );
    }

    return 0;
}


int _getline( char line[], int maxlength ){
    int i, nPos = 0;

    for( i = 0; i < (maxlength -1) && (line[i] = getchar()) != '\n' && line[i] != EOF; i++ ){
        if( line[i] != ' ' && line[i] != '\t' )
            nPos = i+1;
    }

    if( i == 0 ){
        if( line[i] == EOF )
            return -1;
    }else
        line[nPos++] = '\n';

    return nPos;
}
