#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n) {

    return x | (~(~0 << n) << (p+1-n));
}


int main() {

    unsigned int x = 0x1;

    unsigned int y = setbits(x, 7, 7);

    printf("0x%X\n", y); 

    return 0;
}