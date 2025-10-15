#pragma once
#include "Option.hpp"
#include <algorithm>

class EuropeanOption : public Option {
public:
    EuropeanOption(double strike, double maturity, OptionType type);
    double payoff(double spot) const override;
    std::string name() const override;
};
