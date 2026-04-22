#include <stdio.h>

int rob(int nums[], int n) {
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int prev1 = nums[0];
    int prev2 = 0;
    int current;

    for (int i = 1; i < n; i++) {
        current = (prev1 > (prev2 + nums[i])) ? prev1 : (prev2 + nums[i]);
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}

int main() {
    int nums[] = {2,7,9,3,1};
    printf("%d", rob(nums, 5));
}
