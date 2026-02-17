#include <stdio.h>

// Write a c program count_chars.c that uses getchar to read in characters until the user enters Ctrl-D and then prints the total number of characters entered.


int main(void) {
    int count = 0;
    while(getchar() != EOF) {
        count++;
    }

    printf("%d\n", count);

    return 0;
}
