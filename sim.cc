#include "ising.h"
#include "random.h"

#include <thread>
#include <chrono>

int main() {
    // Simulate infinite temp for 1000 cycles then reduce to 1.
    Grid a(0);
    Grid z(1);
    Generator gen;

    a.display();
    z.display();

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j)
            z.update(gen.random(), 0);
        z.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(50));
    }

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j)
            z.update(gen.random(), 1);
        z.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(50));
    }
}
