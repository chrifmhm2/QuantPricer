#pragma once
#include "StochasticProcess.hpp"
#include <utility> // for std::pair

class Heston : public StochasticProcess {
private:
    double mu_;
    double kappa_;
    double theta_;
    double sigma_v_;
    double rho_; // correlation entre W_s et W_v

public:
    Heston(double mu, double kappa, double theta, double sigma_v, double rho);
    std::vector<double> simulatePath(double S0, double T, int N) const override;
    double drift(double t, double S) const override;
    double diffusion(double t, double S) const override;
};
