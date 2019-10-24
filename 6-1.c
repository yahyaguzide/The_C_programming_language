#include <stdio.h>
#include <ctype.h>

/*******************************************************
//  6-1
//
// date: 24.09.2019
// name: Yahya Guezide
// getword that can handle underscores, string constans,
// comments, or preprocessor control lines
********************************************************/

int getword(char *, int);

int main( int argc, char **argv ){
    char word[10];
    int lim = 10;

    int c;
    for(; (c= getword(word, lim)) != '\0' && c != EOF ;){ 
        printf( "%s\n", word );
    }
    return 0;
}

int getword( char *word, int lim ){
    int c, mgetch(void);
    void mungetch(int);
    char *w= word;
    
    while( isspace(c = mgetch()) || c == '\t' );

    if( c != EOF )
        *w++ = c;

    if( isalpha(c) || c =='_' || c == '#' ){
        for(; --lim > 0; w++)
         if( !isalnum(*w= mgetch()) ){
                mungetch(*w);
                break;
            }
        *w= '\0';
    
    }else if( c == '/' ){
        if( (c = mgetch()) == '/' )
            while( (c = mgetch()) != '\n' && c != EOF );
        else if( c == '*' )
            while( (c = mgetch()) != '/' && c != EOF );
        else
            mungetch(c);
    }else{
        *w = '\0';
        return c;
    }

    *w = '\0';
    return word[0];
}

int buffer;
_Bool buffrdy= 0;
int mgetch(){
    int tmp;
    if( buffrdy ){
        tmp= buffer;
        buffrdy = 0;
    }else
        tmp = getchar();
    return tmp;
}

void mungetch( int c ){
    if( !(buffrdy) ){
        buffer = c;
        buffrdy = 1;
    }
}
