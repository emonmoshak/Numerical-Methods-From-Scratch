# Newton-Raphson Method

The Newton-Raphson method is a powerful technique for solving equations numerically. It is based on the idea of linear approximation.

## Mathematical Derivation

Suppose we want to find a root of the equation $f(x) = 0$. Let $x_n$ be an approximation of the root. We can approximate $f(x)$ near $x_n$ using the first two terms of its Taylor series expansion:

$f(x) \approx f(x_n) + f'(x_n)(x - x_n)$

To find a better approximation $x_{n+1}$, we set the linear approximation to zero:

$f(x_n) + f'(x_n)(x_{n+1} - x_n) = 0$

Solving for $x_{n+1}$:

$x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}$

This formula is applied iteratively until the desired accuracy is achieved.

## Convergence Analysis

Newton's method converges quadratically if the root is simple ($f'(r) \neq 0$) and the initial guess $x_0$ is sufficiently close to the root $r$.

The error $e_n = x_n - r$ satisfies:
$e_{n+1} \approx \frac{f''(r)}{2f'(r)} e_n^2$

## Complexity Analysis

Each iteration requires one evaluation of $f(x)$ and one evaluation of $f'(x)$. The number of iterations for quadratic convergence is typically small ($< 10-20$).

## Stability Discussion

The method can fail if:
1. $f'(x_n) \approx 0$ (the tangent is nearly horizontal).
2. The initial guess is far from the root, leading to divergence or oscillation.
3. The root is not simple (convergence becomes linear).
