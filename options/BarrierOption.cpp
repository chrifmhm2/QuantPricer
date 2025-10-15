#include "BarrierOption.hpp"
#include <algorithm>

BarrierOption::BarrierOption(double strike, double maturity, OptionType type, double barrier, BarrierType btype)
    : Option(strike, maturity, type), barrier_(barrier), barrierType_(btype) {}

double BarrierOption::payoff(const std::vector<double>& path) const {
    if (path.empty()) return 0.0;

    double S_T = path.back();
    double payoff_val = 0.0;

    if (type_ == OptionType::Call)
        payoff_val = std::max(S_T - strike_, 0.0);
    else
        payoff_val = std::max(strike_ - S_T, 0.0);

    bool hit = false;
    for (double s : path) {
        if ((barrierType_ == BarrierType::UpAndOut || barrierType_ == BarrierType::UpAndIn) && s >= barrier_)
            hit = true;
        if ((barrierType_ == BarrierType::DownAndOut || barrierType_ == BarrierType::DownAndIn) && s <= barrier_)
            hit = true;
    }

    // Logic depending on barrier type
    switch (barrierType_) {
        case BarrierType::UpAndOut:
        case BarrierType::DownAndOut:
            return hit ? 0.0 : payoff_val;
        case BarrierType::UpAndIn:
        case BarrierType::DownAndIn:
            return hit ? payoff_val : 0.0;
        default:
            return payoff_val;
    }
}

std::string BarrierOption::name() const {
    return "BarrierOption";
}
