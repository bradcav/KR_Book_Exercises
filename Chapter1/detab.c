#include <stdio.h>

#define TAB     8
#define MAXLINE 1000

void detab(char line[], char detabbedLine[], int len);
int getLine(char s[], int lim);

/* ex 1-20: replace tabs in input with correct num of spaces for a given set of tap stops (n)*/
int main () 
{
    int len;
    char line[MAXLINE], detabbedLine[MAXLINE];
    
    while ((len = getLine(line, MAXLINE)) > 0) {
        detab(line, detabbedLine, len);
        printf("%s", detabbedLine);
    }  

    return 0;
}

void detab(char line[], char detabbedLine[], int len)
{
    int i, j;           /* i is index of input line, j is index of output line */
    int charCount;      /* how many chars have been counted since last tab? */
    int spacesNeeded;   /* when we get a tab, how many spcaes needed to get to next tab stop? */

    charCount = 0;
    j = 0;
    for (i = 0; i < len; ++i) {
        if (line[i] == '\t') {
            spacesNeeded = TAB - (charCount % TAB);
            /* insert required spaces into output string, each spaces reduces spaces needed and incr index */
            for (;spacesNeeded > 0; --spacesNeeded, ++j) {
                detabbedLine[j] = ' ';
            }
            charCount = 0;  /* reset the char count since we reached a tab */
        }
        else {
            detabbedLine[j] = line[i];
            ++j;
            ++charCount;
        }
    }
    /* make sure null termination is added to end of string */
    detabbedLine[j] = '\0';
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
