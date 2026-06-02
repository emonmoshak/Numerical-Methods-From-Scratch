# Numerical Calculus: Differentiation and Integration

## Numerical Differentiation

Numerical differentiation approximates the derivative of a function using its values at discrete points.

### Finite Difference Schemes

1. **Forward Difference**:
$f'(x) \approx \frac{f(x+h) - f(x)}{h} + O(h)$

2. **Backward Difference**:
$f'(x) \approx \frac{f(x) - f(x-h)}{h} + O(h)$

3. **Central Difference**:
$f'(x) \approx \frac{f(x+h) - f(x-h)}{2h} + O(h^2)$

Central difference is more accurate ($O(h^2)$) as the first-order error terms cancel out.

## Numerical Integration (Quadrature)

Numerical integration approximates the definite integral $\int_a^b f(x) dx$.

### Newton-Cotes Formulas

1. **Trapezoidal Rule**:
$\int_a^b f(x) dx \approx \frac{h}{2} [f(a) + f(b)]$
Composite: $\int_a^b f(x) dx \approx \frac{h}{2} [f(x_0) + 2\sum_{i=1}^{n-1} f(x_i) + f(x_n)]$
Error: $O(h^2)$

2. **Simpson's 1/3 Rule**:
$\int_a^b f(x) dx \approx \frac{h}{3} [f(a) + 4f(\frac{a+b}{2}) + f(b)]$
Error: $O(h^4)$

### Gaussian Quadrature

Gaussian quadrature chooses both the weights $w_i$ and the points $x_i$ to maximize accuracy.
$\int_{-1}^1 f(x) dx \approx \sum_{i=1}^n w_i f(x_i)$

For $n=2$: $x_i = \pm \frac{1}{\sqrt{3}}, w_i = 1$. Exact for polynomials of degree up to $2n-1 = 3$.

## Stability Discussion

Numerical differentiation is inherently unstable due to subtraction of nearly equal values when $h$ is very small (round-off error). There is an optimal $h$ that balances truncation error $O(h^k)$ and round-off error $O(\epsilon/h)$.

Numerical integration is stable as it is an averaging process.
