#include <stdio.h>

/******************************
 *
 *  binary search with one 
 *  test in the loop
 *
 ******************************/

int binsearch( int x, int v[], int n );

int main(){
    int x, v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    scanf("%d", &x);
    printf( "Read In:%d\n BinSearch 0-9:%d", x, binsearch( x, v, 10 ) );

    return 0;
}

int binsearch( int x, int v[], int n ){
    int low = 0, high = n-1, mid = (low+high)/2;
    while( low < high ){
        if( x > v[mid] ){
            low = mid + 1;
        }else{
            high = mid;
        }// endIf

        mid = (low+high)/2;
    }// endWhile
    if( x == v[mid] ){ return mid; }
    return -1;
}
