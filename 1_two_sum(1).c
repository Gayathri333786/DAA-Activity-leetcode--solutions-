#include <stdio.h>

int* twoSum(int nums[], int n, int target) {
    static int result[2];

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL;
}

int main() {
    int nums[] = {2,7,11,15};
    int target = 9;
    int *res = twoSum(nums, 4, target);

    printf("[%d, %d]", res[0], res[1]);
}
