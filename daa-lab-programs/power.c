#include <stdio.h>

// Function to calculate power using Divide & Conquer
int power(int a, int n) {
    
    // Base case
    if (n == 0)
        return 1;

    // Recursive call
    int half = power(a, n / 2);

    // If exponent is even
    if (n % 2 == 0)
        return half * half;

    // If exponent is odd
    else
        return a * half * half;
}

int main() {
    int a = 2;
    int n = 5;

    int result = power(a, n);

    printf("%d^%d = %d\n", a, n, result);

    return 0;
}
