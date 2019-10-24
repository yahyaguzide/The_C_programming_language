#include <stdio.h>

/************************************
 *
 *  Display the frquencieces of
 *  characters from it input relativ
 *  amount of char in the file
 *
 ************************************/

#define ASCII_COUNT 128

int main(){
    unsigned int cCount = 0;
    int c, precision = 500;

    int ascii_count[ASCII_COUNT];
    for( int i = 0; i < ASCII_COUNT; i++ ){ ascii_count[i] = 0; }
    char* ascii_name[] = { "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS", "TAB", "LF", "VT", "FF", "CR", "SO", 
                            "SI", "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "Esc", "FS", "GS", 
                            "RS", "US", "SP", "!", "\"", "#", "$", "%", "&", "\'", "(", ")", "*", "+", ",", "-", ".", "/", 
                            "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ":", ";", "<", "=", ">", "?", "@", "A", "B", "C", 
                            "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", 
                            "X", "Y", "Z", "[", "\\", "]", "^", "_", "`", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", 
                            "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "{", "|", "}", "~", "DEL"
    };

    while( (c = getchar()) != EOF ){
        ascii_count[(int)c]+= 1;
        cCount+= 1;
    }

    for( int i = 0; i < ASCII_COUNT; i++ ){
        if( ascii_count[i] != 0 ){
            printf( "%s ", ascii_name[i]);

            for( int j = 0; j < (ascii_count[i]*precision)/cCount; j++ ){
                putchar('#');
            }
            putchar('\n');
        }
    }

    return 0;
}
