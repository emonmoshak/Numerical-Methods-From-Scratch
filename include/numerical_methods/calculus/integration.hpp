#pragma once

#include <functional>
#include <vector>
#include <cmath>

namespace nm::calculus {

/**
 * @brief Approximates the integral using the composite Trapezoidal Rule.
 */
inline double trapezoidal_rule(const std::function<double(double)>& f, double a, double b, int n = 100) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h);
    }
    return h * sum;
}

/**
 * @brief Approximates the integral using the composite Simpson's 1/3 Rule.
 */
inline double simpsons_rule(const std::function<double(double)>& f, double a, double b, int n = 100) {
    if (n % 2 != 0) n++; // Simpson's rule requires an even number of intervals
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += (i % 2 == 0) ? 2.0 * f(x) : 4.0 * f(x);
    }
    return h / 3.0 * sum;
}

/**
 * @brief Approximates the integral using 2-point Gaussian Quadrature.
 */
inline double gaussian_quadrature_2pt(const std::function<double(double)>& f, double a, double b) {
    const double x1 = -1.0 / std::sqrt(3.0);
    const double x2 = 1.0 / std::sqrt(3.0);
    const double w = 1.0;

    auto transform = [a, b](double t) { return 0.5 * ((b - a) * t + (b + a)); };
    double factor = 0.5 * (b - a);

    return factor * (w * f(transform(x1)) + w * f(transform(x2)));
}

} // namespace nm::calculus
