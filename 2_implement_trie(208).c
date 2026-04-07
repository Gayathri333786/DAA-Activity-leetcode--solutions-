#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Trie {
    struct Trie* children[26];
    bool isEnd;
} Trie;

Trie* createNode() {
    Trie* node = (Trie*)malloc(sizeof(Trie));
    for(int i = 0; i < 26; i++) node->children[i] = NULL;
    node->isEnd = false;
    return node;
}

void insert(Trie* root, char *word) {
    Trie* cur = root;
    for(int i = 0; word[i]; i++) {
        int idx = word[i] - 'a';
        if(cur->children[idx] == NULL)
            cur->children[idx] = createNode();
        cur = cur->children[idx];
    }
    cur->isEnd = true;
}

bool search(Trie* root, char *word) {
    Trie* cur = root;
    for(int i = 0; word[i]; i++) {
        int idx = word[i] - 'a';
        if(cur->children[idx] == NULL)
            return false;
        cur = cur->children[idx];
    }
    return cur->isEnd;
}

bool startsWith(Trie* root, char *prefix) {
    Trie* cur = root;
    for(int i = 0; prefix[i]; i++) {
        int idx = prefix[i] - 'a';
        if(cur->children[idx] == NULL)
            return false;
        cur = cur->children[idx];
    }
    return true;
}
