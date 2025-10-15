#pragma once
#include "../options/Option.hpp"
#include "../pricing/Pricer.hpp"
#include "../stochastic_models/StochasticProcess.hpp"

class Hedger {
public:
    virtual ~Hedger() = default;

    virtual double simulateHedging(
        const Option& option,
        const StochasticProcess& process,
        const Pricer& pricer,
        double spot,
        double riskFree,
        double volatility,
        double maturity,
        int nSteps
    ) const = 0;
};
