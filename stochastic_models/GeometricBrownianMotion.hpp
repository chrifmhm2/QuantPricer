#pragma once
#include "StochasticProcess.hpp"
#include <vector>
class GeometricBrownianMotion : public StochasticProcess {
private:
    double mu_;
    double sigma_;

public:
    GeometricBrownianMotion(double mu, double sigma);
    std::vector<double> simulatePath(double S0, double T, int N) const override;
    double drift(double t, double S) const override;
    double diffusion(double t, double S) const override;
};
