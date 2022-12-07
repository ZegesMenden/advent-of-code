#include <stdlib.h>
#include <stdio.h>

int anyOverlap(int s1, int e1, int s2, int e2) {

    if ( s1 >= s2 && s1 <= e2 ) { return 1; }
    if ( s2 >= s1 && s2 <= e1 ) { return 1; }

    return 0;

}

char strbuf[256] = {0};

int main() {

    FILE * fptr = fopen("input.txt", "r");
    if ( fptr == NULL ) { return -1; }

    int accumulator = 0;

    while (!feof(fptr)) {
        fgets(strbuf, sizeof(strbuf), fptr);

        int nums[4] = {0};

        // because every number has a seperator, i should be able to just turn those seperators into \0 and split the string?
        int j = 0;

        // pointer to "last" string ( i think )
        char * ptr = &strbuf[0];

        for ( int i = 0; i < 4; i++ ) {
            
            while ( strbuf[j] > 47 && strbuf[j] < 58 ) { j++; }
            strbuf[j++] = '\0';

            nums[i] = atoi(ptr);
            ptr = &strbuf[j];
        
        }

        // if( fullOverlap(nums[0], nums[1], nums[2], nums[3]) ) { printf("%i, %i, %i, %i\n", nums[0], nums[1], nums[2], nums[3]); }
        accumulator += anyOverlap(nums[0], nums[1], nums[2], nums[3]);

    }

    fclose(fptr);

    printf("%i\n", accumulator);

    return 0;

}