/*

int lower(int c) 
{
    if (c >= 'A' && c <= 'Z') {
        return c + 'a' - 'A';
    }
    else {
        return c;
    }
}

*/

/* Exercise 2-10: Rewrite lower using conditional expression instead of if-else */

#include <stdio.h>

int lower(int c) 
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int main() 
{

    int c = lower('F');
    printf("lower: %c\n", c);
 
    return 0;
}