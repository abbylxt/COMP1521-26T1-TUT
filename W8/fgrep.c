#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LENGTH 8192

void search_file(FILE *file, char *needle) {
    char line[MAX_LENGTH];
    char line_no = 0;
    while (fgets(line, MAX_LENGTH, file)) {
        line_no++;
    }
}

int main(int argc, char *argv[]) {

}