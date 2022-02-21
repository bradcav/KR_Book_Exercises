#include <stdio.h>

#define MAXLINE 1000

int max;                /* max length seen so far */
char line[MAXLINE];     /* current input line */
char longest[MAXLINE];  /* longest line saved here */

int getLine(void);
void copy(void);

/* using external (global variables) */
/*print length of longest imput line */
int main () 
{
    int len;        /* current line length */

    int max;           
    extern char longest[MAXLINE];  

    max = 0;
    while ((len = getLine()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
    }

    if (max > 0) {
        printf("Longest line: %sLength: %d\n", longest, max);   /* ex 1-16: print longest line along with its length */
    }    

    return 0;
}

/* getline: read a line into s, return length of line */
int getLine() 
{
    int c;  /* current char */
    int i;  /* length count and array index */

    extern char line[];

    /* i increases (until limit) as long as the next char is not EOF or new line */
    for (i = 0; i < MAXLINE-1  
        && (c = getchar()) != EOF && c != '\n'; ++i) {
            line[i] = c;   /* save current char into char array */
    }
    /* need to add the new line char if that was the last char */
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    /* add null termination to char array */
    line[i] = '\0';

    return i;
}

void copy() 
{
    int i;
    extern char longest[], line[];

    i = 0;
    while((longest[i] = line[i]) != '\0') {  /* (to[i] = from[i]) evaluates to the values which was assigned. */
        ++i;
    }
}