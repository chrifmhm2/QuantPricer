#pragma once
#include "Option.hpp"

class AmericanOption : public Option {
public:
    AmericanOption(double strike, double maturity, OptionType type);
    double payoff(double spot) const override;
    std::string name() const override;
};
