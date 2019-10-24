#include <stdio.h>

/*********************************
 *
 *  Reverses a complete line
 *
 *********************************/

#define TRUE  1
#define FALSE 0
#define MAXLENGTH 1000

void reverse( char line[], int start, int end );
char* reverseForWord( char line[], int maxlength );
int _getline( char line[], int maxlength);

int main(){
    char line[MAXLENGTH];
    while( _getline( line, MAXLENGTH ) > 0 ){
        reverseForWord( line, MAXLENGTH );
        printf( "%s\n", line);
    }

    return 0;
}

void reverse( char line[], int start, int end ){
    char tmp;
    while( start < end ){
        tmp = line[end];
        line[end] = line[start];
        line[start]  = tmp;

        start++;
        end--;
    }
}

char* reverseForWord( char line[], int maxlength ){
    int start, end;
    _Bool INWORD = FALSE, ENDOFLINE = FALSE ;

    for( int i = 0; i < (maxlength-1) && line[i] !=  EOF && !ENDOFLINE; i++ ){
        if( line[i] == '\0' )
            ENDOFLINE = TRUE;

        if( !INWORD && (line[i] != ' ' || line[i] != '\t' || line[i] != '\0' ) ){
            start = i;
            INWORD = TRUE;
        }else if( INWORD && (line[i] == ' ' || line[i] == '\t' || line[i] == '\0' )){
            end = i-1;
            INWORD = FALSE;
            reverse( line, start, end);
        }
    }

    return line;
}

int _getline( char line[], int maxlength){
    int i = 0;
    for( ; i < (maxlength-1) && (line[i] = getchar()) != '\n' && line[i] != EOF; i++ );
    
    if( i == 0 && line[i] == '\n' )
        line[i++] = '\0';
    else
        line[i] = '\0';
    
    return i;
}
