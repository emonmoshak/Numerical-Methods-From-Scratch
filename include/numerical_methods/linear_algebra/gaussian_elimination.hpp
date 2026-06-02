#pragma once

#include <Eigen/Dense>
#include <stdexcept>

namespace nm::linear_algebra {

/**
 * @brief Solves Ax = b using Gaussian Elimination with Partial Pivoting.
 */
inline Eigen::VectorXd gaussian_elimination(Eigen::MatrixXd A, Eigen::VectorXd b) {
    int n = static_cast<int>(A.rows());
    if (n != A.cols() || n != b.size()) {
        throw std::invalid_argument("Matrix dimensions must be consistent and square.");
    }

    // Forward elimination with partial pivoting
    for (int i = 0; i < n; ++i) {
        // Pivot selection
        int max_row = i;
        double max_val = std::abs(A(i, i));
        for (int k = i + 1; k < n; ++k) {
            if (std::abs(A(k, i)) > max_val) {
                max_val = std::abs(A(k, i));
                max_row = k;
            }
        }

        // Swap rows in A and b
        A.row(i).swap(A.row(max_row));
        std::swap(b(i), b(max_row));

        if (std::abs(A(i, i)) < 1e-12) {
            throw std::runtime_error("Matrix is singular or near-singular.");
        }

        // Eliminate
        for (int k = i + 1; k < n; ++k) {
            double factor = A(k, i) / A(i, i);
            A.row(k) -= factor * A.row(i);
            b(k) -= factor * b(i);
        }
    }

    // Back substitution
    Eigen::VectorXd x(n);
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0;
        for (int k = i + 1; k < n; ++k) {
            sum += A(i, k) * x(k);
        }
        x(i) = (b(i) - sum) / A(i, i);
    }

    return x;
}

} // namespace nm::linear_algebra
