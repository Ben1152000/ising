#include "ising.h"
#include "random.h"

#include <algorithm>
#include <vector>

constexpr size_t N = 10;

using std::vector;

size_t free_coupling(double temp) {
    vector<double> r;
    Generator gen;

    FreeGrid<N> a(0);
    FreeGrid<N> z(0);

    do {
        size_t n = std::max(r.size(), std::size_t(1));
        for (size_t i = 0; i < n; ++i)
            r.push_back(gen.random());
        // std::cout << r.size() << std::endl;
        a.reset(0);
        z.reset(1);
        for (auto it = r.rbegin(); it != r.rend(); ++it) {
            a.update(*it, temp);
            z.update(*it, temp);
        }
    } while (a != z);

    size_t u = r.size();
    size_t l = u / 2;

    do {
        size_t m = (l + u) / 2;
        a.reset(0);
        z.reset(1);
        for (size_t i = m; i --> 0;) {
            a.update(r[i], temp);
            z.update(r[i], temp);
        }
        if (a == z)
            u = m;
        else
            l = m;
        // std::cout << l << ' ' << u << std::endl;
    } while (u > l + 1);

    // a.display();
    // z.display();

    return u;
}

size_t fixed_coupling(double temp) {
    vector<double> r;
    Generator gen;

    FixedGrid<N> a(0, 1);
    FixedGrid<N> z(1, 1);

    do {
        size_t n = std::max(r.size(), std::size_t(1));
        for (size_t i = 0; i < n; ++i)
            r.push_back(gen.random());
        // std::cout << r.size() << std::endl;
        a.reset(0, 1);
        z.reset(1, 1);
        for (auto it = r.rbegin(); it != r.rend(); ++it) {
            a.update(*it, temp);
            z.update(*it, temp);
        }
    } while (a != z);

    size_t u = r.size();
    size_t l = u / 2;

    do {
        size_t m = (l + u) / 2;
        a.reset(0, 1);
        z.reset(1, 1);
        for (size_t i = m; i --> 0;) {
            a.update(r[i], temp);
            z.update(r[i], temp);
        }
        if (a == z)
            u = m;
        else
            l = m;
        // std::cout << l << ' ' << u << std::endl;
    } while (u > l + 1);

    return u;
}

int main(int argc, char* argv[]) {

    size_t trials;
    size_t samples = 10;

    for (double beta = 0.001; beta < 10000000.0; beta *= 1.05) {
        double sample = 0;
        for (size_t i = 0; i < samples; ++i) {
            sample += fixed_coupling(beta);
        }
        trials = samples * 10000000 / sample;
        double average = sample;
        for (size_t i = 0; i < trials; ++i) {
            average += fixed_coupling(beta);
        }
        average /= trials + samples;
        std::cout << beta << ", " << average << std::endl;
    }

}
