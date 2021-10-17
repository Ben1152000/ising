#include "ising.h"
#include "random.h"

void coupling(double temp) {
    vector<double> r;
    Generator gen;

    Grid a(0);
    Grid z(0);

    do {
        r.push_back(gen.random());
        a.reset(0);
        z.reset(1);
        for (auto it = r.rbegin(); it != r.rend(); ++it) {
            a.update(*it, temp);
            z.update(*it, temp);
        }
    } while (a != z);

    a.display();
}

int main() {
    coupling(0.3);
}
