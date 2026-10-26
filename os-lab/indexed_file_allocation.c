#include <stdio.h>

int main() {
    int index_block = 5, blocks[] = {19, 21, 23, 45}, n = 4;

    printf("Index Block: %d\nFile Blocks: ", index_block);
    for (int i = 0; i < n; i++) printf("%d ", blocks[i]);
    printf("\nDirect Access Block 2 -> %d\n", blocks[2]);

    return 0;
}
