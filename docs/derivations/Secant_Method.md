# Secant Method

The Secant Method is a root-finding algorithm that uses a succession of roots of secant lines to better approximate a root of a function $f$. It can be thought of as a finite-difference approximation of Newton's method.

## Mathematical Derivation

In Newton's method, the iteration is $x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}$. If the derivative $f'(x_n)$ is unknown or expensive to calculate, we can approximate it using the values of $f$ at two recent points $x_n$ and $x_{n-1}$:

$f'(x_n) \approx \frac{f(x_n) - f(x_{n-1})}{x_n - x_{n-1}}$

Substituting this into the Newton's method formula gives the Secant Method iteration:

$x_{n+1} = x_n - f(x_n) \frac{x_n - x_{n-1}}{f(x_n) - f(x_{n-1})}$

This method requires two initial guesses, $x_0$ and $x_1$.

## Convergence Analysis

The Secant Method converges superlinearly. The rate of convergence $\alpha$ is given by the golden ratio:
$\alpha = \frac{1 + \sqrt{5}}{2} \approx 1.618$

This means it is faster than the Bisection method but slower than Newton's method.

## Complexity Analysis

Each iteration requires only one new function evaluation (since $f(x_n)$ was calculated in the previous step). This makes it computationally efficient if $f'(x)$ is expensive.

## Stability Discussion

The Secant Method can be unstable if $f(x_n) \approx f(x_{n-1})$, which can lead to division by a very small number. Like Newton's method, it requires the initial guesses to be sufficiently close to the root.
