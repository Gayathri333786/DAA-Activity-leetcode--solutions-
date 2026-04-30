#include <stdio.h>

void generateSubsets(int nums[], int n, int index, int subset[], int size) {
    
    printf("[");
    for(int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("]\n");

    for(int i = index; i < n; i++) {
        subset[size] = nums[i];
        generateSubsets(nums, n, i + 1, subset, size + 1);
    }
}

int main() {
    int nums[] = {1, 2, 3};
    int subset[10];
    generateSubsets(nums, 3, 0, subset, 0);
    return 0;
}
