#include <stdio.h>
#include <string.h>

int main()
{
    char dir[10], file[10][20];
    int n, i;

    printf("Enter directory name: ");
    scanf("%s", dir);

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter file %d: ", i + 1);
        scanf("%s", file[i]);
    }

    printf("\nDirectory: %s\nFiles:\n", dir);

    for (i = 0; i < n; i++)
        printf("%s\n", file[i]);

    return 0;
}
