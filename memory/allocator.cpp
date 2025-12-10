#include <iostream>
#include <limits>
#include <memory>
#include <vector>

static constexpr size_t DEFAULT_POOL_SIZE = 64 * 1024;

class mem_pool {
public:
    mem_pool() {
        pool = new char[DEFAULT_POOL_SIZE];
        curr = pool;
        end = pool + DEFAULT_POOL_SIZE;
    }

    ~mem_pool() { delete[] pool; }

    void* alloc(size_t size) {
        if (curr + size > end) {
            return nullptr;
        }
        void* ret = curr;
        curr += size;
        return ret;
    }

    void del(void* p, size_t size) {
        // do nothing, all memory will be delete when mem_pool is destroyed
    }

private:
    char* pool{nullptr};
    char* curr{nullptr};
    char* end{nullptr};
};

template <typename T>
struct my_allocator {
    using value_type = T;
    using size_type = std::size_t;

    my_allocator() = default;

    value_type* allocate(size_type n) {
        return static_cast<value_type*>(pool.alloc(n * sizeof(value_type)));
    }

    void deallocate(value_type* p, size_type n) {
        pool.del(p, n * sizeof(value_type));
    }

    template <typename U>
    struct rebind {
        using other = my_allocator<U>;
    };

    mem_pool pool{};
};

struct S {
    int val{0};
    char ch{0};
    bool flag{false};
};

int main() {
    int c = 0;
    std::vector<S, my_allocator<S>> v{};
    for (int i = 0; i < 7; ++i) {
        v.push_back(S{i, (char)('a' + i), i % 2 == 0});
        if (c == v.capacity())
            continue;

        c = v.capacity();

        std::cout << "capacity: " << c << '\n';
        for (const S& s : v) {
            std::cout << s.val << '\t' << s.ch << '\t' << s.flag << '\t' << &s
                      << '\n';
        }
    }
}