#pragma once
#include <memory>
#include "../options/Option.hpp"
#include "../stochastic_models/StochasticProcess.hpp"

struct PricingResult {
    double price;
    double delta;
    double gamma;
    double vega;
    double rho;
};

class Pricer {
public:
    virtual ~Pricer() = default;

    virtual PricingResult price(
        const Option& option,
        const StochasticProcess& process,
        double spot
    ) const = 0;
};
