#include <stdio.h>
/* 
    return first location in s1 which contains any char from s2. 
    return -1 if s1 contains no chars from s2
*/
int any(char s1[], char s2[]) 
{
    int loc = -1;

    for (int i = 0; s1[i] != '\0'; ++i) {
        for (int j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }

    return loc;
}

int main()
{
    char str1[] = "hellohello";
    char str2[] = "f";

    int i = any(str1, str2);

    printf("%d\n", i);

    return 0;
}