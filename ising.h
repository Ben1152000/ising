#ifndef ISING_H
#define ISING_H

#include <iostream>
#include <array>
#include <math.h>
#include <vector>

using std::array;
using std::vector;

template <size_t N>
struct Grid {
    array<bool, N * N> values;

    Grid(bool value) {
        values.fill(value);
    }

    void reset(bool value) {
        values.fill(value);
    }

    bool get(int i, int j) {
        return values[i * N + j];
    }

    void set(int i, int j, bool x) {
        values[i * N + j] = x;
    }

    void display() {
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < N; ++j) {
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

    bool operator==(const Grid& other) {
        return values == other.values;
    }

    bool operator!=(const Grid& other) {
        return values != other.values;
    }
};

#endif
