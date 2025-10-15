#pragma once
#include "StochasticProcess.hpp"
#include <vector>

class OrnsteinUhlenbeck : public StochasticProcess {
private:
    double kappa_;
    double theta_;
    double sigma_;

public:
    OrnsteinUhlenbeck(double kappa, double theta, double sigma);

    std::vector<double> simulatePath(double X0, double T, int N) const override;

    double drift(double t, double X) const override;
    double diffusion(double t, double X) const override;
};
