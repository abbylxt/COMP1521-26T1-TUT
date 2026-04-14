// print_metadata.c (minimal; no error checking, uses ternaries + bitwise masks)
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
    struct stat st;
    // Use lstat so symlinks show 'l' like `ls -l`
    stat(argv[1], &st);

    char p[11];
    // file type
    mode_t perms = st.st_mode;

    p[0] = S_ISDIR(perms) ? 'd' : '-';

    // hint look at the macros in open(2)
    // user
    p[1] = S_IRUSR & perms ? 'r' : '-';
    p[2] = S_IWUSR & perms ? 'w' : '-';
    p[3] = S_IXUSR & perms ? 'x' : '-';

    // group
    p[4] = S_IRGRP & perms ? 'r' : '-';
    p[5] = S_IWGRP & perms ? 'w' : '-';
    p[6] = S_IXGRP & perms ? 'x' : '-';

    // others
    p[7] = S_IROTH & perms ? 'r' : '-';
    p[8] = S_IWOTH & perms ? 'w' : '-';
    p[9] = S_IXOTH & perms ? 'x' : '-';

    p[10] = '\0';

    printf("size: %lld\n", (long long)st.st_size);
    printf("perms: %s\n", p);
    return 0;
}