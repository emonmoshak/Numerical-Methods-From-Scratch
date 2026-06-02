# v1.0.0: Rigorous Numerical Methods for Engineering Mathematics

## 🚀 Initial Public Release

This release marks the first stable version of **Numerical Methods From Scratch**, a C++20 scientific computing library built from first principles for robotics, aerospace, and academic research.

---

## 🔬 Mathematical Scope
Verified implementations across the "Core Four" pillars of numerical analysis:
*   **Root Finding:** Bisection, Newton-Raphson, Secant, and Fixed-Point Iteration.
*   **Linear Algebra:** Direct (Gaussian, LU) and Iterative (Jacobi, Gauss-Seidel) solvers.
*   **Calculus:** finite difference schemes and quadrature rules (Simpson's, Gaussian).
*   **Differential Equations:** Euler, Improved Euler, and RK4.

## 🛠 Engineering Excellence
*   **Modern C++20:** Header-only core logic utilizing templates and RAII.
*   **Observability:** Solver analytics via the `Result<T>` pattern, exposing internal convergence history.
*   **Visual Validation:** Integrated plotting suite powered by `matplotplusplus`.

## ✅ Verification Summary
*   **25 Unit Tests Passed:** 100% success rate across 7 specialized test suites.
*   **Build Verified:** CMake 3.20+ with GCC 10+ / Clang 10+ / MSVC 19.28+.
*   **Analytics Verified:** Empirical convergence rates (Quadratic/Linear) verified against theoretical derivations.

---

## 📦 Assets
*   **Technical Report:** Professional 20-page LaTeX report documenting methodology and results.
*   **Mathematical Proofs:** Step-by-step derivations for all implemented algorithms.

*June 2, 2026*
