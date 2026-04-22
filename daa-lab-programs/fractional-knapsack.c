#include <stdio.h>

// Swap functions
void swapInt(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swapDouble(double *a, double *b) {
    double t = *a;
    *a = *b;
    *b = t;
}

// Fractional Knapsack function
double fractionalKnapsack(int W, int val[], int wt[], int n) {
    double ratio[n];

    // Calculate value/weight ratio
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)val[i] / wt[i];
    }

    // Sort items based on ratio (descending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                swapDouble(&ratio[j], &ratio[j + 1]);
                swapInt(&val[j], &val[j + 1]);
                swapInt(&wt[j], &wt[j + 1]);
            }
        }
    }

    double profit = 0.0;

    // Pick items
    for (int i = 0; i < n; i++) {
        if (wt[i] <= W) {
            profit += val[i];
            W -= wt[i];
        } else {
            profit += val[i] * ((double)W / wt[i]);
            break;
        }
    }

    return profit;
}

int main() {
    int val[] = {60, 100, 120};
    int wt[]  = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum Profit = %.2f\n", fractionalKnapsack(W, val, wt, n));

    return 0;
}
