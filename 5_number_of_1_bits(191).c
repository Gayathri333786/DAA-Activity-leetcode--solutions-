#include <stdio.h>

int hammingWeight(unsigned int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main() {
    printf("%d", hammingWeight(11)); 
}
