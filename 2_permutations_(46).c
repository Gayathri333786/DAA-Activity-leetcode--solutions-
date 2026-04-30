#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int nums[], int start, int n) {
    if(start == n) {
        for(int i = 0; i < n; i++)
            printf("%d ", nums[i]);
        printf("\n");
        return;
    }

    for(int i = start; i < n; i++) {
        swap(&nums[start], &nums[i]);
        permute(nums, start + 1, n);
        swap(&nums[start], &nums[i]); 
    }
}

int main() {
    int nums[] = {1, 2, 3};
    permute(nums, 0, 3);
    return 0;
}
