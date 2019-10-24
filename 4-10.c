#include <stdio.h>
#include <stdlib.h>/* for atof() */
#include <ctype.h>
#include <math.h>
#include <string.h>

/********************************************
 *
 *  reverse polish notation calculator
 *  Exercise 4-3 to 4-9
 *
 *******************************************/


#define MAXOP   100 /* max size of operand or operator */
#define NUMBER  '0' /* signal that a number was found */
#define UNKNOWNMATH  -2 /* Unknown math Command */
#define SIN     -3
#define COS     -4
#define TAN     -5
#define EXP     -6
#define POW     -7


int getop(char []);
void push(double);
double pop(void);
////////////////////////////////////////////////////////////
// void defines that a function does not take any Parameters
// where a empty parameter list takes an undefined amount of
// parameters
////////////////////////////////////////////////////////////
// Exercise  4-3 ******
// Get Top element
double top(void);
// Swap Top elements with it's predecesor
void swap(void);
void flushStack(void);
// Need to be cautios, could end up in a seg fault
// the size of the stack given is in the hand of the user!!
void cloneStack( double *pStack );


/* reverse Polish calculator */
int main()
{
    int type, strIndex = 0;
    double op2;
    char s[MAXOP];
    string input;

    while ((type = getop(s, input, &strIndex)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            // Exercise 4-3 *******
            case '%':
                op2 = pop();
                double a = pop();
                if( op2 != 0 && a != 0 )
                    push( a>op2?((a/op2)-(int)(a/op2))*op2:((op2/a)-(int)(op2/a))*a );
                else
                    printf("error: Modulo 0 not Defined\n");
                break;
            //***************
            // Exercise 4-5 *******
            case UNKNOWNMATH: 
                printf("error: unknown math command %s\n", s);
                break;
            case SIN:
                push( sin(pop()) );
                break;
            case COS:
                push( cos(pop()) );
                break;
            case TAN:
                push( tan(pop()) );
                break;
            case EXP:
                push( exp(pop()) );
                break;
            case POW:
                op2 = pop();
                push( pow(pop(), op2) );
                break;
            //***************
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp <MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp >0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

// Exercise 4-4 ******
double top(void){
    if( sp > 0 )
        return val[sp -1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void swap(void){
    if( sp > 1 ){
        double _tmp = val[sp -1];
        val[sp -1] = val[sp -2];
        val[sp -2] = _tmp;
    }
}

void flushStack(void){
    for( ;sp-- > 0; ){
        val[sp] = 0.0;
    }
}

void cloneStack( double *pStack ){
        for( int i = 0; i < sp; i++ )
            pStack[i] = val[i]; // equal to *(pStack + i) = *(val + i)
}

int isMath( char s[] );
_Bool isLetter( char c );
void ungets( char s[] );

/* getop: get next character or numeric operand */
int getop(char s[], string input, int *strIndex)
{
    int i, c;

    while ((s[0] = c = input[(*strIndex += 1)]) == ' ' || c == '\t');

    s[1] = '\0';
    if (!isdigit(c) &&c != '.'){
        if( c == '-' && isdigit(c = input[(*strIndex += 1)]) )
            *strIndex -= 1;
        else{
            if( isLetter(c) )
                return isMath( s );
            else
                return c; /* not a number */
        }
    }

    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = input[(*strIndex += 1)]))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = input[(*strIndex += 1)]))
            ;
    s[i] = '\0';
    if (c != EOF)
        *strIndex -= 1;
    return NUMBER;
}

// Exercise 4-5 *******
int isMath( char s[], string input, int *strIndex ){
    int c;

    int i = 1;
    while( isLetter( c = input[(*strIndex += 1)] ) )
        s[i++] = c;
    
    s[i] = '\0';
    //toLower(s);
    if( 0 == strcmp(s, "sin") ){ i = SIN; }
    else if( 0 == strcmp(s, "cos") ){ i = COS; }
    else if( 0 == strcmp(s, "tan") ){ i = TAN; }
    else if( 0 == strcmp(s, "exp") ){ i = EXP; }
    else if( 0 == strcmp(s, "pow") ){ i = POW; }
    else{ i = UNKNOWNMATH; }

    *strIndex -= 1;

    return i;
}

_Bool isLetter( char c ){
    if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
        return 1;
    else
        return 0;
}
//**********************

