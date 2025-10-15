#include "Vasicek.hpp"
#include "../utils/RNG.hpp"
#include <iostream>
#include <vector>


Vasicek::Vasicek(double kappa, double theta, double sigma): kappa_(kappa), theta_(theta), sigma_(sigma) {}



std::vector<double>  Vasicek::simulatePath(double r0, double T, int N) const
{
    RNG rng;
    std::vector<double> r(N+1);
    r[0] = r0;
    double dt = T/static_cast<double>(N);

    for(int i =0; i <N; i++)
    {
        double Z = rng.randn();
        double exp_term = std::exp(-kappa_ *dt);
        double mean = theta_ + (r[i] -theta_)*exp_term;
        double variance = (sigma_ * sigma_) * (1 - std::exp(-2 * kappa_ * dt)) / (2 * kappa_);
        double stddev = std::sqrt(variance);
        r[i+1] = mean + stddev * Z;
    }
    return r;
}



double Vasicek::drift(double t, double r) const
{
    return kappa_*(theta_ -r);
   
}

double Vasicek::diffusion(double t, double r) const
{
    return sigma_;
}