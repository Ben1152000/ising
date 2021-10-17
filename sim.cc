#include "ising.h"
#include "random.h"

#include <thread>
#include <chrono>

constexpr int N = 62;

void simulate(Grid<N>& grid, double temp, size_t steps) {
    Generator gen;
    for (size_t j = 0; j < steps; ++j)
        grid.update(gen.random(), temp);
}

int main(int argc, char* argv[]) {
    // Simulate free grid and fixed grid, varying temp.
    Generator gen;
    FreeGrid<N> g(0);
    g.display();

    std::this_thread::sleep_for (std::chrono::milliseconds(1000));

    for (int i = 0; i < 50; ++i) {
        simulate(g, 0.0, 1000);
        g.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(50));
    }

    for (int i = 0; i < 50; ++i) {
        simulate(g, 0.5, 1000);
        g.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(50));
    }

    for (int i = 0; i < 50; ++i) {
        simulate(g, 1.0, 1000);
        g.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(50));
    }

    for (int i = 0; i < 50; ++i) {
        simulate(g, 100.0, 1000);
        g.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(50));
    }

    std::this_thread::sleep_for (std::chrono::milliseconds(1000));

    FixedGrid<N> b(0, 1);
    b.display();

    std::this_thread::sleep_for (std::chrono::milliseconds(1000));

    for (int i = 0; i < 10; ++i) {
        simulate(b, 0.0, 1000);
        b.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(50));
    }
    
    for (int i = 0; i < 10; ++i) {
        simulate(b, 0.3, 1000);
        b.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(50));
    }

    for (int i = 0; i < 10; ++i) {
        simulate(b, 0.5, 1000);
        b.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(50));
    }

    for (int i = 0; i < 10; ++i) {
        simulate(b, 0.7, 1000);
        b.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(50));
    }
    
    for (int i = 0; i < 10; ++i) {
        simulate(b, 1.0, 1000);
        b.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(50));
    }

    for (int i = 0; i < 10; ++i) {
        simulate(b, 2.0, 1000);
        b.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(50));
    }

    for (int i = 0; i < 100; ++i) {
        simulate(b, 100.0, 1000);
        b.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(50));
    }

    std::this_thread::sleep_for (std::chrono::milliseconds(1000));
}
