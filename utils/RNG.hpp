#pragma once
#include <random>

class RNG {
private:
    mutable std::mt19937 gen_;  // Générateur pseudo-aléatoire
    mutable std::normal_distribution<double> normal_;
    mutable std::uniform_real_distribution<double> uniform_;

public:
    explicit RNG(unsigned int seed = std::random_device{}());

    double randn() const;  // Génère un N(0,1)
    double randu() const;  // Génère un U(0,1)
};
