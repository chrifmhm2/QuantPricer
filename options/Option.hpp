#pragma once
#include <string>
#include <vector>
enum class OptionType { Call, Put };

class Option {
protected:
    double strike_;      // Prix d'exercice K
    double maturity_;    // Maturité T
    OptionType type_;    // Call ou Put

public:
    Option(double strike, double maturity, OptionType type)
        : strike_(strike), maturity_(maturity), type_(type) {}

    virtual ~Option() = default;

    // === Getters ===
    double getStrike() const { return strike_; }
    double getMaturity() const { return maturity_; }
    OptionType getType() const { return type_; }

    // === Méthode virtuelle pure ===
    virtual double payoff(double ST) const = 0; // Payoff terminal
    virtual std::string name() const = 0;
};
