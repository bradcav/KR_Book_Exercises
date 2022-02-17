#include <stdio.h>

/* count digits, white space and other */
int main()
{
    int c, i, nwhite, nother;
    int ndigit[10]; // counts for digits 0 to 9

    /* initialise counters */
    nwhite = nother = 0;
    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        /* c is a digit */
        if (c >= '0' && c <= '9') {
            ++ndigit[c-'0'];
        }
        else if (c == ' ' || c == '\n' || c == '\t') {  /* c is white space */
            ++nwhite;
        }
        else {      /* other */
            ++nother;
        }
    }

    printf("Digits =");
    for (i = 0; i < 10; ++i) {
        printf(" %d,", ndigit[i]);
    }
    printf(" white space = %d, other = %d\n", nwhite, nother);
}