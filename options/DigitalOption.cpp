#include "DigitalOption.hpp"

DigitalOption::DigitalOption(double strike, double maturity, OptionType type, double payout)
    : Option(strike, maturity, type), payout_(payout) {}

double DigitalOption::payoff(double spot) const {
    if (type_ == OptionType::Call)
        return (spot > strike_) ? payout_ : 0.0;
    else
        return (spot < strike_) ? payout_ : 0.0;
}

std::string DigitalOption::name() const {
    return "DigitalOption";
}
