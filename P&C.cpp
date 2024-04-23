
#include <iostream>
#include <queue>
#include <thread>
#include <semaphore.h>

std::queue<int> buffer;
sem_t emptySlots;
sem_t fullSlots;

void producer() {
   for (int i = 1; i <= 5; ++i) {
      sem_wait(&emptySlots);
      buffer.push(i);
      std::cout << "Produced: " << i << std::endl;
      sem_post(&fullSlots);
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
   }
}

void consumer() {
   while (true) {
      sem_wait(&fullSlots);
      int data = buffer.front();
      buffer.pop();
      std::cout << "Consumed: " << data << std::endl;
      sem_post(&emptySlots);
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
   }
}

int main() {
   sem_init(&emptySlots, 0, 5);  
   sem_init(&fullSlots, 0, 0);   

   std::thread producerThread(producer);
   std::thread consumerThread(consumer);

   producerThread.join();
   consumerThread.join();

   sem_destroy(&emptySlots);
   sem_destroy(&fullSlots);

   return 0;
}