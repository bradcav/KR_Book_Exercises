#include <stdio.h>

unsigned int rightrot(unsigned int x, int n) {

    //is the right most bit set? need to carry it over to the left if so
    for (int i = 0; i < n; ++i) {
        unsigned lsb = x & 1u;
        x >>= 1;    //rotate one place to right

        //set the left most bit if it needs setting
        x |= lsb << (sizeof(x) * 8) - 1;
    }

    return x;
    
}


int main() {

    unsigned int x = 0x3;

    unsigned int y = rightrot(x, 2);

    printf("0x%X\n", y); 

    return 0;
}