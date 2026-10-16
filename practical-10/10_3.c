#include <stdio.h>

int main() {
    int t[10], n, x, h1, h2, p;

    for (int i = 0; i < 10; i++)
        t[i] = -1;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter student ID: ");
        scanf("%d", &x);

        h1 = x % 10;
        h2 = 7 - (x % 7);

        p = h1;

        while (t[p] != -1)
            p = (p + h2) % 10;

        t[p] = x;
    }

    printf("\nHash table:\n");
    for (int i = 0; i < 10; i++)
        printf("Slot %d: %d\n", i, t[i]);

    return 0;
}