#include <stdio.h>

int subarraySum(int nums[], int n, int k) {
    int count = 0;

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += nums[j];
            if(sum == k)
                count++;
        }
    }
    return count;
}

int main() {
    int nums[] = {1,1,1};
    printf("%d", subarraySum(nums, 3, 2));
}
