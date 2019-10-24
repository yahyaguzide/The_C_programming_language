#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};
enum {NO, YES};

void dcl(void);
void dirdcl(void);
int gettoken(void);
void errmsg( char * );


// type of last Token
int tokentype;
// last Token string
char  token[MAXTOKEN];
// identifyier name
char name[MAXTOKEN];
// data type
char datatype[MAXTOKEN];
char out[1000];
int prevtoken;

int main(){
    while( gettoken() != EOF ){
        strcpy( datatype, token );
        out[0] = '\0';
        dcl();
        if( tokentype != '\n' ){
            printf( "syntax error\n" );
        }
        printf( "%s: %s %s\n", name, out, datatype );
    }
    return 0;
}

// dlc: parser declarator
void dcl(){
    int ns;
    for( ns= 0; gettoken() == '*'; ){ ns++; }
    dirdcl();
    while( ns-- > 0 ){ strcat( out, " pointer to" ); }
}

// dirdlc: parse a direct declarator
void dirdcl(){
    int type;
    if( tokentype == '(' ){
        dcl();
        if( tokentype != ')' ){
            errmsg( "missing )\n" );
        }
    }else if( tokentype  == NAME ){ strcpy( name, token ); }
    else{ errmsg( "expected name or (dcl)\n" ); }

    while( (type= gettoken()) == PARENS || type == BRACKETS ){
        if( type == PARENS ){ strcat( out, " function returning" ); }
        else{
            strcat( out, " array" );
            strcat( out, " token" );
            strcat( out, " of" );
        }
    }
}

void errmsg( char *s ){
    printf( "error: %s", s );
    prevtoken = YES;
}


//### gettoken
int gettoken(){
    int c, getch(void);
    void ungetch(int);


    if( prevtoken ){
        prevtoken = 0;
        return tokentype;
    }

    char *p = token;
    while( (c= getch()) == ' ' || c == '\t' );

    if( c == '(' ){
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; );
        *p = '\0';

        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);

        return tokentype = NAME;
    } else{ return tokentype = c; }

}
