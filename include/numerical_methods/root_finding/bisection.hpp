#pragma once

#include "numerical_methods/common/error_metrics.hpp"
#include "numerical_methods/common/result.hpp"
#include <functional>

namespace nm::root_finding {

/**
 * @brief Parameters for root-finding algorithms.
 */
struct SolverParams {
    double tolerance = 1e-7;
    int max_iterations = 1000;
};

/**
 * @brief Solves f(x) = 0 using the Bisection Method.
 * 
 * @param f The function to solve.
 * @param a Left bound of the interval.
 * @param b Right bound of the interval.
 * @param params Solver parameters (tolerance, max iterations).
 * @return Result<double> containing the root and convergence info.
 */
inline common::Result<double> bisection(
    const std::function<double(double)>& f, 
    double a, 
    double b, 
    SolverParams params = {}) {
    
    double fa = f(a);
    double fb = f(b);

    if (fa * fb > 0) {
        return {0.0, common::Status::InvalidInput, 0, {}, "Function has same signs at both ends of the interval."};
    }

    if (std::abs(fa) < params.tolerance) return {a, common::Status::Success, 0, {}, "Initial a is root"};
    if (std::abs(fb) < params.tolerance) return {b, common::Status::Success, 0, {}, "Initial b is root"};

    double c = a;
    std::vector<double> errors;
    
    for (int i = 0; i < params.max_iterations; ++i) {
        double prev_c = c;
        c = (a + b) / 2.0;
        double fc = f(c);

        if (i > 0) {
            errors.push_back(common::ErrorMetrics::absolute_error(c, prev_c));
        }

        if (std::abs(fc) < params.tolerance || (b - a) / 2.0 < params.tolerance) {
            return {c, common::Status::Success, i + 1, errors, "Converged"};
        }

        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }

    return {c, common::Status::MaxIterationsReached, params.max_iterations, errors, "Maximum iterations reached"};
}

} // namespace nm::root_finding
