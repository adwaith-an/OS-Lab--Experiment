#include <stdio.h>
#include <pthread.h>

void *grade(void *sub)
{
    printf("Teacher processing %s grades...\n", (char *)sub);
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, grade, "Math");
    pthread_create(&t2, NULL, grade, "Science");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
