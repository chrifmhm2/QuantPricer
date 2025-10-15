#pragma once
#include "Pricer.hpp"
#include <vector>

class FiniteDifferencePricer : public Pricer {
private:
    int nSpace_;
    int nTime_;
    double riskFree_;
    double volatility_;

public:
    FiniteDifferencePricer(int nSpace = 200, int nTime = 200, double riskFree = 0.05, double volatility = 0.2);

    PricingResult price(
        const Option& option,
        const StochasticProcess& process,
        double spot
    ) const override;
};
