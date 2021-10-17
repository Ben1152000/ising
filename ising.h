#ifndef ISING_H
#define ISING_H

#include <iostream>
#include <array>
#include <math.h>
#include <vector>

using std::array;
using std::vector;

template <size_t N>
class Grid {
  protected:
    array<bool, N * N> values;

  public:
    Grid(bool value) {
        values.fill(value);
    }

    Grid(bool value, bool boundary) {
        values.fill(value);
        for (size_t i = 0; i < N; ++i) {
            set(0, i, boundary);
            set(i, 0, boundary);
            set(N - 1, i, boundary);
            set(i, N - 1, boundary);
        }
    }

    void reset(bool value) {
        values.fill(value);
    }

    void reset(bool value, bool boundary) {
        values.fill(value);
        for (size_t i = 0; i < N; ++i) {
            set(0, i, boundary);
            set(i, 0, boundary);
            set(N - 1, i, boundary);
            set(i, N - 1, boundary);
        }
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

    bool operator==(const Grid& other) {
        return values == other.values;
    }

    bool operator!=(const Grid& other) {
        return values != other.values;
    }

    virtual void update(double seed, double temp) = 0;
};

template <size_t N>
class FreeGrid : public Grid<N> {
    // Grid with free (toroidal) boundary condition
    using Grid<N>::Grid, Grid<N>::set, Grid<N>::get;

  public:
    void update(double seed, double temp) override {
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
        set(i, j, static_cast<bool>(seed < p));
    }
};

template <size_t N>
class FixedGrid : public Grid<N> {
    // Grid with fixed boundary condition
    using Grid<N>::Grid, Grid<N>::set, Grid<N>::get;

  public:
    void update(double seed, double temp) override {
        seed *= N;
        size_t i = int(seed);
        seed -= i;
        seed *= N;
        size_t j = int(seed);
        seed -= j;
        int s = -4 + 2 * (get((i + 1) % N, j)
                + get((i + N - 1) % N, j)
                + get(i, (j + 1) % N)
                + get(i, (j + N - 1) % N));
        double p = (1 + tanh(temp * s)) / 2.0;
        if (i > 0 && j > 0 && i + 1 < N && j + 1 < N)
            set(i, j, static_cast<bool>(seed < p));
    }
};

#endif
