#include <pthread.h>
#include <stdio.h>

int balance = 1000;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* atm(void* id)
{
    int amt;

    pthread_mutex_lock(&lock);

    printf("ATM %ld - Enter withdrawal amount: ", (long)id);
    scanf("%d", &amt);

    if (amt <= balance) {
        balance -= amt;
        printf("ATM %ld - Withdrew: $%d | New Balance: $%d\n",
               (long)id, amt, balance);
    } else {
        printf("ATM %ld - Insufficient balance!\n", (long)id);
    }

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, atm, (void*)1);
    pthread_create(&t2, NULL, atm, (void*)2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
