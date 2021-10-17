#include "ising.h"

void Grid::display() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << (values[i * N + j]? "█": " ");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Grid::update(double seed, double temp) {
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