#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int g[MAX][MAX], v[MAX], n;

void dfs(int x) {
    printf("%d ", x);
    v[x] = 1;

    for (int i = 0; i < n; i++) {
        if (g[x][i] && !v[i])
            dfs(i);
    }
}

void bfs(int s) {
    int q[MAX], f = 0, r = 0;

    for (int i = 0; i < n; i++)
        v[i] = 0;

    q[r++] = s;
    v[s] = 1;

    while (f < r) {
        int x = q[f++];
        printf("%d ", x);

        for (int i = 0; i < n; i++) {
            if (g[x][i] && !v[i]) {
                q[r++] = i;
                v[i] = 1;
            }
        }
    }
}

int main() {
    int e, a, b, s;

    printf("Enter number of buildings: ");
    scanf("%d", &n);

    printf("Enter number of roads: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        printf("Enter road %d (two buildings): ", i + 1);
        scanf("%d %d", &a, &b);

        g[a][b] = 1;
        g[b][a] = 1;
    }

    printf("Enter starting building: ");
    scanf("%d", &s);

    printf("\nDFS: ");
    for (int i = 0; i < n; i++)
        v[i] = 0;
    dfs(s);

    printf("\nBFS: ");
    bfs(s);

    return 0;
}