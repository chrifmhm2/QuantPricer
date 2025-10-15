#pragma once
#include "Hedger.hpp"
#include <vector>
#include <cmath>

class DeltaHedgingSimulator : public Hedger {
private:
    unsigned int seed_;

public:
    explicit DeltaHedgingSimulator(unsigned int seed = 42);

    double simulateHedging(
        const Option& option,
        const StochasticProcess& process,
        const Pricer& pricer,
        double spot,
        double riskFree,
        double volatility,
        double maturity,
        int nSteps
    ) const override;
};
