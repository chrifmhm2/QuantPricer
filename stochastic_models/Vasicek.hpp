#pragma once
#include "StochasticProcess.hpp"

class Vasicek : public StochasticProcess {
private:
    double kappa_;  // vitesse de reversion
    double theta_;  // niveau long-terme
    double sigma_;  // volatilité

public:
    Vasicek(double kappa, double theta, double sigma);
    std::vector<double> simulatePath(double r0, double T, int N) const override;
    double drift(double t, double r) const override;
    double diffusion(double t, double r) const override;
};
