#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[] = {98, 183, 37, 122, 14, 124, 65, 67}, head = 53, total = 0;
    int n = 8;

    for (int i = 0; i < n; i++) {
        total += abs(req[i] - head);
        head = req[i];
    }

    printf("Total head movement: %d cylinders\n", total);

    return 0;
}
