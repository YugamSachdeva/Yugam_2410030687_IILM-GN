#include <stdio.h>

void jobScheduling(int job[], int profit[], int deadline[], int n) {

    // Sort jobs by profit (descending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (profit[j] < profit[j + 1]) {

                // Swap profit
                int temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;

                // Swap deadline
                temp = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = temp;

                // Swap job id
                temp = job[j];
                job[j] = job[j + 1];
                job[j + 1] = temp;
            }
        }
    }

    // Find maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (deadline[i] > maxDeadline)
            maxDeadline = deadline[i];
    }

    int slot[maxDeadline + 1];

    // Initialize slots
    for (int i = 0; i <= maxDeadline; i++)
        slot[i] = -1;

    int totalProfit = 0;

    // Assign jobs
    for (int i = 0; i < n; i++) {
        for (int j = deadline[i]; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = job[i];
                totalProfit += profit[i];
                break;
            }
        }
    }

    // Output
    printf("Selected Jobs: ");
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != -1)
            printf("J%d ", slot[i]);
    }

    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    int job[] = {1, 2, 3, 4, 5};
    int profit[] = {100, 19, 27, 25, 15};
    int deadline[] = {2, 1, 2, 1, 3};
    int n = sizeof(job) / sizeof(job[0]);

    jobScheduling(job, profit, deadline, n);

    return 0;
}
