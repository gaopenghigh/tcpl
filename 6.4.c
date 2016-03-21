#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 1000
#define MAX_NODES 100000

int getword(char *word, int limit);

struct t_node *tnlist[MAX_NODES]; // array of pointers that point to tree node
int ntn= 0; // number of tree node

struct t_node {
    char *word;
    int count;
    struct t_node *left;
    struct t_node *right;
};

struct t_link_node {
    char *word;
    int count;
    struct t_link_node *next;
};


char *mystrdup(char *s) {
    char *p = malloc(strlen(s)+1);
    strcpy(p, s);
    return p;
}

void tree_to_list(struct t_node *t) {
    if (t != NULL) {
        tree_to_list(t->left);
        tnlist[ntn] = t;
        ntn++;
        tree_to_list(t->right);
    }
}

void print_tree(struct t_node *p) {
    if (p != NULL) {
        print_tree(p->left);
        printf("word=%s, count=%d\n", p->word, p->count);
        print_tree(p->right);
    }
}

void swap(struct t_node *v[], int i, int j) {
    struct t_node *t = v[i];
    v[i] = v[j];
    v[j] = t;
}

/* sort tnlist */
void sort_list(int left, int right) {
    if (left >= right) {
        return;
    }
    int slow = left;
    int fast = left + 1;
    struct t_node *pivot = tnlist[left];
    while (fast <= right) {
        if (tnlist[fast]->count >= pivot->count) {
            slow++;
            swap(tnlist, slow, fast);
        }
        fast++;
    }
    swap(tnlist, left, slow);
    sort_list(left, slow - 1);
    sort_list(slow + 1, right);
}

void print_list() {
    for (int i=0; tnlist[i] != NULL; i++) {
        printf("word=%s, count=%d\n", tnlist[i]->word, tnlist[i]->count);
    }
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
        node = (struct t_node *)malloc(sizeof(struct t_node));
        node->word = mystrdup(word);
        node->count = 1;
        node->left = NULL;
        node->right = NULL;
        root = add_node(root, node);
    }
    tree_to_list(root);
    sort_list(0, ntn-1);
    print_list();
}

