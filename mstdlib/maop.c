
/***********************************
 *  
 *
 *
 * *********************************/

void mreverse( char *s ){
    int buf;
    char *j = s;

    for( ; *s; s++ );
    for( ; *s == '\n' || *s == '\0'; s-- );

    for( ; s > j; s--, j++ ){
        buf = *s;
        *s = *j;
        *j = buf;
    }
}

void mitoa( int n, char *s ){
    int sign;
    char *sp = s;

    sign = n? -1: 1;
    n *= sign;

    do{
        *sp++ = n%10+'0';
    }while( (n /= 10) > 0 );

    if( sign ){ *sp++ = '-'; }
    *sp = '\0';

    mreverse(s);
}

int matoi( char *s ){
    int n = 0, sign = 1;
    if( *s == '-' ){ sign = -1; s++; }
    else if( *s == '+' ){ s++; }

    for( ; *s >= '0' && *s <= '9'; n = n*10 + *s++ - '0' );

    return n*sign;
}


