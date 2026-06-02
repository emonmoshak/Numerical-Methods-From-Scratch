#include <gtest/gtest.h>
#include "numerical_methods/root_finding/bisection.hpp"
#include "numerical_methods/root_finding/newton_raphson.hpp"
#include "numerical_methods/root_finding/secant.hpp"
#include "numerical_methods/root_finding/fixed_point_iteration.hpp"
#include <cmath>

using namespace nm::root_finding;

// Test function: f(x) = x^2 - 4, roots are 2 and -2
double f(double x) { return x * x - 4.0; }
double df(double x) { return 2.0 * x; }

// Fixed point function: g(x) = sqrt(x + 2) for f(x) = x^2 - x - 2 = 0, root is 2
double g(double x) { return std::sqrt(x + 2.0); }

TEST(RootFindingTest, Bisection) {
    auto result = bisection(f, 0.0, 5.0);
    EXPECT_TRUE(result.is_success());
    EXPECT_NEAR(result.value, 2.0, 1e-6);
}

TEST(RootFindingTest, NewtonRaphson) {
    auto result = newton_raphson(f, df, 1.0);
    EXPECT_TRUE(result.is_success());
    EXPECT_NEAR(result.value, 2.0, 1e-6);
}

TEST(RootFindingTest, Secant) {
    auto result = secant(f, 0.0, 1.0);
    EXPECT_TRUE(result.is_success());
    EXPECT_NEAR(result.value, 2.0, 1e-6);
}

TEST(RootFindingTest, FixedPointIteration) {
    auto result = fixed_point_iteration(g, 1.0);
    EXPECT_TRUE(result.is_success());
    EXPECT_NEAR(result.value, 2.0, 1e-6);
}

TEST(RootFindingTest, BisectionInvalidInput) {
    auto result = bisection(f, 3.0, 5.0);
    EXPECT_EQ(result.status, nm::common::Status::InvalidInput);
}
