#include "_stdlib.h"
#include <stdio.h>

int main(){
    char prop0[] = "Test", prop1[] = "Test", prop2[] = "TeSt", prop3[] = "test", buf[20];
    //int num = 123;

    // _reverse Test
    _reverse(prop3); 
    printf( "_reverse test: %s\n", prop3);


    // _strlen Test
    printf( "_strlen test: %d\n", (_strlen(prop0) == 4) );


    // _strcmp Test
    printf( "_strcmp equal test: %d\n",_strcmp(prop0, prop1) == 0 );
    printf( "_strcmp not equal test: %d\n", _strcmp(prop1, prop2) == ('s' - 'S') );


    // _strncmp Test
    printf( "_strncmp equal test: %d\n", _strncmp(prop1, prop2, 2) == 0 );
    printf( "_strncmp not equal test: %d\n", _strncmp(prop1, prop2, 3) == ('s' -'S') );


    // _strcpy Test
    _strcpy(buf, prop0);
    printf( "_strcpy test: %s == %s\n", buf, prop1 );


    // _strncpy Test
    _strncpy(buf, prop0, 2);
    printf( "_strncpy test: %s == %s\n",buf, prop1 );


    // _strcat Test
    _strcat(buf, prop1);
    printf( "_strcat test: %s\n",buf );


     // _strncat Test
    _strncat(buf, prop1, 2);
    printf( "_strncat test: %s\n",buf );
    
}
