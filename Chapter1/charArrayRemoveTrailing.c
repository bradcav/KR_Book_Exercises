#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
int getLength(char line[]);
void stripLine(char line[], int len);

/* ex 1-18: strip trailing blanks and tabs, and completely blank lines */
int main () 
{
    int len;        /* current line length */
    char line[MAXLINE];     /* current input line */
    
    while ((len = getLine(line, MAXLINE)) > 0) {
        printf("Len before strip: %d\n", len);
        stripLine(line, len);
        printf("%s", line);
        printf("Len after strip: %d\n", getLength(line));
    }  

    return 0;
}

int getLength(char line[]) 
{
    int i;

    i = 0;
    while(line[i] != '\0') {
        ++i;
    }
    return i;
}

void stripLine(char line[], int len)
{
    int i;

    /* check if line is completely blank (just newline '\n') */
    if (line[0] == '\n') {
        line[0] = '\0';
        return;
    }

    /* start from end of string and work backwards, at the first non-blank space char, newline and termination char will be appended to string */
    for (i = len-2; i >= 0; --i) {      /* start at len-2 to skip the newline char at end of string */
        if (line[i] != '\t' && line[i] != ' ') {
            line[i+1] = '\n'; /* re-add the newline char after string when first char is found */
            line[i+2] = '\0';
            return;
        } 
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
