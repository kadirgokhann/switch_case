#include <iostream>
#include <chrono>

// Function similar to StringCreation
void StringCreation(int iterations) {
    int index = 0;
    int arr[] = {0, 100, 2240};
    for (int i = 0; i < iterations; i++) {
        int argc = arr[index % 3];
        index++;
        int res;
        switch (argc) 
        {
            case 0:     [[unlikely]] res = -3; break;
            case 100:   res = 457; break;
            case 2240:  [[likely]] res = 780; break;
            default:    res = 111;
        }
        asm volatile("" : : "r"(res) : "memory"); // prevent optimization
    }
}

// Function similar to StringCopy
void StringCopy(int iterations) {
    int index = 0;
    int arr[] = {0, 100, 2240};
    for (int i = 0; i < iterations; i++) {
        int argc = arr[index % 3];
        index++;
        int res;
        if (argc == 0) [[unlikely]]
            res = -3;  
        else if (argc == 100)
            res = 456;
        else if (argc == 2240) [[likely]]
            res = 780;
        else
            res = 111;
        asm volatile("" : : "r"(res) : "memory"); // prevent optimization
    }
}

int main() {
    const int iterations = 100000000; // adjust to get measurable time

    // Benchmark StringCreation
    auto start1 = std::chrono::high_resolution_clock::now();
    StringCreation(iterations);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end1 - start1;
    std::cout << "StringCreation took " << elapsed1.count() << " seconds\n";

    // Benchmark StringCopy
    auto start2 = std::chrono::high_resolution_clock::now();
    StringCopy(iterations);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - start2;
    std::cout << "StringCopy took " << elapsed2.count() << " seconds\n";

    return 0;
}
