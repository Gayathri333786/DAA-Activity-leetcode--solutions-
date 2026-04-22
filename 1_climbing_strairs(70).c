#include <stdio.h>

int climbStairs(int n) {
    if (n <= 2) return n;

    int prev1 = 2, prev2 = 1, current;
    for (int i = 3; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}

int main() {
    printf("%d", climbStairs(5)); 
}
