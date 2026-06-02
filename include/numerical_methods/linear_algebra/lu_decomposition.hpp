#pragma once

#include <Eigen/Dense>
#include <stdexcept>
#include <vector>

namespace nm::linear_algebra {

/**
 * @brief LU Decomposition of a square matrix.
 * 
 * Factors A = LU using Doolittle's algorithm.
 */
struct LUFactorization {
    Eigen::MatrixXd L;
    Eigen::MatrixXd U;

    /**
     * @brief Solves Ax = b using the LU factors.
     */
    Eigen::VectorXd solve(const Eigen::VectorXd& b) const {
        int n = static_cast<int>(L.rows());
        Eigen::VectorXd y(n);
        Eigen::VectorXd x(n);

        // Forward substitution: Ly = b
        for (int i = 0; i < n; ++i) {
            double sum = 0;
            for (int k = 0; k < i; ++k) {
                sum += L(i, k) * y(k);
            }
            y(i) = b(i) - sum;
        }

        // Backward substitution: Ux = y
        for (int i = n - 1; i >= 0; --i) {
            double sum = 0;
            for (int k = i + 1; k < n; ++k) {
                sum += U(i, k) * x(k);
            }
            if (std::abs(U(i, i)) < 1e-12) {
                throw std::runtime_error("Matrix is singular or near-singular.");
            }
            x(i) = (y(i) - sum) / U(i, i);
        }

        return x;
    }
};

/**
 * @brief Performs LU Decomposition on matrix A.
 */
inline LUFactorization lu_decompose(const Eigen::MatrixXd& A) {
    if (A.rows() != A.cols()) {
        throw std::invalid_argument("Matrix must be square for LU decomposition.");
    }

    int n = static_cast<int>(A.rows());
    Eigen::MatrixXd L = Eigen::MatrixXd::Identity(n, n);
    Eigen::MatrixXd U = Eigen::MatrixXd::Zero(n, n);

    for (int i = 0; i < n; ++i) {
        // Upper triangular matrix U
        for (int j = i; j < n; ++j) {
            double sum = 0;
            for (int k = 0; k < i; ++k) {
                sum += L(i, k) * U(k, j);
            }
            U(i, j) = A(i, j) - sum;
        }

        // Lower triangular matrix L
        for (int j = i + 1; j < n; ++j) {
            double sum = 0;
            for (int k = 0; k < i; ++k) {
                sum += L(j, k) * U(k, i);
            }
            if (std::abs(U(i, i)) < 1e-12) {
                throw std::runtime_error("Zero pivot encountered. LU decomposition without pivoting failed.");
            }
            L(j, i) = (A(j, i) - sum) / U(i, i);
        }
    }

    return {L, U};
}

} // namespace nm::linear_algebra
