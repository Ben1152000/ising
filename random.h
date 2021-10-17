#ifndef RANDOM_H
#define RANDOM_H

#include <random>

class Generator {

    std::random_device device;
    std::mt19937 eng;
    std::uniform_real_distribution<> dist;

  public:
    Generator() : device(), eng(device()), dist(0, 1) {}

    double random() {
        return dist(eng);
    }
};

#endif
