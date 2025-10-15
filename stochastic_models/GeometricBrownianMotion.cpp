#include "GeometricBrownianMotion.hpp"
#include <random>
#include <cmath>
#include "../utils/RNG.hpp"
GeometricBrownianMotion::GeometricBrownianMotion(double mu, double sigma)
    : mu_(mu), sigma_(sigma){}


std::vector<double> GeometricBrownianMotion::simulatePath(double S0, double T, int N) const {
    RNG rng;  // générateur local
    std::vector<double> S(N + 1);
    S[0] = S0;

    double dt = T / static_cast<double>(N);
    for (int k = 0; k < N; ++k) {
        double Z = rng.randn();  
        double drift = (mu_ - 0.5 * sigma_ * sigma_) * dt;
        double diffusion = sigma_ * std::sqrt(dt) * Z;
        S[k + 1] = S[k] * std::exp(drift + diffusion);
    }

    return S;
}


double GeometricBrownianMotion::drift(double t, double S) const
{
    return mu_ * S;
}
double GeometricBrownianMotion::diffusion(double t, double S) const
{
    return sigma_ * S;
}