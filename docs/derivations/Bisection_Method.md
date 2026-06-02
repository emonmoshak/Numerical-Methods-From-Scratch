# Bisection Method

The Bisection Method is a root-finding algorithm that applies to any continuous function for which one knows two values with opposite signs.

## Mathematical Derivation

Suppose $f(x)$ is a continuous function defined on the interval $[a, b]$, with $f(a)$ and $f(b)$ having opposite signs ($f(a) \cdot f(b) < 0$). According to the Intermediate Value Theorem, there exists at least one root $c$ within the interval $(a, b)$ such that $f(c) = 0$.

The method repeatedly bisects the interval and then selects a subinterval in which a root must lie for further processing.

1. Calculate the midpoint $c = \frac{a + b}{2}$.
2. Calculate the function value at the midpoint, $f(c)$.
3. If $f(c) = 0$ or the error is within tolerance, then $c$ is the root.
4. If $f(a) \cdot f(c) < 0$, the root lies in $[a, c]$. Set $b = c$.
5. If $f(b) \cdot f(c) < 0$, the root lies in $[c, b]$. Set $a = c$.

## Error Analysis

Let $L_n$ be the length of the interval after $n$ iterations.
$L_0 = b - a$
$L_1 = \frac{b - a}{2}$
$L_n = \frac{b - a}{2^n}$

The absolute error after $n$ iterations is bounded by:
$|c_n - c| \leq \frac{b - a}{2^{n+1}}$

## Complexity Analysis

The number of iterations $n$ required to achieve a tolerance $\epsilon$ is:
$\frac{b - a}{2^{n+1}} < \epsilon \implies n > \log_2\left(\frac{b - a}{\epsilon}\right) - 1$

The time complexity is $O(n \cdot C_f)$, where $C_f$ is the cost of evaluating the function $f(x)$.

## Stability Discussion

The Bisection Method is unconditionally stable and guaranteed to converge if the function is continuous and the initial signs are opposite. However, it converges linearly and is relatively slow compared to methods like Newton-Raphson.
