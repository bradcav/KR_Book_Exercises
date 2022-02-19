#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
void reverseLine(char line[], int len);

/* ex 1-19: reverse input string line by line */
int main () 
{
    int len;        /* current line length */
    char line[MAXLINE];     /* current input line */
    
    while ((len = getLine(line, MAXLINE)) > 0) {
        reverseLine(line, len);
        printf("%s", line);
    }  

    return 0;
}

void reverseLine(char line[], int len) 
{
    int end, i;
    char temp[len];     /* temp to store the reversed string */

    end = len - 2;  /* start at len - 2 since line[len] is '\0' and line[len-1] is '\n' */

    for (i = 0; i < len - 1; ++i) {
        temp[i] = line[end];
        --end;
    }

    /* copy chars over to line, ignoring last one since it is always newline (termination not counted in len) */
    for (i = 0; i < len - 1; ++i) {
        line[i] = temp[i];
    }
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
