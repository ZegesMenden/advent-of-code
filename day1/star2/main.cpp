#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// unsigned char heap[INT_MAX];

// void * _better_malloc(size_t size) {
// shitfart1101:
//     size_t addr = rand();
//     if ( INT_MAX - addr > size ) { return &heap[addr]; }
//     else { goto shitfart1101; } 
// }

// void * _better_realloc(void * ptr, size_t size) {
//     return ptr;
// }

template<class T = int>
class list {

private:   
    size_t allocated = 0;
public:

    typedef T mem_t;
    size_t len = 0;
    T * mem;

    list () {
        mem = (T*)malloc(sizeof(T));
        allocated = 1;
    };

    bool append(T val) {
        allocated++;
        len++;
        mem = (T*) realloc(mem, sizeof(T)*allocated);
        if ( mem == NULL ) { printf("realloc failed\n\n"); return false; }
        mem[len-1] = val;
    
        return true;
    }

    T at(size_t idx) { 
        if ( idx >= len ) { return NULL; }
        if ( idx < 0 ) { return mem[len-idx]; }
        return mem[idx]; 
    }

    T operator[](size_t idx) {
        return this->at(idx);
    }

};

list<int> calorie_sum; int accum;
FILE * fptr;char strbuf[256];

int main(int argc, char **argv) {
    srand(time(NULL));
    if ( argc > 1 ) { printf("opening %s\n", argv[1]); }
    else { return -1; }

    fptr = fopen(argv[1], "r");
    
    accum = 0;
    int bignum[3] = {0};
    while ( !feof(fptr) ) {   
        // get string
        fgets(strbuf, sizeof(strbuf), fptr);
        if ( strbuf[0] == '\n' ) { 
            
            for ( int i = 0; i < 3; i++ ) {
                if ( accum > bignum[i] && (accum != bignum[0] && accum != bignum[1] && accum != bignum[2])) { bignum[i] = accum; break; }
            }

            accum = atoi(strbuf);
        } else {
            accum += atoi(strbuf);
        }
                
    }

    fclose(fptr);
    fptr = fopen(argv[1], "r");

    accum = 0;
    while ( !feof(fptr) ) {   
        // get string
        fgets(strbuf, sizeof(strbuf), fptr);
        if ( strbuf[0] == '\n' ) { 
            
            for ( int i = 0; i < 3; i++ ) {
                if ( accum > bignum[i] && (accum != bignum[0] && accum != bignum[1] && accum != bignum[2])) { bignum[i] = accum; break; }
            }

            accum = atoi(strbuf);
        } else {
            accum += atoi(strbuf);
        }
                
    }

    fclose(fptr);
    fptr = fopen(argv[1], "r");

    accum = 0;
    while ( !feof(fptr) ) {   
        // get string
        fgets(strbuf, sizeof(strbuf), fptr);
        if ( strbuf[0] == '\n' ) { 
            
            for ( int i = 0; i < 3; i++ ) {
                if ( accum > bignum[i] && (accum != bignum[0] && accum != bignum[1] && accum != bignum[2])) { bignum[i] = accum; break; }
            }

            accum = atoi(strbuf);
        } else {
            accum += atoi(strbuf);
        }
                
    }

    printf("%i, %i, %i\n%i", bignum[0], bignum[1], bignum[2], bignum[0] + bignum[1] + bignum[2]);

    for ( int i = 0; i < calorie_sum.len; i++ ) {
        printf("%i, %i, %i, %i\n", calorie_sum.at(i++), calorie_sum.at(i++), calorie_sum.at(i++), calorie_sum.at(i++));
    }

    return 0;

}   




