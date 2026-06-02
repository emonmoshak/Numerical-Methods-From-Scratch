# Interpolation

Interpolation is the process of finding a function that passes through a given set of data points.

## Lagrange Interpolation

Given $n+1$ points $(x_0, y_0), \dots, (x_n, y_n)$, the Lagrange interpolating polynomial is:
$P(x) = \sum_{i=0}^n y_i L_i(x)$

where $L_i(x)$ are the Lagrange basis polynomials:
$L_i(x) = \prod_{j=0, j \neq i}^n \frac{x - x_j}{x_i - x_j}$

## Newton Interpolation

Newton interpolation uses divided differences to build the polynomial incrementally.
$P(x) = f[x_0] + f[x_0, x_1](x - x_0) + f[x_0, x_1, x_2](x - x_0)(x - x_1) + \dots$

Divided differences are defined recursively:
$f[x_i, \dots, x_{i+k}] = \frac{f[x_{i+1}, \dots, x_{i+k}] - f[x_i, \dots, x_{i+k-1}]}{x_{i+k} - x_i}$

## Cubic Spline Interpolation

Cubic splines use piecewise cubic polynomials $S_i(x)$ between each pair of points $(x_i, x_{i+1})$.
$S_i(x) = a_i + b_i(x - x_i) + c_i(x - x_i)^2 + d_i(x - x_i)^3$

Constraints:
1. $S_i(x_i) = y_i$ and $S_i(x_{i+1}) = y_{i+1}$ (Interpolation)
2. $S_i'(x_{i+1}) = S_{i+1}'(x_{i+1})$ (Continuous first derivative)
3. $S_i''(x_{i+1}) = S_{i+1}''(x_{i+1})$ (Continuous second derivative)

## Error Analysis

The error for polynomial interpolation is:
$f(x) - P(n)(x) = \frac{f^{(n+1)}(\xi)}{(n+1)!} \prod_{i=0}^n (x - x_i)$

For cubic splines, the error is $O(h^4)$, where $h$ is the maximum spacing between points.

## Complexity Analysis

- **Lagrange**: $O(n^2)$ to evaluate at one point.
- **Newton**: $O(n^2)$ to build the table, $O(n)$ to evaluate.
- **Cubic Spline**: $O(n)$ to solve the tridiagonal system for coefficients, $O(1)$ to evaluate in a specific interval.

## Stability Discussion

High-degree polynomial interpolation can suffer from **Runge's phenomenon**, where large oscillations occur near the edges of the interval. Cubic splines are much more stable and preferred for smooth interpolation.
