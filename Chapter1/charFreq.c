#include <stdio.h>

/* ex 1-14: histogram of char frequency */
int main()
{
    int c, i, j;
    int charCount[26];

    /* initialise counters */
    for (i = 0; i < 26; ++i) {
        charCount[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        /* c is a char between a and z */
        if (c >= 'a' && c <= 'z') {
            ++charCount[c - 'a'];
        }    
    }

    printf("Char Freq:\n");
    for (i = 0; i < 26; ++i) {
        putchar('a' + i);
        putchar(':');
        for (j = 0; j < charCount[i]; ++j) {
            printf("-");
        }
        printf("\n");
    }
}