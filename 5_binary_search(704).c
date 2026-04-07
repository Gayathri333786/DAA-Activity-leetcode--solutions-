#include <stdio.h>

int binarySearch(int nums[], int n, int target) {
    int left = 0, right = n - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int nums[] = {-1,0,3,5,9,12};
    printf("%d", binarySearch(nums, 6, 9));
}
