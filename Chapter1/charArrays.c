#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/*print length of longest imput line */
int main () 
{
    int len;        /* current line length */
    int max;        /* max length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("Longest line: %sLength: %d\n", longest, max);   /* ex 1-16: print longest line along with its length */
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

void copy(char to[], char from[]) 
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0') {  /* (to[i] = from[i]) evaluates to the values which was assigned. */
        ++i;
    }
}