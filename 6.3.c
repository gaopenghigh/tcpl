#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 1000
#define MAXLEN 1000

char getch();
void ungetch(char c);

int getword(char *word, int limit) {
    char *w = word;
    char c;
    while (isspace((c = getch())) && c != '\n') {
    }
    if (c != EOF) {
        *w = c;
        w++;
    }
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    limit--;
    while (limit > 0) {
        c = getch();
        if (isalnum(c)) {
            *w = c;
            w++;
        } else {
            ungetch(c);
            break;
        }
        limit--;
    }
    *w = '\0';
    return w[0];
}

struct linkedlist {
    int line_num;
    struct linkedlist *next;
};

struct t_node {
    char *word;
    struct linkedlist *lines;
    struct t_node *left;
    struct t_node *right;
};

struct linkedlist *malloc_linkedlist_node(int line_num) {
    struct linkedlist *p = malloc(sizeof(struct linkedlist));
    p->line_num = line_num;
    p->next = NULL;
    return p;
}

int found_in_list(struct linkedlist *l, int line_num) {
    struct linkedlist *p = l;
    while (p != NULL) {
        if (p->line_num == line_num) {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

void add_to_linkedlist(struct linkedlist *l, int line_num) {
    struct linkedlist *p = l;
    while (p->next != NULL) {
        p = p->next;
    }
    struct linkedlist *n = malloc_linkedlist_node(line_num);
    p->next = n;
}

void print_tree(struct t_node *p) {
    if (p != NULL) {
        print_tree(p->left);
        struct linkedlist *pl = p->lines;
        printf("word = %s, line numbers = ", p->word);
        while(pl != NULL) {
            printf("%d ", pl->line_num);
            pl = pl->next;
        }
        printf("\n");
        print_tree(p->right);
    }
}

char *mystrdup(char *s) {
    char *p = malloc(strlen(s)+1);
    strcpy(p, s);
    return p;
}

struct t_node *add_node(struct t_node *p, char *w, int line_num) {
    if (p == NULL) {
        p = malloc(sizeof(struct t_node));
        p->word = mystrdup(w);
        p->lines = malloc_linkedlist_node(line_num);
        p->left = NULL;
        p->right =NULL;
    } else {
        int cond = strcmp(w, p->word);
        if (cond > 0) {
            p->right = add_node(p->right, w, line_num);
        } else if (cond < 0) {
            p->left = add_node(p->left, w, line_num);
        } else {
            if (!found_in_list(p->lines, line_num)) {
                add_to_linkedlist(p->lines, line_num);
            }
        }
    }
    return p;
}

int main() {
    int len;
    char word[MAX_WORD_LEN];
    struct t_node *root = NULL;
    int line_num = 1;
    int c;
    while ((c = getword(word, MAX_WORD_LEN)) != EOF) {
        if (c == '\n') {
            line_num++;
            continue;
        }
        root = add_node(root, word, line_num);
    }
    print_tree(root);
}

