#include <stdio.h>

int main() {
    int p[50], F[10], r[10], n, nf, i, j, k, pos, hit, min;
    int faults = 0, hits = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &p[i]);
    scanf("%d", &nf);

    for (i = 0; i < nf; i++) F[i] = -1, r[i] = 0;

    printf("\n Page \t Status \t\t Frames\n");
    for (i = 0; i < n; i++) {
        hit = 0;
        for (j = 0; j < nf; j++)
            if (F[j] == p[i]) { hit = 1; r[j] = i + 1; break; }

        if (hit) {
            hits++;
            printf("%d\t Hit\t\t", p[i]);
        } else {
            pos = -1;
            for (j = 0; j < nf; j++)
                if (F[j] == -1) { pos = j; break; }

            if (pos == -1) {
                min = r[0]; pos = 0;
                for (j = 1; j < nf; j++)
                    if (r[j] < min) min = r[j], pos = j;
            }
            F[pos] = p[i];
            r[pos] = i + 1;
            faults++;
            printf("%d\t page fault\t", p[i]);
        }

        for (k = 0; k < nf; k++)
            if (F[k] == -1) printf("- ");
            else printf("%d ", F[k]);
        printf("\n");
    }
    printf("\n Total page Faults = %d\n", faults);
    printf("Total page Hits = %d\n", hits);
    return 0;
}
