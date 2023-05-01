 #include <iostream>
#include <thread>
#include <semaphore.h>
#include <vector>

using namespace std;

// Initialize the semaphores
sem_t mutex;
sem_t empty_slots;
sem_t full;

// Declare the buffer and other variables
vector<int> buffer;
int buffer_size;
int num_items_to_produce;
int num_items_to_consume;
int item_counter = 0;
int producer_counter = 0;
int consumer_counter = 0;

// Function to produce an item and add it to the buffer
void producer()
{
    while (producer_counter < num_items_to_produce) {
        // Wait for an empty slot in the buffer
        sem_wait(&empty_slots);
        
        // Acquire the mutex lock
        sem_wait(&mutex);
        
        // Produce an item and add it to the buffer
        item_counter++;
        buffer.push_back(item_counter);
        cout << "Producer produces item " << item_counter << endl;
        producer_counter++;

        // Release the mutex lock
        sem_post(&mutex);
        
        // Signal that the buffer is no longer empty
        sem_post(&full);
    }
}

// Function to consume an item and remove it from the buffer
void consumer()
{
    while (consumer_counter < num_items_to_consume) {
        // Wait for a full slot in the buffer
        sem_wait(&full);
        
        // Acquire the mutex lock
        sem_wait(&mutex);
        
        // Consume an item from the buffer
        int item = buffer.back();
        buffer.pop_back();
        cout << "Consumer consumes item " << item << endl;
        consumer_counter++;
        
        // Release the mutex lock
        sem_post(&mutex);
        
        // Signal that the buffer is no longer full
        sem_post(&empty_slots);
    }
}

int main()
{
    // Prompt the user to enter the buffer size, number of items to produce, and number of items to consume
    cout << "Enter the buffer size: ";
    cin >> buffer_size;
    cout << "Enter the number of items to produce: ";
    cin >> num_items_to_produce;
    cout << "Enter the number of items to consume: ";
    cin >> num_items_to_consume;

    // Initialize the semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&empty_slots, 0, buffer_size);
    sem_init(&full, 0, 0);

    // Create the producer and consumer threads
    thread producer_thread(producer);
    thread consumer_thread(consumer);

    // Join the threads
    producer_thread.join();
    consumer_thread.join();

    // Destroy the semaphores
    sem_destroy(&mutex);
    sem_destroy(&empty_slots);
    sem_destroy(&full);

    return 0;
}
