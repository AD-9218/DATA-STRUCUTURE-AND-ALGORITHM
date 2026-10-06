#include <stdio.h>
#include <stdlib.h>

struct N {
    int d;
    struct N *l, *r;
};

struct N* nn(int x) {
    struct N *n = malloc(sizeof(struct N));
    n->d = x;
    n->l = n->r = NULL;
    return n;
}

void in(struct N *t) {
    if (t == NULL) return;
    in(t->l);
    printf("%d ", t->d);
    in(t->r);
}

void pre(struct N *t) {
    if (t == NULL) return;
    printf("%d ", t->d);
    pre(t->l);
    pre(t->r);
}

void post(struct N *t) {
    if (t == NULL) return;
    post(t->l);
    post(t->r);
    printf("%d ", t->d);
}

void lev(struct N *t) {
    if (t == NULL) return;

    struct N *q[100];
    int f = 0, r = 0;

    q[r++] = t;

    while (f < r) {
        struct N *x = q[f++];
        printf("%d ", x->d);

        if (x->l) q[r++] = x->l;
        if (x->r) q[r++] = x->r;
    }
}

int main() {
    struct N *t = nn(1);

    t->l = nn(2);
    t->r = nn(3);
    t->l->l = nn(4);
    t->l->r = nn(5);
    t->r->l = nn(6);
    t->r->r = nn(7);

    printf("Inorder: ");
    in(t);

    printf("\nPreorder: ");
    pre(t);

    printf("\nPostorder: ");
    post(t);

    printf("\nLevelorder: ");
    lev(t);

    return 0;
}
