#pragma once
#include "StochasticProcess.hpp"

class MertonJumpDiffusion : public StochasticProcess {
private:
    double mu_;
    double sigma_;
    double lambda_;  // jump intensity
    double mu_j_;    // mean of jump size
    double sigma_j_; // stddev of jump size

public:
    MertonJumpDiffusion(double mu, double sigma, double lambda, double mu_j, double sigma_j);
    std::vector<double> simulatePath(double S0, double T, int N) const override;
    double drift(double t, double S) const override;
    double diffusion(double t, double S) const override;
};
