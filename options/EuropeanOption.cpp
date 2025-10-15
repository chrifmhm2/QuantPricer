#include "EuropeanOption.hpp"
#include <algorithm>

EuropeanOption::EuropeanOption(double strike, double maturity, OptionType type)
    : Option(strike, maturity, type) {}

double EuropeanOption::payoff(double spot) const {
    if (type_ == OptionType::Call)
        return std::max(spot - strike_, 0.0);
    else
        return std::max(strike_ - spot, 0.0);
}

std::string EuropeanOption::name() const {
    return "EuropeanOption";
}
