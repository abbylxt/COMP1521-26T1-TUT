#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LENGTH 8192

int main(int argc, char *argv[]) {
    // This program should only run for argc == 2
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    FILE *output = fopen(argv[1], "w");

    if (output == NULL) {
        perror("");
        exit(1);
    }

    char line[MAX_LENGTH];

    if (fgets(line, MAX_LENGTH, stdin) != NULL) {
        fputs(line, output);
    }

    return 0;
}