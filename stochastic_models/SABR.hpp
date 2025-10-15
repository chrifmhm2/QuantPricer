#pragma once
#include "StochasticProcess.hpp"

class SABR : public StochasticProcess {
private:
    double alpha_; // vol initiale
    double beta_;  // elasticity
    double rho_;   // corrélation
    double nu_;    // volatilité de la volatilité

public:
    SABR(double alpha, double beta, double rho, double nu);
    std::vector<double> simulatePath(double F0, double T, int N) const override;
    double drift(double t, double F) const override;
    double diffusion(double t, double F) const override;
};