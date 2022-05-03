#include <limits.h>
#include <float.h>
#include <stdio.h>

int main() 
{
    printf("SIGNED\n");
    printf("Char min: %d, char max: %d\n", CHAR_MIN, CHAR_MAX);
    printf("Short min: %d, short max: %d\n", SHRT_MIN, SHRT_MAX);
    printf("Int min: %d, int max: %d\n", INT_MIN, INT_MAX);
    printf("Long min: %ld, long max: %ld\n", LONG_MIN, LONG_MAX);
    printf("Float min: %f, float max: %f\n", FLT_MIN, FLT_MAX);
    printf("Double min: %f, double max: %lf\n", DBL_MIN, DBL_MAX);
    


    printf("\nUNSIGNED\n");
    printf("Char min: %d, char max: %d\n", 0, UCHAR_MAX);
    printf("Short min: %d, short max: %d\n", 0, USHRT_MAX);
    printf("Int min: %d, int max: %u\n", 0, UINT_MAX);
    printf("Long min: %d, long max: %lu\n", 0, ULONG_MAX);

    

    return 0;
}