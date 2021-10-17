#include "ising.h"
#include "random.h"

#include <thread>
#include <chrono>

constexpr int N = 50;

int main(int argc, char* argv[]) {
    // Simulate infinite temp for 1000 cycles then reduce to 1.
    Grid<N> a(0);
    Grid<N> z(1);
    Generator gen;

    a.display();
    z.display();

    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 500; ++j)
            z.update(gen.random(), 0);
        z.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(60));
    }

    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 500; ++j)
            z.update(gen.random(), 0.5);
        z.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(60));
    }

    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 500; ++j)
            z.update(gen.random(), 1);
        z.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(60));
    }

    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 500; ++j)
            z.update(gen.random(), 100);
        z.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(60));
    }
}
