#pragma once
#include "StochasticProcess.hpp"

class CIR : public StochasticProcess {
private:
    double kappa_;
    double theta_;
    double sigma_;

public:
    CIR(double kappa, double theta, double sigma);
    std::vector<double> simulatePath(double r0, double T, int N) const override;
    std::vector<double> simulatePathEuler(double r0, double T, int N) const;
    double drift(double t, double r) const override;
    double diffusion(double t, double r) const override;
};
