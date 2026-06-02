#pragma once

#include "numerical_methods/common/result.hpp"
#include <Eigen/Dense>
#include <stdexcept>

namespace nm::linear_algebra {

/**
 * @brief Calculates the determinant of a square matrix using LU decomposition.
 */
inline double determinant(const Eigen::MatrixXd& A) {
    if (A.rows() != A.cols()) {
        throw std::invalid_argument("Matrix must be square to calculate determinant.");
    }

    int n = static_cast<int>(A.rows());
    Eigen::MatrixXd tempA = A;
    double det = 1.0;

    // Gaussian elimination to upper triangular form
    for (int i = 0; i < n; ++i) {
        int pivot = i;
        for (int j = i + 1; j < n; ++j) {
            if (std::abs(tempA(j, i)) > std::abs(tempA(pivot, i))) {
                pivot = j;
            }
        }

        if (pivot != i) {
            tempA.row(i).swap(tempA.row(pivot));
            det *= -1.0;
        }

        if (std::abs(tempA(i, i)) < 1e-12) return 0.0;

        for (int j = i + 1; j < n; ++j) {
            double factor = tempA(j, i) / tempA(i, i);
            tempA.row(j) -= factor * tempA.row(i);
        }
        det *= tempA(i, i);
    }

    return det;
}

/**
 * @brief Calculates the inverse of a square matrix using Gaussian elimination.
 */
inline Eigen::MatrixXd inverse(const Eigen::MatrixXd& A) {
    if (A.rows() != A.cols()) {
        throw std::invalid_argument("Matrix must be square to calculate inverse.");
    }

    int n = static_cast<int>(A.rows());
    Eigen::MatrixXd aug = Eigen::MatrixXd::Zero(n, 2 * n);
    aug.leftCols(n) = A;
    aug.rightCols(n) = Eigen::MatrixXd::Identity(n, n);

    for (int i = 0; i < n; ++i) {
        int pivot = i;
        for (int j = i + 1; j < n; ++j) {
            if (std::abs(aug(j, i)) > std::abs(aug(pivot, i))) {
                pivot = j;
            }
        }
        aug.row(i).swap(aug.row(pivot));

        if (std::abs(aug(i, i)) < 1e-12) {
            throw std::runtime_error("Matrix is singular and cannot be inverted.");
        }

        aug.row(i) /= aug(i, i);
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                aug.row(j) -= aug(j, i) * aug.row(i);
            }
        }
    }

    return aug.rightCols(n);
}

/**
 * @brief Approximates the dominant eigenvalue and eigenvector using Power Iteration.
 */
inline common::Result<std::pair<double, Eigen::VectorXd>> power_iteration(
    const Eigen::MatrixXd& A,
    int max_iterations = 1000,
    double tolerance = 1e-9) {
    
    int n = static_cast<int>(A.rows());
    Eigen::VectorXd b = Eigen::VectorXd::Random(n);
    b.normalize();
    double mu = 0;
    std::vector<double> errors;

    for (int k = 0; k < max_iterations; ++k) {
        Eigen::VectorXd b_next = A * b;
        double mu_next = b.dot(b_next); // Rayleigh quotient
        b_next.normalize();

        double error = std::abs(mu_next - mu);
        errors.push_back(error);

        mu = mu_next;
        b = b_next;

        if (error < tolerance) {
            return {{mu, b}, common::Status::Success, k + 1, errors, "Converged"};
        }
    }

    return {{mu, b}, common::Status::MaxIterationsReached, max_iterations, errors, "Max iterations reached"};
}

} // namespace nm::linear_algebra
