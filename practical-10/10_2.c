#include <stdio.h>
#include <stdlib.h>

struct Node {
    int d;
    struct Node *next;
};

int main() {
    struct Node *t[10];
    int n, x, p;

    for (int i = 0; i < 10; i++)
        t[i] = NULL;

    printf("Enter number of books: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter book code: ");
        scanf("%d", &x);

        p = x % 10;

        struct Node *nn = malloc(sizeof(struct Node));
        nn->d = x;
        nn->next = t[p];
        t[p] = nn;
    }

    printf("\nShelf contents:\n");
    for (int i = 0; i < 10; i++) {
        printf("Shelf %d: ", i);

        struct Node *q = t[i];

        while (q != NULL) {
            printf("%d ", q->d);
            q = q->next;
        }

        printf("\n");
    }

    return 0;
}