#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n) {

    return x ^ (~(~0 << n) << (p+1-n));
}


int main() {

    unsigned int x = 0xF0;

    unsigned int y = invert(x, 7, 8);

    printf("0x%X\n", y); 

    return 0;
}