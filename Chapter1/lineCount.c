#include <stdio.h>

int main() 
{
    // ex 1-8: count blanks, tabs and new lines
    int c, nl, nt, nb;

    nl = nt = nb = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {        // single quotes to represent int value of a char
            ++nl;
        }
        if (c == '\t') {
            ++nt;
        }
        if (c == ' ') {
            ++nb;
        }
    }
    printf("lines: %d\ttabs: %d\tblanks: %d\n", nl, nt, nb);
}