#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 1000

int getword(char *word, int limit);

struct t_node {
    char *word;
    int count;
    struct t_node *left;
    struct t_node *right;
};

void print_tree(struct t_node *p) {
    if (p != NULL) {
        print_tree(p->left);
        printf("word=%s, count=%d\n", p->word, p->count);
        print_tree(p->right);
    }
}

char *mystrdup(char *s) {
    char *p = malloc(strlen(s)+1);
    strcpy(p, s);
    return p;
}

struct t_node *add_node(struct t_node *p, struct t_node *node) {
    if (p == NULL) {
        p = malloc(sizeof(struct t_node));
        p->word = mystrdup(node->word);
        p->count = 1;
        p->left = NULL;
        p->right =NULL;
    } else {
        int cond = strcmp(node->word, p->word);
        if (cond > 0) {
            p->right = add_node(p->right, node);
        } else if (cond < 0) {
            p->left = add_node(p->left, node);
        } else {
            p->count += 1;
        }
    }
    return p;
}

int main() {
    int len;
    char word[MAX_WORD_LEN];
    struct t_node *root;
    struct t_node *node;
    while (getword(word, MAX_WORD_LEN) != EOF) {
        printf("%s\n", word);
        node = (struct t_node *)malloc(sizeof(struct t_node));
        node->word = mystrdup(word);
        node->count = 1;
        node->left = NULL;
        node->right = NULL;
        root = add_node(root, node);
    }
    print_tree(root);
}

