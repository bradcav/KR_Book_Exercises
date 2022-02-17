#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);

/* ex 1-17: print lines with > 80 chars */
int main () 
{
    int len;        /* current line length */
    char line[MAXLINE];     /* current input line */
    
    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > 80) {
            printf("%s", line);
        }
    }  

    return 0;
}

/* getline: read a line into s, return length of line */
int getLine(char s[], int lim) 
{
    int c;  /* current char */
    int i;  /* length count and array index */

    /* i increases (until limit) as long as the next char is not EOF or new line */
    for (i = 0; i < lim-1  && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;   /* save current char into char array */
    }
    /* need to add the new line char if that was the last char */
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    /* add null termination to char array */
    s[i] = '\0';

    return i;
}
