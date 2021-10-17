#include <iostream>
#include <array>
#include <math.h>
#include <random>
#include <thread>
#include <chrono>

constexpr int N = 48;

using std::array;

std::random_device device;
std::mt19937 eng(device());
std::uniform_real_distribution<> dist(0, 1);

double seed() {
    return dist(eng);
}

struct Grid {
    array<bool, N * N> values;

    Grid(bool value) {
        values.fill(value);
    }

    bool get(int i, int j) {
        return values[i * N + j];
    }

    void set(int i, int j, bool x) {
        values[i * N + j] = x;
    }

    void display() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cout << (values[i * N + j]? "█": " ");
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void update(double seed, double temp) {
        seed *= N;
        int i = int(seed);
        seed -= i;
        seed *= N;
        int j = int(seed);
        seed -= j;
        int s = -4 + 2 * (get((i + 1) % N, j)
              + get((i + N - 1) % N, j)
              + get(i, (j + 1) % N)
              + get(i, (j + N - 1) % N));
        double p = (1 + tanh(temp * s)) / 2.0;
        // std::cout << s << ' ' << p;
        set(i, j, static_cast<bool>(seed < p));
    }
};


int main() {
    
    Grid a(0);
    Grid z(1);

    a.display();
    z.display();

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j)
            z.update(seed(), 0);
        z.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(50));
    }

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j)
            z.update(seed(), 1);
        z.display();
        std::this_thread::sleep_for (std::chrono::milliseconds(50));
    }
    
}