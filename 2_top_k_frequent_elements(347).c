#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} Pair;

int compare(const void *a, const void *b) {
    return ((Pair*)b)->freq - ((Pair*)a)->freq;
}

void topKFrequent(int nums[], int n, int k) {
    Pair freq[1000];
    int size = 0;

    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < size; j++) {
            if(freq[j].num == nums[i]) {
                freq[j].freq++;
                found = 1;
                break;
            }
        }
        if(!found) {
            freq[size].num = nums[i];
            freq[size].freq = 1;
            size++;
        }
    }

    qsort(freq, size, sizeof(Pair), compare);

    for(int i = 0; i < k; i++)
        printf("%d ", freq[i].num);
}
