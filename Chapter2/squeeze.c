#include <stdio.h>
/*
    delete each char in str1 which matches any char in str2
*/
void squeeze(char s1[], char s2[]) {
    int i, j, k;
    int found = 0;

    k = 0;
    //for each char in string to be changed
    for (i = 0; s1[i] != '\0'; ++i) {
        //is this char in s2?
        for (j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                found = 1;
            }
        }
        if (!found) {
            s1[k++] = s1[i];
        }    
        found = 0;
    }
    s1[k] = '\0';
}

int main()
{
    char str1[] = "hellohello";
    char str2[] = "he";

    squeeze(str1, str2);

    printf("%s\n", str1);

    return 0;
}