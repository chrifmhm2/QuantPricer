#pragma once
#include "Pricer.hpp"
#include <vector>
#include <Eigen/Dense>

class LongstaffSchwartz : public Pricer {
private:
    int nPaths_;
    int nSteps_;
    double riskFree_;
    unsigned int seed_;

public:
    LongstaffSchwartz(int nPaths = 10000, int nSteps = 100, double riskFree = 0.0, unsigned int seed = 123);

    PricingResult price(
        const Option& option,
        const StochasticProcess& process,
        double spot
    ) const override;

private:
    double regression(const Eigen::MatrixXd& X, const Eigen::VectorXd& Y) const;
};
