#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmp(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

void mergeIntervals(Interval arr[], int n) {
    qsort(arr, n, sizeof(Interval), cmp);

    Interval res[100];
    int index = 0;

    res[index] = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i].start <= res[index].end) {
            if(arr[i].end > res[index].end)
                res[index].end = arr[i].end;
        } else {
            index++;
            res[index] = arr[i];
        }
    }

    for(int i = 0; i <= index; i++)
        printf("[%d,%d] ", res[i].start, res[i].end);
}
