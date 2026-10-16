#include <stdio.h>

int main() {
    int t[10], n, x, p;

    for (int i = 0; i < 10; i++)
        t[i] = -1;

    printf("Enter number of vehicles: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter registration number: ");
        scanf("%d", &x);

        p = x % 10;

        while (t[p] != -1)
            p = (p + 1) % 10;

        t[p] = x;
    }

    printf("\nParking slots:\n");
    for (int i = 0; i < 10; i++)
        printf("Slot %d: %d\n", i, t[i]);

    return 0;
}