#include <iostream>
#include <pthread.h>

#define BUFFER_SIZE 10
int itemCount = 0;
int buffer[BUFFER_SIZE];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buf_not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t buf_not_empty = PTHREAD_COND_INITIALIZER;

int produceItem();
void putItemIntoBuffer(int);
int removeItemFromBuffer();
void consumeItem(int);

void* producer(void* arg){
  while(true){
    item = produceItem();

    if(itemCount == BUFFER_SIZE){
      pthread_cond_wait(&buf_not_full, &mutex);
    }

    putItemIntoBuffer(item);
    itemCount = itemCount + 1;

    if(itemCount == 1){
      pthread_cond_signal(&buf_not_empty);
    }

  }
}

void* consumer(void* arg){
  while (true){

    if(itemCount == 0){
      pthread_cond_wait(&buf_not_empty, &mutex);
    }

    item = removeItemFromBuffer();
    itemCount = itemCount - 1;
    if(itemCount == BUFFER_SIZE - 1){
      pthread_cond_signal(&buf_not_full);
    }
    consumeItem(item);
  }
}
