#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// please forgive me

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
int bignum; int r_decrement;
int main(int argc, char **argv) {
    srand(time(NULL));
    if ( argc > 1 ) { goto shitfart0; }
    else { goto shitfart1; }
shitfart0:
    printf("opening %s\n", argv[1]); 
    goto shitfart100;
shitfart1:
    goto shitfart10;

shitfart100:    
    fptr = fopen(argv[1], "r");
    
    accum = 0;
    while ( !feof(fptr) ) {   
        // get string
        fgets(strbuf, sizeof(strbuf), fptr);
        if ( strbuf[0] == '\n' ) { goto shitfart101; }
        
        else 
        {
            goto shitfart110;
        }

    shitfart101:
        calorie_sum.append(accum);
        accum = atoi(strbuf);
        goto shitfart111;
    shitfart110:
        accum += atoi(strbuf);
    shitfart111:
        continue;
    }

    // inverse decrementor == incrementor???
    bignum = 0; r_decrement = 0;

shitfart1100:
    r_decrement++;

    if ( r_decrement < calorie_sum.len ) { goto shitfart1000; } else { goto shitfart1001; }
shitfart1000:
    if ( calorie_sum.at(r_decrement) > bignum ) { goto shitfart1010; }
    goto shitfart1011;
shitfart1010:
    bignum = calorie_sum.at(r_decrement);
shitfart1011:
    goto shitfart1100;

shitfart1001:
    printf("%i", bignum);

shitfart11:
    return 0;
shitfart10:
    return -1;
}   




