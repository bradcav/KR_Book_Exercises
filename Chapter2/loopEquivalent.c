/* 
for (i = 0; i < lim-1  && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;   
}
*/

#include <stdio.h>

#define MAX_STRING_LENGTH 100


/* equivalent loop to one above without using && or || */
int main()
{
    int i = 0;
	int lim = MAX_STRING_LENGTH;
	int c;

	char s[MAX_STRING_LENGTH];

    while (i < lim - 1) {
        c = getchar();

        if (c == EOF) {
            break;
        }

        if (c == '\n') {
            break;
        }

        s[i++] = c;
    }

    s[i] = '\0';

    return 0;
}