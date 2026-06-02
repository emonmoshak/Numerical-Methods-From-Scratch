# Numerical Methods From Scratch

A professional scientific computing library implementing core numerical methods from first principles in C++20.

## Overview

This project serves as both an educational mathematics resource and an engineering computation toolkit. It focuses on mathematical derivation, algorithm analysis, numerical stability, and computational accuracy.

## Features

- **Root Finding:** Bisection, Newton-Raphson, Secant, Fixed Point Iteration.
- **Linear Algebra:** Gaussian Elimination, LU Decomposition, Gauss-Seidel, Jacobi.
- **Interpolation:** Lagrange, Newton, Cubic Spline.
- **Numerical Differentiation:** Forward, Backward, and Central Difference.
- **Numerical Integration:** Trapezoidal Rule, Simpson's Rule, Gaussian Quadrature.
- **ODE Solvers:** Euler, Improved Euler, Runge-Kutta 4.
- **Matrix Computation:** Multiplication, Determinant, Inverse, Eigenvalues (Power Iteration).
- **Visualization:** Convergence graphs and error plots using `matplotplusplus`.

## Prerequisites

- C++20 Compatible Compiler (GCC 10+, Clang 10+, MSVC 19.28+)
- CMake 3.20+
- Dependencies (managed via FetchContent or system-wide installation):
    - Eigen
    - matplotplusplus
    - fmt
    - GoogleTest

## Project Structure

- `include/`: Header files (.hpp)
- `src/`: Source files (.cpp)
- `tests/`: Unit tests using GoogleTest
- `examples/`: Usage examples
- `docs/`: Project documentation and mathematical derivations

## Building the Project

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Documentation

Mathematical derivations for the algorithms can be found in `docs/derivations/`.
