#include <stdio.h>
#include <string.h>
#include <limits.h>

void minWindow(char *s, char *t) {
    int freq[256] = {0};

    for(int i = 0; t[i]; i++)
        freq[t[i]]++;

    int left = 0, count = strlen(t);
    int minLen = INT_MAX, start = 0;

    for(int right = 0; s[right]; right++) {
        if(freq[s[right]] > 0)
            count--;

        freq[s[right]]--;

        while(count == 0) {
            if(right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            freq[s[left]]++;
            if(freq[s[left]] > 0)
                count++;

            left++;
        }
    }

    if(minLen == INT_MAX)
        printf("");
    else {
        for(int i = start; i < start + minLen; i++)
            printf("%c", s[i]);
    }
}

int main() {
    char s[] = "ADOBECODEBANC";
    char t[] = "ABC";
    minWindow(s, t);
}
