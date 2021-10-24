/* Write an aligned malloc and free function that supports allocating memory such that the memory address
returned id divisible by a specific power of two */
#include <bitset>
#include <cstddef>
#include <cstdlib>
#include <iostream>

void* aligned_malloc(size_t bytes, size_t alignment)
{
    size_t offset = alignment - 1 + sizeof(void*);
    std::cout << "Offset: " << offset << std::endl;
    void* p1 = (void*)malloc(bytes + offset);
    std::cout << "p1 = " << p1 << std::endl;
    if (p1 == nullptr)
        return nullptr;
    std::cout << "Initial pointer: " << p1 << " " << reinterpret_cast<uint64_t>(p1) % alignment << std::endl;
    void* p2 = (void*)(((size_t)p1 + offset) & ~(alignment - 1));
    ((void**)p2)[-1] = p1; // previous piece of memory??
    std::bitset<64> y(alignment - 1);
    std::cout << "Mask ~(alignment - 1) = " << ~y << std::endl;
    std::cout << "Shifted pointer: " << p2 << " " << reinterpret_cast<uint64_t>(p2) % alignment << std::endl;
    return p2;
}
void aligned_free(void* p2)
{
    void* p1 = ((void**)p2)[-1];
    free(p1);
}

int main()
{
    void* m = aligned_malloc(240, 512);
    aligned_free(m);
    aligned_free(m);

    return 0;
}