#include <stdio.h>

#define     LOWER   0
#define     UPPER   300
#define     STEP    20

/* print fahrenheit to celsius table 
    for fahr = 0, 20, ..., 300*/
int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    printf("Fahr\tCelsius\n");
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);    // %n is the width of the number to show, prints the numbers in a field that wide (aligned right)
        fahr = fahr + step;
    }   

    printf("\n\n\n");

    /* Exercise 1-5: use a for loop and print the table in reverse */
    int fahr_int;
    printf("Reverse order:\n");
    for (fahr_int = UPPER; fahr_int >= LOWER; fahr_int = fahr_int - STEP) {
        printf("%3d\t%6.1f\n", fahr_int, (5.0/9.0)*(fahr_int-32));
    }
} 
