#include <stdio.h>

int main() {
    int b[10], p[10], nb, np, i, j, worst;

    scanf("%d", &nb);
    for (i = 0; i < nb; i++) scanf("%d", &b[i]);

    scanf("%d", &np);
    for (i = 0; i < np; i++) scanf("%d", &p[i]);

    for (i = 0; i < np; i++) {
        worst = -1;
        for (j = 0; j < nb; j++)
            if (b[j] >= p[i] && (worst == -1 || b[j] > b[worst]))
                worst = j;

        if (worst != -1) {
            printf("Process %d -> Block %d\n", i + 1, worst + 1);
            b[worst] -= p[i];
        } else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
    return 0;
}
