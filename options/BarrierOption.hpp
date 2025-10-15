#pragma once
#include "Option.hpp"
#include <vector>

enum class BarrierType { UpAndOut, DownAndOut, UpAndIn, DownAndIn };

class BarrierOption : public Option {
private:
    double barrier_;
    BarrierType barrierType_;

public:
    BarrierOption(double strike, double maturity, OptionType type, double barrier, BarrierType btype);
    double payoff(const std::vector<double>& path) const;
    std::string name() const override;
};
