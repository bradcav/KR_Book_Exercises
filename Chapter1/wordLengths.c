#include <stdio.h>

/* ex 1-13: print histogram of word lengths in input */
int main()
{
    int c, i, j;
    int length;

    /* histogram of 5 bins e.g. 1-2, 3-4, 5-6, 7-8, 9+ */
    int wordLength[5];

    length = 0;

    /* init word length counts to 0 */
    for (i = 0; i < 5; ++i) {
        wordLength[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {  /* c is white space, not in word */
            /* did we just leave a word (length > 0)? */
            if (length > 0) {
                /* increment appropriate bin */
                if (length >= 1 && length <= 2) {
                    ++wordLength[0];
                }
                else if (length >= 3 && length <= 4) {
                    ++wordLength[1];
                }
                else if (length >= 5 && length <= 6) {
                    ++wordLength[2];
                } else if (length >= 7 && length <= 8) {
                    ++wordLength[3];
                } else {
                    /* 9 or greater */
                    ++wordLength[4];
                }
            }

            /* reset length since we have left a word */
            length = 0;
        }
        else {
            ++length;   //still in a word, incr length
        }
    }

    for (i = 0; i < 5; ++i) {
        printf("Bin %d: ", i);
        for (j = 0; j < wordLength[i]; ++j) {
            printf("-");
        }
        printf("\n");
    }
    
}