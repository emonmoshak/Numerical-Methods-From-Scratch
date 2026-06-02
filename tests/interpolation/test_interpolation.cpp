#include <gtest/gtest.h>
#include "numerical_methods/interpolation/polynomial.hpp"
#include "numerical_methods/interpolation/cubic_spline.hpp"
#include <vector>

using namespace nm::interpolation;

TEST(InterpolationTest, Lagrange) {
    std::vector<double> x = {0, 1, 2};
    std::vector<double> y = {1, 2, 5}; // f(x) = x^2 + 1
    
    EXPECT_NEAR(lagrange(x, y, 0.5), 1.25, 1e-9);
    EXPECT_NEAR(lagrange(x, y, 1.5), 3.25, 1e-9);
}

TEST(InterpolationTest, Newton) {
    std::vector<double> x = {0, 1, 2};
    std::vector<double> y = {1, 2, 5};
    
    NewtonInterpolator ni(x, y);
    EXPECT_NEAR(ni(0.5), 1.25, 1e-9);
    EXPECT_NEAR(ni(1.5), 3.25, 1e-9);
}

TEST(InterpolationTest, CubicSpline) {
    std::vector<double> x = {0, 1, 2, 3};
    std::vector<double> y = {0, 1, 0, -1};
    
    CubicSpline cs(x, y);
    // At nodes
    EXPECT_NEAR(cs(0), 0, 1e-9);
    EXPECT_NEAR(cs(1), 1, 1e-9);
    EXPECT_NEAR(cs(2), 0, 1e-9);
    
    // Between nodes
    EXPECT_TRUE(cs(0.5) > 0);
    EXPECT_TRUE(cs(1.5) > 0);
}
