#include <stdio.h>
#include <stdlib.h>

int utf8_char_length(unsigned char byte) {
    
    if ((byte & 0x80) == 0) { // 0x80 = 10000000 
        return 1;
    } else if ((byte & 0xE0) == 0xC0) { // 0xC0 = 11000000
        return 2;
    } else if ((byte & 0xF0) == 0xE0) { // 0xE0 = 11100000
        return 3;
    } else if ((byte & 0xF8) == 0xF0) { // 0xF0 = 11110000
                                        // 0xF8 = 11111000
        return 4;
    } else {
        return -1;
    }
    
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return 1;
    }

    int count = 0;
    char *utf8_string = argv[1];

    for (int i = 0; utf8_string[i] != '\0'; i++) {
        int len = utf8_char_length(utf8_string[i]);
        count++;

        i += (len - 1);
    }

    printf("there are %d codepoints in the string\n", count);
    return 0;
}