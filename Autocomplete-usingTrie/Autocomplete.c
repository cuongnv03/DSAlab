#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    int is_end_of_word;
    struct TrieNode *children[ALPHABET_SIZE];
};

struct TrieNode *create_node() {
    struct TrieNode *node = (struct TrieNode *) malloc(sizeof(struct TrieNode));
    node->is_end_of_word = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(struct TrieNode *root, const char *key) {
    int length = strlen(key);
    struct TrieNode *node = root;
    for (int i = 0; i < length; i++) {
        int index = tolower(key[i]) - 'a';
        if (!node->children[index]) {
            node->children[index] = create_node();
        }
        node = node->children[index];
    }
    node->is_end_of_word = 1;
}

void suggest(struct TrieNode *root, const char *prefix) {
    int length = strlen(prefix);
    struct TrieNode *node = root;
    for (int i = 0; i < length; i++) {
        int index = tolower(prefix[i]) - 'a';
        if (!node->children[index]) {
            printf("No words found with this prefix.\n");
            return;
        }
        node = node->children[index];
    }
    suggest_util(node, (char *) prefix);
}

void suggest_util(struct TrieNode *node, char *prefix) {
    if (node->is_end_of_word) {
        printf("%s ", prefix);
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            char c = 'a' + i;
            char *new_prefix = (char *) malloc(strlen(prefix) + 2);
            sprintf(new_prefix, "%s%c", prefix, c);
            suggest_util(node->children[i], new_prefix);
            free(new_prefix);
        }
    }
}

void remove_word(struct TrieNode *root, const char *key) {
    int length = strlen(key);
    struct TrieNode *node = root;
    for (int i = 0; i < length; i++) {
        int index = tolower(key[i]) - 'a';
        if (!node->children[index]) {
            printf("Word not found.\n");
            return;
        }
        node = node->children[index];
    }
    node->is_end_of_word = 0;
}

int main() {
    struct TrieNode *root = create_node();
    FILE *fp = fopen("references.txt","r");
    char str[1000];
    while(!feof(fp)){
        fscanf(fp,"%s",str);
        insert(root,str);
    }
    fclose(fp);
    char input[100];
    while (1)
    {
        printf("\n>> ");
        scanf("%s",input);
        suggest(root,input);
    }
return 0;
}

