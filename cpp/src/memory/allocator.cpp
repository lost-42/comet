#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>

#include "doctest.h"

static constexpr std::size_t DEFAULT_POOL_SIZE = 64 * 1024;

/* A tiny bump (arena) allocator: allocations move a cursor forward, and
 * individual deallocations are no-ops - everything is released at once when
 * the pool is destroyed. */
class mem_pool {
public:
    mem_pool()
        : pool(new char[DEFAULT_POOL_SIZE]),
          curr(pool),
          end(pool + DEFAULT_POOL_SIZE) {}

    ~mem_pool() { delete[] pool; }

    mem_pool(const mem_pool&) = delete;
    mem_pool& operator=(const mem_pool&) = delete;

    void* alloc(std::size_t size) {
        if (curr + size > end) {
            return nullptr;
        }
        void* ret = curr;
        curr += size;
        return ret;
    }

    void del(void* /*p*/, std::size_t /*size*/) {
        /* bump allocator: no per-object free */
    }

private:
    char* pool;
    char* curr;
    char* end;
};

template <typename T>
struct my_allocator {
    using value_type = T;
    using size_type = std::size_t;

    my_allocator() : pool(std::make_shared<mem_pool>()) {}

    /* Required by allocator_traits; the pool is SHARED, not copied, otherwise
     * the temporary rebound allocator used for std::vector's internal
     * _Container_proxy node would free the memory it just handed out. */
    template <typename U>
    my_allocator(const my_allocator<U>& other) : pool(other.pool) {}

    value_type* allocate(size_type n) {
        return static_cast<value_type*>(pool->alloc(n * sizeof(value_type)));
    }

    void deallocate(value_type* /*p*/, size_type /*n*/) {}

    template <typename U>
    struct rebind {
        using other = my_allocator<U>;
    };

    std::shared_ptr<mem_pool> pool;
};

struct S {
    int val{0};
    char ch{0};
    bool flag{false};
};

TEST_CASE("allocator: std::vector on a custom bump allocator [cpp11][memory]") {
    std::vector<S, my_allocator<S>> v;

    std::size_t last = 0;
    for (int i = 0; i < 7; ++i) {
        v.push_back(S{i, static_cast<char>('a' + i), i % 2 == 0});
        if (last != v.capacity()) {
            last = v.capacity();
            std::cout << "capacity: " << last << '\n';
            for (const S& s : v) {
                std::cout << s.val << '\t' << s.ch << '\t' << s.flag << '\t'
                          << &s << '\n';
            }
        }
    }

    CHECK(v.size() == 7u);
    CHECK(v[0].val == 0);
    CHECK(v[6].ch == 'g');
}
