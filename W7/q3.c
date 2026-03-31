#include <stdio.h>
#include <unistd.h>

int main(void) {
    // Rewrite this code using read and write instead of the stdio functions scanf and printf
    unsigned char c;
    // scanf("%c", &c);
    read(0, &c, 1);
    // printf("%c", c);
    write(1, &c, 1);
    return 0;
}