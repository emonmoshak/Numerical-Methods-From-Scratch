# Fixed Point Iteration

Fixed Point Iteration is a method for finding roots by rewriting the equation $f(x) = 0$ in the form $x = g(x)$.

## Mathematical Derivation

To solve $f(x) = 0$, we transform it into an equivalent fixed-point problem $x = g(x)$. A point $r$ such that $g(r) = r$ is called a fixed point of $g$. If $r$ is a fixed point of $g$, then it is a root of $f$.

The iteration scheme is:
$x_{n+1} = g(x_n)$

starting from an initial guess $x_0$.

## Convergence Analysis (Fixed Point Theorem)

The iteration $x_{n+1} = g(x_n)$ converges to a unique fixed point $r$ in an interval $[a, b]$ if:
1. $g(x) \in [a, b]$ for all $x \in [a, b]$.
2. $g$ is continuously differentiable on $[a, b]$.
3. There exists a constant $k < 1$ such that $|g'(x)| \leq k$ for all $x \in [a, b]$ (Contraction Mapping).

The convergence is linear with rate $k = |g'(r)|$.

## Complexity Analysis

Each iteration requires one evaluation of $g(x)$. The number of iterations depends on the value of $|g'(r)|$; the smaller the value, the faster the convergence.

## Stability Discussion

The choice of $g(x)$ is critical. Multiple $g(x)$ can be derived from the same $f(x) = 0$, but only those satisfying $|g'(r)| < 1$ will converge. If $|g'(r)| > 1$, the iteration will diverge from the root.
