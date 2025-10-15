#include "RNG.hpp"

RNG::RNG(unsigned int seed)
    : gen_(seed), normal_(0.0, 1.0), uniform_(0.0, 1.0) {}

double RNG::randn() const {
    return normal_(gen_);
}

double RNG::randu() const {
    return uniform_(gen_);
}
