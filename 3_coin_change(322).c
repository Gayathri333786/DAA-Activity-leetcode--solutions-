#include <stdio.h>
#include <limits.h>

int coinChange(int coins[], int n, int amount) {
    int dp[amount + 1];

    for (int i = 0; i <= amount; i++)
        dp[i] = amount + 1;

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                if (dp[i] > dp[i - coins[j]] + 1)
                    dp[i] = dp[i - coins[j]] + 1;
            }
        }
    }

    return (dp[amount] > amount) ? -1 : dp[amount];
}

int main() {
    int coins[] = {1,2,5};
    printf("%d", coinChange(coins, 3, 11)); 
}
