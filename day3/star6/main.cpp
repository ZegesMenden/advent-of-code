#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char strbuf[256] = {0};

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
        
        unsigned int charmaps[3][2] = {{0, 0}, {0, 0}, {0, 0}};

        for ( int line = 0; line < 3; line ++ ) {
            fgets(strbuf, sizeof(strbuf), fptr);
            int len = strlen(strbuf)-1;
            for ( int i = 0; i < len; i++ ) { charmaps[line][(int)strbuf[i] > 96] |= 1<<char2num(strbuf[i]); }
        }
        
        unsigned int charmap_all[2] = {charmaps[0][1]&charmaps[1][1]&charmaps[2][1], charmaps[0][0]&charmaps[1][0]&charmaps[2][0]};
        
        int i = 1;
        int n = 0;
        
        while (!(i==charmap_all[0]) && !(i==charmap_all[1])) {
            i <<= 1;
            n++;
        }

        accumulator += n + (i==charmap_all[1]? 25 : 0);
        
    }
    printf("%i\n", accumulator);
}