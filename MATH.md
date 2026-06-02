# Mathematical Foundations of Numerical Methods

This document serves as an index and overview of the mathematical principles implemented in this library.

## Root Finding

Finding $x$ such that $f(x) = 0$.

- [Bisection Method](docs/derivations/Bisection_Method.md): Robust, linear convergence using interval bisection.
- [Newton-Raphson Method](docs/derivations/Newton_Raphson.md): Fast, quadratic convergence using linear approximation.
- [Secant Method](docs/derivations/Secant_Method.md): Superlinear convergence without needing derivatives.
- [Fixed Point Iteration](docs/derivations/Fixed_Point_Iteration.md): General iterative scheme $x = g(x)$.

## Linear Algebra

Solving systems $Ax = b$ and matrix analysis.

- [LU Decomposition](docs/derivations/LU_Decomposition.md): Factorization for efficient solving and determinants.
- [Gaussian Elimination](docs/derivations/LU_Decomposition.md): Direct solver with partial pivoting.
- [Iterative Solvers (Jacobi & Gauss-Seidel)](docs/derivations/Iterative_Linear_Solvers.md): Successive approximation for large systems.
- Power Iteration: Dominant eigenvalue and eigenvector approximation.

## Interpolation

Fitting functions to data points.

- [Polynomial Interpolation (Lagrange & Newton)](docs/derivations/Interpolation.md): Global polynomial fit.
- [Cubic Spline Interpolation](docs/derivations/Interpolation.md): Piecewise smooth cubic fit.

## Calculus

Numerical approximation of derivatives and integrals.

- [Numerical Differentiation](docs/derivations/Numerical_Integration.md): Finite difference schemes (Forward, Backward, Central).
- [Numerical Integration](docs/derivations/Numerical_Integration.md): Trapezoidal Rule, Simpson's Rule, Gaussian Quadrature.

## Differential Equations

Solving Initial Value Problems $\frac{dy}{dt} = f(t, y)$.

- [Euler Method](docs/derivations/Euler_Method.md): Basic first-order integration.
- [Improved Euler](docs/derivations/Euler_Method.md): Second-order predictor-corrector method.
- [RK4 (Runge-Kutta 4)](docs/derivations/Runge_Kutta.md): High-accuracy fourth-order integration.
