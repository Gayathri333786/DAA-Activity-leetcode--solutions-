#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int last[256];
    for(int i = 0; i < 256; i++) last[i] = -1;

    int maxLen = 0, start = 0;

    for(int i = 0; s[i] != '\0'; i++) {
        if(last[s[i]] >= start) {
            start = last[s[i]] + 1;
        }
        last[s[i]] = i;

        int len = i - start + 1;
        if(len > maxLen) maxLen = len;
    }
    return maxLen;
}

int main() {
    char s[] = "abcabcbb";
    printf("%d", lengthOfLongestSubstring(s));
}
