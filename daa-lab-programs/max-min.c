#include <stdio.h>

// Function to find max and min using Divide & Conquer
void maxMin(int arr[], int left, int right, int *max, int *min) {

    // If only one element
    if (left == right) {
        *max = arr[left];
        *min = arr[left];
        return;
    }

    // If two elements
    if (right == left + 1) {
        if (arr[left] > arr[right]) {
            *max = arr[left];
            *min = arr[right];
        } else {
            *max = arr[right];
            *min = arr[left];
        }
        return;
    }

    // Divide
    int mid = (left + right) / 2;
    int max1, min1, max2, min2;

    // Conquer
    maxMin(arr, left, mid, &max1, &min1);
    maxMin(arr, mid + 1, right, &max2, &min2);

    // Combine
    *max = (max1 > max2) ? max1 : max2;
    *min = (min1 < min2) ? min1 : min2;
}

int main() {
    int arr[] = {45, 23, 85, 96, 5, 4, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max, min;

    maxMin(arr, 0, n - 1, &max, &min);

    printf("Maximum element = %d\n", max);
    printf("Minimum element = %d\n", min);

    return 0;
}
