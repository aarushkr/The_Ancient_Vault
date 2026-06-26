#ifndef RANDOM_MT_H
#define RANDOM_MT_H

#include <iostream>
#include <chrono>
#include <random>

namespace Random {
    inline std::mt19937& get_rng() {
        static std::mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
        return rng;
    }

    inline int next_int() {
        return get_rng()();
    }

    inline int next_range(int low, int high) {
        std::uniform_int_distribution<int> dist(low, high);
        return dist(get_rng());
    }

    inline long long next_long_range(long long low, long long high) {
        static std::mt19937_64 rng64(std::chrono::high_resolution_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<long long> dist(low, high);
        return dist(rng64);
    }

    inline bool next_bool(double probability) {
        std::bernoulli_distribution dist(probability);
        return dist(get_rng());
    }
}
#endif