#pragma once
#include "Pricer.hpp"
#include <cmath>

class AnalyticPricer : public Pricer {
private:
    double riskFree_;
    double volatility_;

public:
    AnalyticPricer(double riskFree, double volatility);

    PricingResult price(
        const Option& option,
        const StochasticProcess& process,
        double spot
    ) const override;

private:
    double normalCDF(double x) const;
};
