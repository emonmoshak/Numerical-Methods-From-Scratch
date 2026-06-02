#include <gtest/gtest.h>
#include "numerical_methods/linear_algebra/lu_decomposition.hpp"
#include "numerical_methods/linear_algebra/gaussian_elimination.hpp"
#include "numerical_methods/linear_algebra/iterative_solvers.hpp"
#include "numerical_methods/linear_algebra/matrix_utils.hpp"
#include <Eigen/Dense>

using namespace nm::linear_algebra;

TEST(LinearAlgebraTest, LUDecomposition) {
    Eigen::MatrixXd A(3, 3);
    A << 2, -1, -2,
         -4, 6, 3,
         -4, -2, 8;
    
    Eigen::VectorXd b(3);
    b << -1, 5, 2;

    auto lu = lu_decompose(A);
    Eigen::VectorXd x = lu.solve(b);

    EXPECT_NEAR(x(0), 1.0, 1e-9);
    EXPECT_NEAR(x(1), 1.0, 1e-9);
    EXPECT_NEAR(x(2), 1.0, 1e-9);
}

TEST(LinearAlgebraTest, GaussianElimination) {
    Eigen::MatrixXd A(3, 3);
    A << 1, 2, 3,
         4, 5, 6,
         7, 8, 10;
    
    Eigen::VectorXd b(3);
    b << 6, 15, 25;

    Eigen::VectorXd x = gaussian_elimination(A, b);

    EXPECT_NEAR(x(0), 1.0, 1e-9);
    EXPECT_NEAR(x(1), 1.0, 1e-9);
    EXPECT_NEAR(x(2), 1.0, 1e-9);
}

TEST(LinearAlgebraTest, Jacobi) {
    Eigen::MatrixXd A(3, 3);
    A << 5, -2, 3,
         -3, 9, 1,
         2, -1, -7;
    
    Eigen::VectorXd b(3);
    b << -1, 2, 3;

    auto result = jacobi(A, b);
    EXPECT_TRUE(result.is_success());
    
    Eigen::VectorXd expected = A.colPivHouseholderQr().solve(b);
    for (int i = 0; i < 3; ++i) {
        EXPECT_NEAR(result.value(i), expected(i), 1e-6);
    }
}

TEST(LinearAlgebraTest, GaussSeidel) {
    Eigen::MatrixXd A(3, 3);
    A << 5, -2, 3,
         -3, 9, 1,
         2, -1, -7;
    
    Eigen::VectorXd b(3);
    b << -1, 2, 3;

    auto result = gauss_seidel(A, b);
    EXPECT_TRUE(result.is_success());
    
    Eigen::VectorXd expected = A.colPivHouseholderQr().solve(b);
    for (int i = 0; i < 3; ++i) {
        EXPECT_NEAR(result.value(i), expected(i), 1e-6);
    }
}

TEST(LinearAlgebraTest, Determinant) {
    Eigen::MatrixXd A(3, 3);
    A << 1, 2, 3,
         4, 5, 6,
         7, 8, 9;
    EXPECT_NEAR(determinant(A), 0.0, 1e-9);

    A(2, 2) = 10;
    EXPECT_NEAR(determinant(A), -3.0, 1e-9);
}

TEST(LinearAlgebraTest, Inverse) {
    Eigen::MatrixXd A(2, 2);
    A << 4, 7,
         2, 6;
    
    Eigen::MatrixXd inv = inverse(A);
    Eigen::MatrixXd I = A * inv;

    EXPECT_NEAR(I(0, 0), 1.0, 1e-9);
    EXPECT_NEAR(I(0, 1), 0.0, 1e-9);
    EXPECT_NEAR(I(1, 0), 0.0, 1e-9);
    EXPECT_NEAR(I(1, 1), 1.0, 1e-9);
}

TEST(LinearAlgebraTest, PowerIteration) {
    Eigen::MatrixXd A(2, 2);
    A << 2, 1,
         1, 2;
    // Eigenvalues are 3 and 1. Dominant is 3.
    auto result = power_iteration(A);
    EXPECT_TRUE(result.is_success());
    EXPECT_NEAR(result.value.first, 3.0, 1e-6);
}
