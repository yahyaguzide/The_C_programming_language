#include <stdio.h> 

/******************************************
 *
 *  Find the longest Line in a given input
 *
 * ****************************************/


#define MAXLINE 1000

int _getline( char line[], int maxline );
void copy( char to[], char from[] );

int main(){
    int len;
    char line[MAXLINE];
    
    while( (len = _getline( line, MAXLINE )) > 0 ){
        if( len > 79 ){
            printf("%s\n", line);
        }
    }

    return 0;

}

int _getline( char line[], int maxline ){
    int c, i;
    for( i = 0; i < (maxline - 1) && (c = getchar()) != EOF && c != '\n'; i++ )
        line[i] = c;
    if( i > 0 )
        line[i + 1] = '\0';

    return i;
}

