#pragma once

#include "numerical_methods/common/result.hpp"
#include <Eigen/Dense>
#include <vector>

namespace nm::linear_algebra {

/**
 * @brief Parameters for iterative linear solvers.
 */
struct IterativeParams {
    double tolerance = 1e-7;
    int max_iterations = 1000;
};

/**
 * @brief Solves Ax = b using the Jacobi Method.
 */
inline common::Result<Eigen::VectorXd> jacobi(
    const Eigen::MatrixXd& A,
    const Eigen::VectorXd& b,
    IterativeParams params = {}) {
    
    int n = static_cast<int>(A.rows());
    Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
    Eigen::VectorXd next_x(n);
    std::vector<double> errors;

    for (int k = 0; k < params.max_iterations; ++k) {
        for (int i = 0; i < n; ++i) {
            double sum = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    sum += A(i, j) * x(j);
                }
            }
            if (std::abs(A(i, i)) < 1e-12) {
                return {x, common::Status::Error, k, errors, "Zero diagonal element."};
            }
            next_x(i) = (b(i) - sum) / A(i, i);
        }

        double error = (next_x - x).norm();
        errors.push_back(error);
        x = next_x;

        if (error < params.tolerance) {
            return {x, common::Status::Success, k + 1, errors, "Converged"};
        }
    }

    return {x, common::Status::MaxIterationsReached, params.max_iterations, errors, "Max iterations reached"};
}

/**
 * @brief Solves Ax = b using the Gauss-Seidel Method.
 */
inline common::Result<Eigen::VectorXd> gauss_seidel(
    const Eigen::MatrixXd& A,
    const Eigen::VectorXd& b,
    IterativeParams params = {}) {
    
    int n = static_cast<int>(A.rows());
    Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
    std::vector<double> errors;

    for (int k = 0; k < params.max_iterations; ++k) {
        Eigen::VectorXd prev_x = x;
        for (int i = 0; i < n; ++i) {
            double sum = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    sum += A(i, j) * x(j);
                }
            }
            if (std::abs(A(i, i)) < 1e-12) {
                return {x, common::Status::Error, k, errors, "Zero diagonal element."};
            }
            x(i) = (b(i) - sum) / A(i, i);
        }

        double error = (x - prev_x).norm();
        errors.push_back(error);

        if (error < params.tolerance) {
            return {x, common::Status::Success, k + 1, errors, "Converged"};
        }
    }

    return {x, common::Status::MaxIterationsReached, params.max_iterations, errors, "Max iterations reached"};
}

} // namespace nm::linear_algebra
