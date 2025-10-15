#pragma once
#include "Option.hpp"
#include <vector>
#include <numeric>
#include <algorithm>

class AsianOption : public Option {
public:
    AsianOption(double strike, double maturity, OptionType type);
    double payoff(const std::vector<double>& path) const;
    std::string name() const override;
};
