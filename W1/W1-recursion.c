// This program scans in a number n and prints the sum of all integers up to and including n.
#include <stdio.h>

int sum(int n);
int sum_recursive(int n);

int main(int argc, char *argv[]) {
        int n;
        printf("Enter a number: ");
        scanf("%d", &n);

        int result = sum_recursive(n);
        printf("Sum of all numbers up to %d = %d\n", n, result);

        return 0;
}

// using recursion
int sum_recursive(int n) {
    if (n == 1) {
        // stopping condition (what is the end case)
        return 1;
    }
    return n + sum_recursive(n - 1);
}

// no recursive 
int sum(int n) {
    int result = 0;
    for (int i = 0; i <= n; i++) {
        result += i;
    }
    return result;
}