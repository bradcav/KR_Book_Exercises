#include <stdio.h>

#define TAB     8
#define MAXLINE 1000

void detab(char line[], char detabbedLine[], int len);
void entab(char line[], char entabbedLine[], int len);
int getLine(char s[], int lim);

/* ex 1-21: replace strings of blanks by the minimum required blanks and tabs to achieve the same spacing,
this implementation favours a tab over a space when one space is needed and both would fit. */
int main () 
{
    int len;
    char line[MAXLINE], entabbedLine[MAXLINE];
    
    while ((len = getLine(line, MAXLINE)) > 0) {
        entab(line, entabbedLine, len);
        printf("%s", entabbedLine);
    }  

    return 0;
}

void entab(char line[], char entabbedLine[], int len) 
{
    int spaceCount;         //space chars needed to represent space in input
    int charCount;          //input line char count (tabs count as the number of spaces they take)
    int newLineCharCount;   //spaces taken up by chars in the new line (tabs count as the number of spaces they take)
    int spacesNeeded;       //when a tab is read, how many spaces would it need?
    int i, j;               /* i is index of input line, j is index of output line */
    int tabWillUse;         /* store how many spaces a tab would use in the current posistion */

    spaceCount = 0;
    charCount = 0;
    newLineCharCount = 0;
    j = 0;
    for (i = 0; i < len; ++i) {
        /* at a space, just incr num of spaces in current space found, and incr number of chars read from input */
        if (line[i] == ' ') {
            ++spaceCount;
            ++charCount;
        } 
        else if (line[i] == '\t') {
            /* how many spaces to get to the next tab stop? incr space count and char count by that */
            spacesNeeded = TAB - (charCount % TAB);
            spaceCount += spacesNeeded;
            charCount += spacesNeeded;
        }
        else {
            /* when read char is normal char (not tab or space), if space count > 0 then need to replace those spaces with tabs & spaces
            and copy that char to output line*/ 
            while (spaceCount > 0) {
                /* does a tab fit? */
                tabWillUse = TAB - (newLineCharCount % TAB);
                if (tabWillUse <= spaceCount) {
                    //input a tab
                    entabbedLine[j] = '\t';
                    ++j;
                    newLineCharCount += tabWillUse;
                    spaceCount -= tabWillUse;
                } else {
                    //only a space will fit
                    entabbedLine[j] = ' ';
                    ++j;
                    ++newLineCharCount;
                    --spaceCount;
                }
            }
            //once spaces have been replaced, carry on adding normal char to output line
            ++charCount;
            spaceCount = 0;
            entabbedLine[j] = line[i];
            ++newLineCharCount;
            ++j;
        }       
    }
    /*end with null termination */
    entabbedLine[j] = '\0';
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
