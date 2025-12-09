#include <iostream>
#include <limits>
#include <memory>
#include <vector>

template <typename T>
struct MyAllocator {
    using value_type = T;
    using size_type = std::size_t;

    static value_type pool[512];

    MyAllocator() = default;

    value_type* allocate(size_type n) {
        return static_cast<value_type*>(::operator new(n * sizeof(value_type)));
    }

    void deallocate(value_type* p, size_type n) {
        ::operator delete(p, n * sizeof(value_type));
    }

    template <typename U>
    struct rebind {
        using other = MyAllocator<U>;
    };
};

struct S {
    S(int v) : val(v) {
    }
    int val{0};
};

int main() {
    std::vector<S, MyAllocator<S>> v{MyAllocator<S>{}};
    for (int i = 0; i < 7; ++i) {
        v.push_back(S{i});
    }

    for (const S& s : v) {
        std::cout << s.val << '\t' << &s << '\n';
    }
}