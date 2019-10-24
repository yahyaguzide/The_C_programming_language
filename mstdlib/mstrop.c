
int mstrlen( char *s ){
    int n = 0;
    
    for( ; *s; n++, s++);

    return n;
}

void mstrcat( char *s, char *t ){
    
    //ToDo: built in check for char sizes

     for( ; *s; s++);

    for( ; (*s = *t); s++, t++ );
}

void mstrcpy( char *s, char *t ){
    
    for( ; (*s = *t); s++, t++ );
}

int mstrcmp(char *s, char *t){

    for( ; *s == *t; s++, t++){
        if( !(*s) ){ return 0;}
    }

    return *s - *t;
}


void mstrncat(char *s, char *t, int n){
    
    //ToDo: built in check for char sizes

     for( ; *s; s++);

    for( ; (*s = *t) && n; s++, t++, n-- );   
    *s = '\0';
}

void mstrncpy(char *s, char *t, int n){

     for( ; (*s = *t) && n; s++, t++, n-- );
}

int mstrncmp(char *s, char *t, int n){

    if( n ){
        n--;
        for( ; *s == *t; s++, t++, n--){
            if( !(*s) || !n ){ return 0;}
        }

    return *s - *t;
    }

    return -1;
}

char *mstrstr(char *s, char *t){
    char *s0= s, *tp = 0;

    for( ; !(*s); s++ ){
        if( !(*tp) ){
            return s0;
        }

        if( *s == *tp ){
            tp++;
        }else{
            s0 = s+1;
            tp = t;
        }
    }

    return 0;
}
