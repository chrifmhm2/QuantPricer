#pragma once
#include "StochasticProcess.hpp"

class HullWhite : public StochasticProcess {
private:
    double a_;
    double sigma_;
    double theta_; // optional constant drift term

public:
    HullWhite(double a, double sigma, double theta = 0.0);
    std::vector<double> simulatePath(double r0, double T, int N) const override;
    double drift(double t, double r) const override;
    double diffusion(double t, double r) const override;
};
