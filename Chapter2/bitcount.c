/*
    In a 2's complement system, x &= x-1 always deleted rightmost 1-bit.
    e.g
    x =     0110    -> 6
    x-1 =   0101    -> 5
    x & (x-1) -> 0100

    eg2
    x =     1100    -> -4
    x-1 =   1011    -> -5
    x & (x-1) -> 1000

    This can be used as a fast way to count number of 1-bits
*/

#include <stdio.h>

int countbits(int x) {
    int count = 0;
    while(x) {
        ++count;
        x &= (x-1);
    }

    return count;
}

int main() {

    int x = -2147483647;
    unsigned int y = countbits(x);

    printf("num of 1-bits: %d\n", y);
 
    return 0;
}