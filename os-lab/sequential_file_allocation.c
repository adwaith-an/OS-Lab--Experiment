#include <stdio.h>

int main() {
    int start = 12, len = 5, allocated = 1;

    printf("Allocated blocks: ");
    for (int i = 0; i < len; i++) printf("%d ", start + i);
    printf("\nStatus: %s\n", allocated ? "success" : "Failed");

    return 0;
}
