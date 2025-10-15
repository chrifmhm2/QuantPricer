#include "AmericanOption.hpp"
#include <algorithm>

AmericanOption::AmericanOption(double strike, double maturity, OptionType type)
    : Option(strike, maturity, type) {}

double AmericanOption::payoff(double spot) const {
    if (type_ == OptionType::Call)
        return std::max(spot - strike_, 0.0);
    else
        return std::max(strike_ - spot, 0.0);
}

std::string AmericanOption::name() const {
    return "AmericanOption";
}
