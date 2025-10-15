# QuantPricer 🧮

A modular C++ pricing engine for derivatives based on advanced stochastic processes and numerical methods.

---

## 🚀 Overview

**QuantPricer** is a quantitative finance simulation framework that models and prices financial derivatives under various stochastic dynamics.  
It is designed to be **modular**, **efficient**, and **extensible**, following object-oriented and SOLID principles.

---

## 🧠 Implemented Models

| Category | Model |
|-----------|--------|
| Diffusion | Geometric Brownian Motion, Ornstein–Uhlenbeck |
| Interest Rate | Vasicek, CIR, Hull–White |
| Volatility | Heston, SABR |
| Jump Process | Merton Jump-Diffusion |

---

## 💹 Supported Derivatives

| Type | Features |
|------|-----------|
| European | Black–Scholes, Monte Carlo |
| Asian | Arithmetic/Geometric average |
| American | Longstaff-Schwartz (LSMC) |
| Barrier | Up-and-Out, Down-and-In |
| Digital | Binary payout |

---

## 🔧 Pricing Methods

- **Monte Carlo Simulation** (Euler, Milstein)
- **Closed-Form Solutions** (Black–Scholes, Vasicek bond)
- **Longstaff-Schwartz Regression** (for American)
- **Finite Differences** *(optional later)*

---

## 🧰 Hedging & Greeks

- Delta, Gamma, Vega, Rho estimation by finite differences  
- Delta-hedging backtest simulations  
- Pathwise Greeks (optional future module)

---

## 📦 Project Structure

