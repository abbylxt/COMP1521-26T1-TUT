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

    FILE *input = fopen(argv[1], "r");

    if (input == NULL) {
        perror("");
        exit(1);
    }

    char line[MAX_LENGTH];

    if (fgets(line, MAX_LENGTH, input) != NULL) {
        fputs(line, stdout);
    }

    return 0;
}