// Print every third number from 24 to 42.
#include <stdio.h>

int main(void) {
    // for (int x = 24; x < 42; x += 3) {
    //     printf("%d\n", x);
    // }

    // int x = 24;

    // while (x < 42) {
    //     printf("%d\n", x);
    //     x += 3
    // }

    int x = 24;

loop:
    if (x >= 42) goto loop_end;
        
    printf("%d", y);
    printf("\n");
        
    x += 3;

    goto loop;

loop_end:

    return 0;
}