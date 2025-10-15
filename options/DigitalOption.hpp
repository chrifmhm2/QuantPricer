#pragma once
#include "Option.hpp"

class DigitalOption : public Option {
private:
    double payout_; // fixed amount

public:
    DigitalOption(double strike, double maturity, OptionType type, double payout);
    double payoff(double spot) const override;
    std::string name() const override;
};
