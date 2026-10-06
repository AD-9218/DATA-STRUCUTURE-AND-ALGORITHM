#include <stdio.h>
#include <stdlib.h>

struct N {
    int d;
    struct N *l, *r;
};

struct N* ins(struct N *t, int x) {
    if (t == NULL) {
        t = malloc(sizeof(struct N));
        t->d = x;
        t->l = t->r = NULL;
        return t;
    }

    if (x < t->d)
        t->l = ins(t->l, x);
    else if (x > t->d)
        t->r = ins(t->r, x);

    return t;
}

void in(struct N *t) {
    if (t == NULL)
        return;

    in(t->l);
    printf("%d ", t->d);
    in(t->r);
}

int main() {
    struct N *t = NULL;
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;

    for (int i = 0; i < n; i++)
        t = ins(t, a[i]);

    printf("Inorder: ");
    in(t);

    return 0;
}