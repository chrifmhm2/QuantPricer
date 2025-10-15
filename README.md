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

# 📘 Stochastic Models Implemented in QuantPricer

This section presents the mathematical foundations of all stochastic processes implemented in the project.  
Each process is characterized by its **Stochastic Differential Equation (SDE)**, **parameters**, and **applications**.

---

## 🧩 1. Geometric Brownian Motion (GBM)

\[
dS_t = \mu S_t \, dt + \sigma S_t \, dW_t
\]

**Analytical solution:**
\[
S_t = S_0 \exp\left( (\mu - \tfrac{1}{2}\sigma^2)t + \sigma W_t \right)
\]

| Parameter | Meaning |
|------------|----------|
| \( \mu \) | Drift (average growth rate) |
| \( \sigma \) | Constant volatility |

**Use case:** basic model for stock prices (Black–Scholes model).

---

## 🧩 2. Vasicek Model

\[
dr_t = \kappa(\theta - r_t)\, dt + \sigma \, dW_t
\]

| Parameter | Meaning |
|------------|----------|
| \( \kappa \) | Speed of mean reversion |
| \( \theta \) | Long-term mean level |
| \( \sigma \) | Volatility |

**Key feature:** Mean-reverting rate process (can become negative).  
**Use case:** Short-rate modeling in fixed income.

---

## 🧩 3. Cox–Ingersoll–Ross (CIR) Model

\[
dr_t = \kappa(\theta - r_t)\, dt + \sigma \sqrt{r_t} \, dW_t
\]

| Parameter | Meaning |
|------------|----------|
| \( \kappa \) | Mean reversion speed |
| \( \theta \) | Long-term rate level |
| \( \sigma \) | Volatility coefficient |

**Feller condition (positivity):**
\[
2\kappa\theta > \sigma^2
\]

**Use case:** interest rate or stochastic volatility modeling.

---

## 🧩 4. Ornstein–Uhlenbeck Process (OU)

\[
dX_t = \kappa(\theta - X_t)\, dt + \sigma \, dW_t
\]

**Closed-form solution:**
\[
X_t = \theta + (X_0 - \theta)e^{-\kappa t} + \sigma \int_0^t e^{-\kappa(t-s)} dW_s
\]

| Parameter | Meaning |
|------------|----------|
| \( \kappa \) | Speed of mean reversion |
| \( \theta \) | Long-term mean |
| \( \sigma \) | Volatility |

**Use case:** mean-reverting quantities (interest rate spreads, log-volatility).

---

## 🧩 5. Heston Model

\[
\begin{cases}
dS_t = \mu S_t \, dt + \sqrt{v_t} S_t \, dW_t^S \\
dv_t = \kappa(\theta - v_t)\, dt + \sigma_v \sqrt{v_t} \, dW_t^v
\end{cases}
\]

with correlation \( dW_t^S dW_t^v = \rho \, dt \).

| Parameter | Meaning |
|------------|----------|
| \( \mu \) | Asset drift |
| \( \kappa, \theta, \sigma_v \) | Variance dynamics parameters |
| \( \rho \) | Correlation between price and variance |

**Use case:** modeling stochastic volatility and volatility smiles.

---

## 🧩 6. Hull–White Model

\[
dr_t = [\theta(t) - a r_t]\, dt + \sigma \, dW_t
\]

| Parameter | Meaning |
|------------|----------|
| \( a \) | Mean reversion speed |
| \( \sigma \) | Volatility |
| \( \theta(t) \) | Time-dependent drift (fits yield curve) |

**Use case:** interest rate modeling (caps, floors, swaps).

---

## 🧩 7. Merton Jump-Diffusion Model

\[
dS_t = \mu S_t \, dt + \sigma S_t \, dW_t + S_t (J - 1) \, dN_t
\]

where:
- \( N_t \) is a Poisson process with intensity \( \lambda \),
- \( J \) is the random jump size (log-normal).

| Parameter | Meaning |
|------------|----------|
| \( \lambda \) | Jump intensity |
| \( \mu_J, \sigma_J \) | Mean and std. of jump magnitude |

**Use case:** models sudden price jumps (crashes, news, announcements).

---

## 🧩 8. SABR Model

\[
\begin{cases}
dF_t = \alpha_t F_t^{\beta} \, dW_t^1 \\
d\alpha_t = \nu \alpha_t \, dW_t^2
\end{cases}
\]

with \( dW_t^1 dW_t^2 = \rho \, dt \).

| Parameter | Meaning |
|------------|----------|
| \( \alpha \) | Initial volatility |
| \( \beta \) | Elasticity parameter (0 ≤ β ≤ 1) |
| \( \rho \) | Correlation between asset and volatility |
| \( \nu \) | Volatility of volatility |

**Special cases:**
- \( \beta = 1 \): lognormal (Black model)
- \( \beta = 0 \): normal (Bachelier model)

**Use case:** calibration of implied volatility surfaces (FX, rates).

---

# ⚙️ Build & Run Instructions

### 🔧 Requirements

- **C++17** or later  
- **CMake ≥ 3.15**  
- Optional: Python / R for result visualization  

---

### 🏗️ Build Instructions

```bash
# 1. Clone the project
git clone https://github.com/<username>/QuantPricer.git
cd QuantPricer

# 2. Create build directory
mkdir build && cd build

# 3. Generate build files
cmake ..

# 4. Compile
make -j4
