#pragma once

#include "numerical_methods/common/error_metrics.hpp"
#include "numerical_methods/common/result.hpp"
#include "numerical_methods/root_finding/bisection.hpp" // For SolverParams
#include <functional>

namespace nm::root_finding {

/**
 * @brief Solves f(x) = 0 using the Secant Method.
 * 
 * @param f The function to solve.
 * @param x0 First initial guess.
 * @param x1 Second initial guess.
 * @param params Solver parameters (tolerance, max iterations).
 * @return Result<double> containing the root and convergence info.
 */
inline common::Result<double> secant(
    const std::function<double(double)>& f,
    double x0,
    double x1,
    SolverParams params = {}) {
    
    double f0 = f(x0);
    double f1 = f(x1);
    std::vector<double> errors;

    for (int i = 0; i < params.max_iterations; ++i) {
        if (std::abs(f1 - f0) < 1e-12) {
            return {x1, common::Status::Error, i, errors, "Division by zero in Secant method."};
        }

        double next_x = x1 - f1 * (x1 - x0) / (f1 - f0);
        double error = common::ErrorMetrics::absolute_error(next_x, x1);
        errors.push_back(error);

        x0 = x1;
        f0 = f1;
        x1 = next_x;
        f1 = f(x1);

        if (error < params.tolerance) {
            return {x1, common::Status::Success, i + 1, errors, "Converged"};
        }
    }

    return {x1, common::Status::MaxIterationsReached, params.max_iterations, errors, "Maximum iterations reached"};
}

} // namespace nm::root_finding
