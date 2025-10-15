#include "CIR.hpp"
#include "../utils/RNG.hpp"
#include <Eigen/Dense>
#include <random>
#include <cmath>
#include <algorithm>
CIR::CIR(double kappa, double theta, double sigma)
    : kappa_(kappa), theta_(theta), sigma_(sigma) {}

// ==================================================
// ====== 1. Simulation par schéma d’Euler =========
// ==================================================
std::vector<double> CIR::simulatePathEuler(double r0, double T, int N) const
{
    RNG rng;
    std::vector<double> r(N + 1);
    r[0] = r0;

    double dt = T / static_cast<double>(N);

    for (int i = 0; i < N; ++i) {
        double Z = rng.randn();

        // Full truncation pour éviter les valeurs négatives
        double ri = std::max(r[i], 0.0);

        r[i + 1] = r[i] + kappa_ * (theta_ - ri) * dt
                 + sigma_ * std::sqrt(ri * dt) * Z;

        r[i + 1] = std::max(r[i + 1], 0.0);
    }

    return r;
}

// ==================================================
// ====== 2. Simulation exacte (loi χ² non centrée) ==
// ==================================================
/*std::vector<double> CIR::simulatePath(double r0, double T, int N) const
{
    RNG rng;
    std::vector<double> r(N + 1);
    r[0] = r0;

    double dt = T / static_cast<double>(N);

    for (int i = 0; i < N; ++i) {
        // Pré-calculs
        double c = (sigma_ * sigma_ * (1.0 - std::exp(-kappa_ * dt))) / (4.0 * kappa_);
        double lambda = (4.0 * kappa_ * std::exp(-kappa_ * dt) * r[i]) /
                        (sigma_ * sigma_ * (1.0 - std::exp(-kappa_ * dt)));
        double nu = (4.0 * kappa_ * theta_) / (sigma_ * sigma_);

        // Approximation de la loi χ² non centrée :
        // On utilise ici une approximation basée sur une loi normale pour éviter Boost
        // (λ grand → approx par N(μ, σ²))
        double mean = nu + lambda;
        double variance = 2.0 * (nu + 2.0 * lambda);
        double chi2_approx = mean + std::sqrt(variance) * rng.randn();

        chi2_approx = std::max(chi2_approx, 0.0); // éviter valeurs négatives

        r[i + 1] = c * chi2_approx;
    }

    return r;
}*/



std::vector<double> CIR::simulatePath(double r0, double T, int N) const
{
    RNG rng;
    std::vector<double> r(N + 1);
    r[0] = r0;

    double dt = T / static_cast<double>(N);

    // Générateurs Eigen
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < N; ++i) {
        double c = (sigma_ * sigma_ * (1.0 - std::exp(-kappa_ * dt))) / (4.0 * kappa_);
        double lambda = (4.0 * kappa_ * std::exp(-kappa_ * dt) * r[i]) /
                        (sigma_ * sigma_ * (1.0 - std::exp(-kappa_ * dt)));
        double nu = (4.0 * kappa_ * theta_) / (sigma_ * sigma_);

        // Étape 1 : Poisson(K | λ/2)
        std::poisson_distribution<int> pois(lambda / 2.0);
        int K = pois(gen);

        // Étape 2 : χ²_(ν + 2K)
        std::gamma_distribution<double> gammaDist((nu / 2.0) + K, 2.0);
        double chi2 = gammaDist(gen);

        // Étape 3 : Calcul du taux
        r[i + 1] = c * chi2;
    }

    return r;
}

// ==================================================
// ====== 3. Fonctions drift et diffusion ===========
// ==================================================
double CIR::drift(double t, double r) const
{
    return kappa_ * (theta_ - r);
}

double CIR::diffusion(double t, double r) const
{
    return sigma_ * std::sqrt(std::max(r, 0.0));
}
