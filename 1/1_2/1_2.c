#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

volatile int a = 0;
volatile int lock = 0;


void spin_lock() {
    asm volatile(
        /*YOUR CODE HERE*/

        /****************/
        :
        : "m" (lock)
        : "eax", "memory"
    );
}

void spin_unlock() {
    asm volatile(
        /*YOUR CODE HERE*/

        /****************/
        :
        : "m" (lock)
        : "eax", "memory"
    );
}


void *thread(void *arg) {

    for(int i=0; i<10000; i++){
        spin_lock();
        a = a + 1;
        spin_unlock();
    }
    return NULL;
}

int main() {
    FILE *fptr;
    fptr = fopen("1.txt", "a");
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread, NULL);
    pthread_create(&t2, NULL, thread, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    fprintf(fptr, "%d ", a);
    fclose(fptr);
}