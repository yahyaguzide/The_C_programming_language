#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER '0'
#define ERROR   -2

int pop(void);
void push(int);

int getoperator(char *, int *);

int main(int argc, char *argv[]){
    int buf;


    for(int i= 1; i < argc; i++ ){
        switch( getoperator( *(++argv), &buf ) ){
            case NUMBER:
                push(buf);
                break;
            case '+':
                push( pop() + pop() );
                break;
            case '-':
                buf = pop();
                push( pop() - buf );
                break;
            case '*':
                push( pop() * pop() );
                break;
            case '/':
                buf = pop();
                if( buf == 0 ){
                    // no zero division mate
                }else{
                    push( pop()/buf );
                }
                break;
            case ERROR:
                // The Fuck mate, you bufoon
                break;
            default:
                //  What the hell is evan that
                break;
        }
    }
        printf( "= %d\n", pop() );
}

int getoperator( char *s, int *n ){

    if( !isdigit(*s) && *s != '-' && *s != '+' && *s != '*' && *s != '/' ){
        return ERROR;
    }else if( (*(s+1) == ' ' || *(s+1) == '\0') && (*s == '+' || *s == '-' || *s == '*' || *s == '/') ){
        return *s;
    }else{
        *n = atoi( s );
        return NUMBER;
    }
}


int stack[20];
int *stackp = stack;

int pop(){
    if( (stackp - stack) > 0 ){
        return *(--stackp);
    }
    return 0;
}

void push( int n ){
    if( (stackp - stack) < 20 ){
        *stackp++ = n;
    }
}
