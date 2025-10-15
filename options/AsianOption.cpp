#include "AsianOption.hpp"
#include <numeric>
#include <algorithm>

AsianOption::AsianOption(double strike, double maturity, OptionType type)
    : Option(strike, maturity, type) {}

double AsianOption::payoff(const std::vector<double>& path) const {
    if (path.empty()) return 0.0;

    double avg = std::accumulate(path.begin(), path.end(), 0.0) / path.size();
    if (type_ == OptionType::Call)
        return std::max(avg - strike_, 0.0);
    else
        return std::max(strike_ - avg, 0.0);
}

std::string AsianOption::name() const {
    return "AsianOption";
}
