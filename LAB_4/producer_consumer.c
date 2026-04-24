#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int in = 0, out = 0;
sem_t empty, full, mutex;
void producer() {
    int item;
    if (sem_trywait(&empty) != 0) {
        printf("Buffer is FULL! Cannot produce.\n");
        return;
    }
    sem_wait(&mutex);
    printf("Enter item to produce: ");
    scanf("%d", &item);
    buffer[in] = item;
    printf("Produced %d at position %d\n", item, in);
    in = (in + 1) % BUFFER_SIZE;
    sem_post(&mutex);
    sem_post(&full);
}
void consumer() {
    int item;
    if (sem_trywait(&full) != 0) {
        printf("Buffer is EMPTY! Cannot consume.\n");
        return;
    }
    sem_wait(&mutex);
    item = buffer[out];
    printf("Consumed %d from position %d\n", item, out);
    out = (out + 1) % BUFFER_SIZE;
    sem_post(&mutex);
    sem_post(&empty);
}
int main() {
    int choice;
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);
    printf("Enter ");
    printf("1. Producer ");
    printf("2. Consumer ");
    printf("3. Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                printf("Exiting...\n");
                sem_destroy(&empty);
                sem_destroy(&full);
                sem_destroy(&mutex);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

Enter 1. Producer 2. Consumer 3. Exit

Enter choice: 1
Enter item to produce: 1
Produced 1 at position 0

Enter choice: 1
Enter item to produce: 2
Produced 2 at position 1

Enter choice: 1
Enter item to produce: 3
Produced 3 at position 2

Enter choice: 2
Consumed 1 from position 0

Enter choice: 2
Consumed 2 from position 1

Enter choice: 2
Consumed 3 from position 2

Enter choice: 2
Buffer is EMPTY! Cannot consume.

Enter choice: 3
Exiting...


