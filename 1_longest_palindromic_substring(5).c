#include <stdio.h>
#include <string.h>

void expand(char *s, int left, int right, int *start, int *maxLen) {
    while(left >= 0 && right < strlen(s) && s[left] == s[right]) {
        if(right - left + 1 > *maxLen) {
            *maxLen = right - left + 1;
            *start = left;
        }
        left--;
        right++;
    }
}

void longestPalindrome(char *s) {
    int start = 0, maxLen = 0;

    for(int i = 0; i < strlen(s); i++) {
        expand(s, i, i, &start, &maxLen);     
        expand(s, i, i+1, &start, &maxLen);   
    }

    for(int i = start; i < start + maxLen; i++)
        printf("%c", s[i]);
}

int main() {
    char s[] = "babad";
    longestPalindrome(s);
}
