# Numerical Methods From Scratch

A professional scientific computing library implementing core numerical methods from first principles in C++20.

## Overview

This project serves as both an educational mathematics resource and an engineering computation toolkit. It focuses on mathematical derivation, algorithm analysis, numerical stability, and computational accuracy.

## Features

### Root Finding
- **Bisection Method**: Robust and guaranteed convergence.
- **Newton-Raphson**: Fast quadratic convergence.
- **Secant Method**: Efficient without needing analytical derivatives.
- **Fixed Point Iteration**: Versatile iterative solver.

### Linear Algebra
- **Gaussian Elimination**: With partial pivoting for stability.
- **LU Decomposition**: Efficient for multiple right-hand sides.
- **Jacobi & Gauss-Seidel**: Iterative methods for large systems.
- **Matrix Utilities**: Determinant, Inverse, and Eigenvalues (Power Iteration).

### Interpolation
- **Lagrange & Newton Polynomials**: Global interpolation.
- **Cubic Splines**: Smooth piecewise interpolation.

### Numerical Calculus
- **Differentiation**: Forward, Backward, and Central finite differences.
- **Integration**: Trapezoidal, Simpson's 1/3, and 2-point Gaussian Quadrature.

### ODE Solvers
- **Euler & Improved Euler**: Fundamental time-stepping.
- **RK4**: High-order accuracy for initial value problems.

## Mathematical Rigor

Every algorithm in this library is accompanied by a formal derivation and analysis in `docs/derivations/`. For a high-level overview, see [MATH.md](MATH.md).

## Prerequisites

- C++20 Compatible Compiler (GCC 10+, Clang 10+, MSVC 19.28+)
- CMake 3.20+

## Building and Testing

```bash
mkdir build
cd build
cmake ..
cmake --build .
ctest --output-on-failure
```

## Documentation

Mathematical derivations for the algorithms can be found in `docs/derivations/`.
Detailed contributing guidelines are in `CONTRIBUTING.md`.
