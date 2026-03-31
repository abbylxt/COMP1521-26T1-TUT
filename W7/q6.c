#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    int16_t num1 = 30000; 
    int16_t num2 = 30000;
    uint16_t result = num1 + num2;
    int32_t result32 = num1 + num2;
    printf("%d\n", num1);
    printf("%d\n", num2);
    printf("%d\n", result);
    printf("%d\n", result32);

    // printf("%X\n", unsigned_result);
    // printf("%d\n", numF);



    return EXIT_SUCCESS;
}