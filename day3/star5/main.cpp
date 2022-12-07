#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char strbuf[256] = "";

int char2num(char c) {
    if ( c > 64 && c < 91 ) { return (int)c - 38 - 25; }
    if ( c > 96 && c < 123 ) { return (int)c - 96; }
    return 0;
}

int main() {

    FILE * fptr = fopen("input.txt", "r");
    if ( fptr == NULL ) { return -1; }

    int accumulator = 0;
    while (!feof(fptr)) {
        fgets(strbuf, sizeof(strbuf), fptr);

        int len = strlen(strbuf);

        unsigned int charmaps[2] = {0, 0};
                
        for ( int i = 0; i < len/2; i++ ) { charmaps[(int)strbuf[i] > 96] |= 1<<char2num(strbuf[i]); }

        for ( int i = len/2; i < len; i++ ) {           
            if ( ( charmaps[(int)strbuf[i] > 96] & 1<<char2num(strbuf[i]) ) == 1<<char2num(strbuf[i]) ) {
                accumulator += char2num(strbuf[i]) + 25*((int)strbuf[i] > 64 && (int)strbuf[i] < 91); 
                break;
            }
        }

    }
    printf("%i\n", accumulator);
}