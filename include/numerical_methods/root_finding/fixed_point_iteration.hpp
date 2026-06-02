#pragma once

#include "numerical_methods/common/error_metrics.hpp"
#include "numerical_methods/common/result.hpp"
#include "numerical_methods/root_finding/bisection.hpp" // For SolverParams
#include <functional>

namespace nm::root_finding {

/**
 * @brief Solves x = g(x) using Fixed Point Iteration.
 * 
 * @param g The fixed-point function.
 * @param x0 Initial guess.
 * @param params Solver parameters (tolerance, max iterations).
 * @return Result<double> containing the fixed point and convergence info.
 */
inline common::Result<double> fixed_point_iteration(
    const std::function<double(double)>& g,
    double x0,
    SolverParams params = {}) {
    
    double x = x0;
    std::vector<double> errors;

    for (int i = 0; i < params.max_iterations; ++i) {
        double next_x = g(x);
        double error = common::ErrorMetrics::absolute_error(next_x, x);
        errors.push_back(error);

        x = next_x;

        if (error < params.tolerance) {
            return {x, common::Status::Success, i + 1, errors, "Converged"};
        }

        if (std::isnan(x) || std::isinf(x)) {
            return {x, common::Status::Diverged, i, errors, "Diverged to NaN or Inf."};
        }
    }

    return {x, common::Status::MaxIterationsReached, params.max_iterations, errors, "Maximum iterations reached"};
}

} // namespace nm::root_finding
