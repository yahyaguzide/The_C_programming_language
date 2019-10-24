#include <stdio.h>

/****************************************
 *
 *  Program should 'fold' long Lines
 *  into pre defined ones in a smart way
 *
 *****************************************/


#define MAXLINE 100

void Lshift( char arr[], int size, int x );
int _getline( char arr[], int size, int *lastNonSpaceChar );

int main(){
    char buffer[MAXLINE];
    int lastChar = 0;

    for(; _getline(buffer, MAXLINE, &lastChar) > 0 ; ){
        printf("%s\n", buffer);
        Lshift(buffer, MAXLINE, lastChar);
    }

    return 0;
}

void Lshift( char arr[], int size, int x ){
    if( x > 0 ){
        for( int i = x; i < size; i++  ){ arr[i-x] = arr[i]; }
    }

}

int _getline( char arr[], int size, int *lastNonSpaceChar ){
    int i, c;
    for( i = 0; i < (size - 2) && (c = getchar()) != '\n' && c != EOF; i++ ){
        if( c != ' ' ){ *lastNonSpaceChar = i; }
        arr[i] = c;
    }

    if( c != EOF ){ 
        arr[++(*lastNonSpaceChar)] = '\0'; 
        i+= 1;
    }
    return i;
}
