// Squares a number, unless its square is too big for a 32-bit integer.
// If it is too big, prints an error message instead.

#include <stdio.h>

#define SQUARE_MAX 46340

int main(void) {
    int x;
    int y;

    printf("Enter a number: ");
    scanf("%d", &x);

    if_condition:
    if (x <= SQUARE_MAX) goto else_body;
    if_body:
    printf("square too big for 32 bits\n");

    goto if_end;

    else_body:
    y = x * x;
    printf("%d\n", y);
    
    if_end:

    return 0;
}