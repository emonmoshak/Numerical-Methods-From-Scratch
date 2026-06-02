#pragma once

#include <functional>

namespace nm::calculus {

/**
 * @brief Approximates the derivative using forward difference.
 */
inline double forward_difference(const std::function<double(double)>& f, double x, double h = 1e-5) {
    return (f(x + h) - f(x)) / h;
}

/**
 * @brief Approximates the derivative using backward difference.
 */
inline double backward_difference(const std::function<double(double)>& f, double x, double h = 1e-5) {
    return (f(x) - f(x - h)) / h;
}

/**
 * @brief Approximates the derivative using central difference.
 */
inline double central_difference(const std::function<double(double)>& f, double x, double h = 1e-5) {
    return (f(x + h) - f(x - h)) / (2.0 * h);
}

} // namespace nm::calculus
