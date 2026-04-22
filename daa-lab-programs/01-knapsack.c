#include <stdio.h>

// Function to return maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 0/1 Knapsack using Dynamic Programming
int knapsack(int W, int wt[], int val[], int n) {

    int dp[n + 1][W + 1];

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            // Base case
            if (i == 0 || w == 0)
                dp[i][w] = 0;

            // If weight of item is less than capacity
            else if (wt[i - 1] <= w)
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );

            // If item can't be included
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int val[] = {4, 5, 3, 7};
    int wt[]  = {2, 3, 1, 4};
    int W = 5;

    int n = sizeof(val) / sizeof(val[0]);

    int result = knapsack(W, wt, val, n);

    printf("Maximum Profit = %d\n", result);

    return 0;
}
