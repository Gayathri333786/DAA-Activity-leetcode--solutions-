#include <stdio.h>

int maxSubArray(int nums[], int n) {
    int maxSum = nums[0];
    int current = nums[0];

    for(int i = 1; i < n; i++) {
        if(current < 0)
            current = nums[i];
        else
            current += nums[i];

        if(current > maxSum)
            maxSum = current;
    }
    return maxSum;
}

int main() {
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("%d", maxSubArray(nums, 9));
}
