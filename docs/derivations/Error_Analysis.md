# Error Analysis in Numerical Methods

Error analysis is fundamental to numerical computing, providing bounds on how much the numerical approximation deviates from the true solution.

## Types of Errors

### 1. Round-off Error
Due to the finite precision of computer arithmetic (floating-point representation).

### 2. Truncation Error
Due to the approximation of a mathematical process (e.g., stopping a Taylor series at a finite term).

## Error Metrics

Given an approximation $\hat{x}$ and a true value $x$:

- **Absolute Error**: $E_{abs} = |\hat{x} - x|$
- **Relative Error**: $E_{rel} = \frac{|\hat{x} - x|}{|x|}$ (Undefined if $x=0$)
- **Approximate Relative Error**: $E_{a} = \frac{|\hat{x}_{new} - \hat{x}_{old}|}{|\hat{x}_{new}|}$ (Used when the true value is unknown)

## Order of Convergence

A method is said to have order of convergence $p$ if:
$\lim_{n \to \infty} \frac{|x_{n+1} - r|}{|x_n - r|^p} = C$

- $p=1$: Linear convergence (e.g., Bisection, Fixed Point).
- $1 < p < 2$: Superlinear convergence (e.g., Secant).
- $p=2$: Quadratic convergence (e.g., Newton-Raphson).

## Stability

A numerical algorithm is **stable** if errors made during the computation do not grow as the algorithm progresses. Stability often depends on both the algorithm and the problem being solved (conditioning).
