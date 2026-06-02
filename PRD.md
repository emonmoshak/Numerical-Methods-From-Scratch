# Product Requirements Document (PRD)

# Project Title

Numerical Methods From Scratch

---

# Vision

Build a professional scientific computing library implementing core numerical methods from first principles without relying on high-level numerical solvers.

The project should serve as both an educational mathematics resource and an engineering computation toolkit.

The emphasis is on mathematical derivation, algorithm analysis, numerical stability, and computational accuracy.

---

# Objectives

Demonstrate competency in:

* Numerical Analysis
* Linear Algebra
* Differential Equations
* Scientific Computing
* Error Analysis
* Algorithm Design
* Applied Mathematics

---

# Target Users

## Primary

* Engineering students
* Mathematics students
* Scientific computing enthusiasts

## Secondary

* Scholarship reviewers
* Professors
* Recruiters

---

# Core Features

## 1. Root Finding Methods

Implement:

### Bisection Method

### Newton-Raphson Method

### Secant Method

### Fixed Point Iteration

Display:

* Convergence history
* Error reduction
* Iteration count

---

## 2. Linear System Solvers

Implement:

### Gaussian Elimination

### LU Decomposition

### Gauss-Seidel Method

### Jacobi Iteration

Display:

* Solution vector
* Residual error
* Computational complexity

---

## 3. Interpolation

Implement:

### Lagrange Interpolation

### Newton Interpolation

### Cubic Spline Interpolation

Display:

* Interpolation curve
* Error comparison

---

## 4. Numerical Differentiation

Implement:

### Forward Difference

### Backward Difference

### Central Difference

Display:

* Approximation error
* Convergence behavior

---

## 5. Numerical Integration

Implement:

### Trapezoidal Rule

### Simpson's Rule

### Gaussian Quadrature

Display:

* Integral approximation
* Error analysis

---

## 6. ODE Solvers

Implement:

### Euler Method

### Improved Euler

### Runge-Kutta 4

Display:

* Numerical solution
* Analytical solution
* Error plots

---

## 7. Matrix Computation Module

Implement:

### Matrix Multiplication

### Determinant Calculation

### Matrix Inverse

### Eigenvalue Approximation

### Power Iteration

---

## 8. Error Analysis Framework

Compute:

* Absolute Error
* Relative Error
* Truncation Error
* Convergence Rate

---

## 9. Visualization Engine

Generate:

* Convergence graphs
* Error plots
* Function approximation plots
* Stability analysis plots

---

## 10. Mathematical Documentation

Every algorithm must include:

* Formal problem statement
* Derivation
* Mathematical proof
* Complexity analysis
* Stability discussion

---

# Technical Architecture

## Language

C++20

---

## Libraries

Eigen

matplotplusplus

fmt

GoogleTest

---

## Modules

root_finding/

linear_algebra/

interpolation/

integration/

differentiation/

ode/

visualization/

tests/

docs/

---

# Documentation Requirements

Create:

docs/derivations/

Required documents:

* Bisection_Method.md
* Newton_Raphson.md
* LU_Decomposition.md
* Euler_Method.md
* Runge_Kutta.md
* Numerical_Integration.md
* Error_Analysis.md

All derivations written using LaTeX.

---

# Success Criteria

A user can:

1. Solve nonlinear equations.
2. Solve matrix systems.
3. Approximate derivatives.
4. Approximate integrals.
5. Solve ODEs.
6. Visualize convergence.
7. Understand the mathematics behind every algorithm.

The project should demonstrate strong competency in engineering mathematics and numerical analysis.
