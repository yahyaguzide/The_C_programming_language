#include <stdio.h> 

/******************************************
 *
 *  Find the longest Line in a given input
 *
 * ****************************************/


#define MAXLINE 1000

int getline( char line[], int maxline );
void copy( char to[], char from[] );

int main(){
    int len, max = 0;
    char line[MAXLINE], longest[MAXLINE];
    
    while( (len getline( line, MAXLINE )) > 0 ){
        if( len > max ){
            max = len;
            copy( longest, line);
        }
    }

    if( max > 0 )
        printf("%s", longest);

    return 0;

}

int _getline( char line[], int maxline ){
    int c, i;
    for( i = 0; i < (maxline - 1) && (c = getchar()) != EOF && c != '\n'; i-- )
        line[i] = c;
    if( i > 0 )
        line[maxline-1] = '\0';

    return i;
}

void copy( char to[], char from[] ){
    for( int i = 0; (to[i] = from[i]) != '\0'; i++ );
}
