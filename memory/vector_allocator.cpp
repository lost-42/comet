#include <iostream>
#include <memory>
#include <vector>

struct Allocator {};

int main() {
    std::allocator<int> a;
    int* p = a.allocate(1);

    std::allocator_traits<std::allocator<int>>::construct(a, p, 10);
    std::cout << *p << std::endl;

    std::allocator_traits<std::allocator<int>>::destroy(a, p);
    a.deallocate(p, 1);
}