#include <stdio.h>

void combinationSum(int arr[], int n, int target, int index, int result[], int size) {
    if(target == 0) {
        for(int i = 0; i < size; i++)
            printf("%d ", result[i]);
        printf("\n");
        return;
    }

    for(int i = index; i < n; i++) {
        if(arr[i] <= target) {
            result[size] = arr[i];
            combinationSum(arr, n, target - arr[i], i, result, size + 1);
        }
    }
}

int main() {
    int arr[] = {2, 3, 6, 7};
    int result[50];
    combinationSum(arr, 4, 7, 0, result, 0);
    return 0;
}
