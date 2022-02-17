#include <stdio.h>

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */

int main() {
    int c;
    int nl, nw, nc, state;

    nl = nw = nc = 0;
    state = OUT;

    while ((c = getchar()) != EOF) {
        ++nc;   /* every char increments char count */
        if (c == '\n') {
            ++nl;   /* increment new line count */
        }
        if (c == ' ' || c == '\n' || c == '\t') {   /* space, new line and tab indicate out of word */
            state = OUT;
        }
        else if (state == OUT) {    /* not leaving a word, and in OUT state means entering word */
            state = IN;
            ++nw;
        }
    }
    printf("lines: %d words: %d chars: %d\n", nl, nw, nc);
}