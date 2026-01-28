/**
 * @file prod_cons.cpp
 * @author Ollie Li (rui96uk@gmail.com)
 * @brief producer and consumer problem
 * @version 0.1
 * @date 2026-01-05
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <pthread.h>

#include <iostream>

static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t empty = PTHREAD_COND_INITIALIZER,
                      fill = PTHREAD_COND_INITIALIZER;

static constexpr int LOOP = 100;

static constexpr int BUF_SIZE = 20;
static int BUF[BUF_SIZE] = {0};
int curr = 0;

void put(int d) { BUF[curr++] = d; }

int get() { return BUF[curr--]; }

void* producer(void* p) {
    for (int i = 1; i < LOOP; ++i) {
        pthread_mutex_lock(&lock);
        while (curr == BUF_SIZE)
            pthread_cond_wait(&empty, &lock);
        put(i);
        pthread_cond_signal(&fill);
        pthread_mutex_unlock(&lock);
    }

    return nullptr;
}

void* consumer(void* p) {
    for (int i = 1; i < LOOP; ++i) {
        pthread_mutex_lock(&lock);
        while (curr <= 0)
            pthread_cond_wait(&fill, &lock);
        std::cout << "consumer(" << pthread_self() << "): " << get()
                  << std::endl;
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&lock);
    }

    return nullptr;
}

void run_prod_cons() {
    pthread_t thread1, thread2, thread3, thread4;
    pthread_create(&thread1, NULL, producer, NULL);
    pthread_create(&thread2, NULL, consumer, NULL);
    pthread_create(&thread3, NULL, consumer, NULL);
    pthread_create(&thread4, NULL, consumer, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    std::cout << "finished" << std::endl;
}