#include "OrnsteinUhlenbeck.hpp"
#include "../utils/RNG.hpp"
#include <cmath>

OrnsteinUhlenbeck::OrnsteinUhlenbeck(double kappa, double theta, double sigma)
    : kappa_(kappa), theta_(theta), sigma_(sigma) {}

std::vector<double> OrnsteinUhlenbeck::simulatePath(double X0, double T, int N) const {
    RNG rng;
    std::vector<double> X(N + 1);
    X[0] = X0;
    double dt = T / static_cast<double>(N);

    for (int i = 0; i < N; ++i) {
        double Z = rng.randn();
        double expTerm = std::exp(-kappa_ * dt);
        double mean = theta_ + (X[i] - theta_) * expTerm;
        double variance = (sigma_ * sigma_) * (1 - std::exp(-2 * kappa_ * dt)) / (2 * kappa_);
        X[i + 1] = mean + std::sqrt(variance) * Z;
    }

    return X;
}

double OrnsteinUhlenbeck::drift(double t, double X) const {
    return kappa_ * (theta_ - X);
}

double OrnsteinUhlenbeck::diffusion(double t, double X) const {
    return sigma_;
}
