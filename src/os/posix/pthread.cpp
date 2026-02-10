#include <pthread.h>

#include <iostream>

void* foo(void* p) {
    int* pi = (int*)p;
    for (int i = 0; i < 1000000; ++i) {
        ++(*pi);
    }
    return nullptr;
}

void test_race_condition() {
    std::cout << "[test_race_condition]" << std::endl;

    pthread_t thread1, thread2;
    int i = 0;
    pthread_create(&thread1, NULL, foo, &i);
    pthread_create(&thread2, NULL, foo, &i);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    std::cout << i << std::endl;
}

static pthread_mutex_t lock;
void* foo_no_rc(void* p) {
    int* pi = (int*)p;
    for (int i = 0; i < 1000000; ++i) {
        pthread_mutex_lock(&lock);
        ++(*pi);
        pthread_mutex_unlock(&lock);
    }
    return nullptr;
}

void test_mutex() {
    std::cout << "[test_mutex]" << std::endl;

    pthread_mutex_init(&lock, NULL);

    pthread_t thread1, thread2;
    int i = 0;
    pthread_create(&thread1, NULL, foo_no_rc, &i);
    pthread_create(&thread2, NULL, foo_no_rc, &i);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    std::cout << i << std::endl;
}

static pthread_mutex_t cond_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
static int ready = 0;

void* foo_cond(void* p) {
    pthread_mutex_lock(&cond_lock);
    while (ready == 0) {
        std::cout << "foo_cond" << std::endl;
        pthread_cond_wait(&empty, &cond_lock);
    }
    pthread_mutex_unlock(&cond_lock);
    return nullptr;
}

void* bar_cond(void* p) {
    pthread_mutex_lock(&cond_lock);
    for (int i = 0; i < 5'000'000; ++i) {
        if (i % 1'000'000 == 0)
            std::cout << "bar_cond" << std::endl;
    }
    ready = 1;
    pthread_cond_signal(&empty);
    pthread_mutex_unlock(&cond_lock);
    return nullptr;
}

void test_condition_variable() {
    std::cout << "[test_condition_variable]" << std::endl;
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, foo_cond, NULL);
    pthread_create(&thread2, NULL, bar_cond, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}

void run_pthread() {
    test_race_condition();
    test_mutex();
    test_condition_variable();
}