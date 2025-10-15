#pragma once
#include "Pricer.hpp"
#include <random>
#include <vector>

class MonteCarloPricer : public Pricer {
private:
    int nPaths_;     // nombre de simulations Monte Carlo
    int nSteps_;     // nombre de pas par trajectoire
    double riskFree_; // taux sans risque
    unsigned int seed_;

public:
    MonteCarloPricer(int nPaths = 10000, int nSteps = 252, double riskFree = 0.0, unsigned int seed = 42);

    PricingResult price(
        const Option& option,
        const StochasticProcess& process,
        double spot
    ) const override;
};
