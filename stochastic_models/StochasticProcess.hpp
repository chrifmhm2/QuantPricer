#pragma once
#include <vector>

class StochasticProcess {
public:
    virtual ~StochasticProcess() = default;
    virtual std::vector<double> simulatePath(double S0, double T, int N) const = 0;
    virtual double drift(double t, double S) const = 0;
    virtual double diffusion(double t, double S) const = 0;
};
