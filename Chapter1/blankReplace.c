#include <stdio.h>

/* ex 1-9: copy input, replacing all string of more than 1 space with a single space */
int main() 
{
    int c, countb;

    countb = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ') {     // if char is blank, incr count
            ++countb;
            if (countb <= 1) {
                putchar(c);     //only write a blank if current count is not greater than 1
            }
        } else {
            //not a blank, so reset the count and write char
            countb = 0;
            putchar(c);
        }
    }
}