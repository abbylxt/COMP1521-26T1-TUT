// prints out contents of $HOME/.diary

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *filename = ".diary";

int main(void) {
    // Create path $HOME/.diary

    // Get the environment variable for home
    char *value = getenv("HOME");

    int pathname_len = strlen(value) + 1 + strlen(filename) + 1;

    char *full_pathname = malloc(pathname_len * sizeof(char));
    
    snprintf(full_pathname, pathname_len, "%s/%s", value, filename);

    FILE *input = fopen(full_pathname, "r");

    char line[1084];

    while (fgets(line, 1084, input) != NULL) {
        fputs(line, stdout);
    }
 
    fclose(input);
}