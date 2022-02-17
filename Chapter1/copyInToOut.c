#include <stdio.h>

int main() 
{
    int c;

    /*
    c = getchar();
    while(c != EOF) {
        putchar(c);
        c = getchar();
    }
    */

    int test = getchar() != EOF;
    printf("%d\n", test);   // ctrl+d can be used to generate EOF from stdin

    // more concise:
    while ((c = getchar()) != EOF) {
        putchar(c);
    } 
}