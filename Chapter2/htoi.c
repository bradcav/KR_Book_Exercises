#include <string.h>
#include <stdio.h>

int htoi(char *hex) {

    int mul = 1;
    char c;
    int num = 0;

    int len = strlen(hex);
    int end = 0;

    //is there a 0x at the start? ignore first two chars if so
    if (len > 2) {
        if (hex[1] == 'x' || hex[1] == 'X') {
            end = 2;
        }
    }


    for (int i = len - 1; i >= end; --i) {
        c = hex[i];

        if (c >= '0' && c <= '9') {
            num += mul * (c - '0');
        } else if (c >= 'a' && c <= 'f') {
            num += mul * (c - 'a' + 10);
        } else if (c >= 'A' && c <= 'F') {
            num += mul * (c - 'A' + 10);
        }

        mul *= 16;
    }

    return num;

}

int main()
{

    int i = htoi("0Xdead");

    printf("%d\n", i);

    return 0;
}