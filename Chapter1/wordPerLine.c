#include <stdio.h>

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */

/* print out input one word per line */
int main() {
    int c;
    int state;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {   /* space, new line and tab indicate out of word */
            /* if we are leaving the word (IN to OUT) then write a new line */
            if (state == IN) {
                putchar('\n');
            }
            state = OUT;
        }
        else if (state == OUT) {    /* not leaving a word, and in OUT state means entering word, write the char */
            state = IN;     
            putchar(c);    
        }
        else {
            putchar(c);     /* normal character, so print */
        }
    }
 
}