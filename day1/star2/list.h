#include <stdlib.h>

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