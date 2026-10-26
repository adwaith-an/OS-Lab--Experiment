#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, k = 0;
    int faults = 0, hits = 0;
    int hit;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    for (i = 0; i < n; i++) {
        hit = 0;
        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                hit = 1;
                break;
            }
        }

        if (hit) {
            hits++;
            printf("%d -> Hit\n", pages[i]);
        } else {
            frames[k] = pages[i];
            k = (k + 1) % f;
            faults++;
            printf("%d -> page fault\n", pages[i]);
        }
    }

    printf("\nTotal page faults = %d\n", faults);
    printf("Total page Hits = %d\n", hits);

    return 0;
}
