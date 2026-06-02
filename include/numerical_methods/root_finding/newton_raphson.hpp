#pragma once

#include "numerical_methods/common/error_metrics.hpp"
#include "numerical_methods/common/result.hpp"
#include "numerical_methods/root_finding/bisection.hpp" // For SolverParams
#include <functional>

namespace nm::root_finding {

/**
 * @brief Solves f(x) = 0 using the Newton-Raphson Method.
 * 
 * @param f The function to solve.
 * @param df The derivative of the function.
 * @param x0 Initial guess.
 * @param params Solver parameters (tolerance, max iterations).
 * @return Result<double> containing the root and convergence info.
 */
inline common::Result<double> newton_raphson(
    const std::function<double(double)>& f,
    const std::function<double(double)>& df,
    double x0,
    SolverParams params = {}) {
    
    double x = x0;
    std::vector<double> errors;

    for (int i = 0; i < params.max_iterations; ++i) {
        double fx = f(x);
        double dfx = df(x);

        if (std::abs(dfx) < 1e-12) {
            return {x, common::Status::Error, i, errors, "Derivative too small; possible division by zero."};
        }

        double next_x = x - fx / dfx;
        double error = common::ErrorMetrics::absolute_error(next_x, x);
        errors.push_back(error);

        x = next_x;

        if (error < params.tolerance) {
            return {x, common::Status::Success, i + 1, errors, "Converged"};
        }
    }

    return {x, common::Status::MaxIterationsReached, params.max_iterations, errors, "Maximum iterations reached"};
}

} // namespace nm::root_finding
