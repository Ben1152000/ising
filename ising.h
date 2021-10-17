#ifndef ISING_H
#define ISING_H

#include <iostream>
#include <array>
#include <math.h>
#include <vector>

constexpr int N = 4;

using std::array;
using std::vector;

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

    void display();

    void update(double seed, double temp);

    bool operator==(const Grid& other) {
        return values == other.values;
    }

    bool operator!=(const Grid& other) {
        return values != other.values;
    }
};

#endif
