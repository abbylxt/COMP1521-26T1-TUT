#include <stdio.h>
#include <stdint.h>

uint32_t six_middle_bits(uint32_t u) {

    // u is 0100 0111 0110 1??? ???0 1110 0101 0110 in binary
    // The MIDDLE BITS have been represented with ?
// & / >> ^ 
    // 0100 0111 0110 1??? ???0 1110 0101 0110
    // &
    // 0000 0000 0000 0111 1110 0000 0000 0000
    // 0000 0000 0000 0??? ???0 0000 0000 0000
    // >> 13
// 0b11 1111
    return (u & 0x2F) >> 13;
}

int main(void) {
    Word input; // word = 4 bytes = 32 bit, which can be used to storage 32bit integer
    scanf("%d", input)
    printf("0x%X\n", six_middle_bits(input));
    return 0;
}