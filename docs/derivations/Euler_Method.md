# ODE Solvers

Ordinary Differential Equation (ODE) solvers approximate the solution of Initial Value Problems (IVPs):
$\frac{dy}{dt} = f(t, y), \quad y(t_0) = y_0$

## Euler Method

The Euler method is a first-order numerical procedure for solving ODEs. It is the simplest Runge-Kutta method.
$y_{n+1} = y_n + h f(t_n, y_n)$
Error: $O(h)$ (Local), $O(h)$ (Global)

## Improved Euler (Heun's Method)

The Improved Euler method is a second-order method that uses an intermediate step to better estimate the slope.
Predictor: $\tilde{y}_{n+1} = y_n + h f(t_n, y_n)$
Corrector: $y_{n+1} = y_n + \frac{h}{2} [f(t_n, y_n) + f(t_{n+1}, \tilde{y}_{n+1})]$
Error: $O(h^2)$

## Runge-Kutta 4 (RK4)

The RK4 method is a fourth-order method that is widely used for its balance of accuracy and computational cost.
$k_1 = f(t_n, y_n)$
$k_2 = f(t_n + \frac{h}{2}, y_n + \frac{h}{2} k_1)$
$k_3 = f(t_n + \frac{h}{2}, y_n + \frac{h}{2} k_2)$
$k_4 = f(t_n + h, y_n + h k_3)$
$y_{n+1} = y_n + \frac{h}{6} (k_1 + 2k_2 + 2k_3 + k_4)$
Error: $O(h^4)$

## Stability Discussion

Numerical stability refers to the property that errors do not grow as the computation progresses. Explicit methods like those above can be unstable if the step size $h$ is too large, especially for "stiff" equations. Implicit methods (not implemented here) are generally more stable for stiff problems.
