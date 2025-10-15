#include <iostream>
#include <vector>
#include <iomanip> // pour std::setprecision
#include "stochastic_models/GeometricBrownianMotion.hpp"
#include "stochastic_models/Vasicek.hpp"
#include "stochastic_models/CIR.hpp"
#include "stochastic_models/OrnsteinUhlenbeck.hpp"

void testGBM() {
    std::cout << "\n=============================\n";
    std::cout << "🌐 Simulation : Geometric Brownian Motion (GBM)";
    std::cout << "\n=============================\n";

    double S0 = 100.0;   // prix initial
    double mu = 0.05;    // drift (5%)
    double sigma = 0.2;  // volatilité (20%)
    double T = 1.0;      // maturité (1 an)
    int N = 252;         // nombre de pas (252 jours)

    GeometricBrownianMotion gbm(mu, sigma);
    std::vector<double> path = gbm.simulatePath(S0, T, N);

    std::cout << std::fixed << std::setprecision(4);
    for (int i = 0; i < 10 && i < path.size(); ++i)
        std::cout << "Step " << i << " : S = " << path[i] << std::endl;

    std::cout << "Valeur finale S(T) = " << path.back() << std::endl;
}

void testVasicek() {
    std::cout << "\n=============================\n";
    std::cout << "🏦 Simulation : Vasicek Interest Rate Process";
    std::cout << "\n=============================\n";

    double r0 = 0.03;    // taux initial
    double kappa = 0.3;  // vitesse de réversion
    double theta = 0.05; // moyenne de long terme
    double sigma = 0.02; // volatilité
    double T = 1.0;      // horizon de 1 an
    int N = 252;         // pas de temps

    Vasicek vasicek(kappa, theta, sigma);
    std::vector<double> path = vasicek.simulatePath(r0, T, N);

    std::cout << std::fixed << std::setprecision(6);
    for (int i = 0; i < 10 && i < path.size(); ++i)
        std::cout << "Step " << i << " : r = " << path[i] << std::endl;

    std::cout << "Valeur finale r(T) = " << path.back() << std::endl;
}


void testCIR() {
    std::cout << "\n=============================\n";
    std::cout << "💠 Simulation : CIR Process";
    std::cout << "\n=============================\n";

    double r0 = 0.03, kappa = 0.5, theta = 0.04, sigma = 0.1;
    double T = 1.0;
    int N = 252;

    CIR cir(kappa, theta, sigma);

    // Test 1 - Euler
    auto pathEuler = cir.simulatePathEuler(r0, T, N);
    std::cout << "Euler: Final r(T) = " << pathEuler.back() << std::endl;

    // Test 2 - Exact (approx)
    auto pathExact = cir.simulatePath(r0, T, N);
    std::cout << "Exact (approx): Final r(T) = " << pathExact.back() << std::endl;
}


void testOrnsteinUhlenbeck() {
    std::cout << "\n=============================\n";
    std::cout << "🌿 Simulation : Ornstein–Uhlenbeck Process\n";
    std::cout << "=============================\n";

    double X0 = 0.02, kappa = 1.0, theta = 0.05, sigma = 0.03;
    double T = 1.0; int N = 252;

    OrnsteinUhlenbeck ou(kappa, theta, sigma);
    auto path = ou.simulatePath(X0, T, N);

    for (int i = 0; i < 10; ++i)
        std::cout << "Step " << i << " : X = " << path[i] << std::endl;

    std::cout << "Final X(T) = " << path.back() << std::endl;
}

int main() {
    std::cout << "=== QuantPricer: Stochastic Process Simulator ===\n";

    // 🟢 Test 1 : Geometric Brownian Motion
    testGBM();

    // 🟢 Test 2 : Vasicek Process
    testVasicek();

    // 🟡 À venir :
    // testCIR();
    testCIR();
    // testOrnsteinUhlenbeck();
    testOrnsteinUhlenbeck();
    // testHeston();
    // testHullWhite();
    // testMerton();
    // testSABR();

    std::cout << "\nSimulation terminée ✅\n";
    return 0;
}
