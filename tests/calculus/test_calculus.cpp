#include <gtest/gtest.h>
#include "numerical_methods/calculus/differentiation.hpp"
#include "numerical_methods/calculus/integration.hpp"
#include <cmath>

using namespace nm::calculus;

// f(x) = x^2, f'(x) = 2x, int f(x) = x^3 / 3
double f_quad(double x) { return x * x; }

TEST(CalculusTest, Differentiation) {
    double x = 2.0;
    double expected = 4.0;
    
    EXPECT_NEAR(forward_difference(f_quad, x), expected, 1e-4);
    EXPECT_NEAR(backward_difference(f_quad, x), expected, 1e-4);
    EXPECT_NEAR(central_difference(f_quad, x), expected, 1e-8);
}

TEST(CalculusTest, Integration) {
    double a = 0.0;
    double b = 1.0;
    double expected = 1.0 / 3.0;

    EXPECT_NEAR(trapezoidal_rule(f_quad, a, b, 1000), expected, 1e-6);
    EXPECT_NEAR(simpsons_rule(f_quad, a, b, 100), expected, 1e-8);
    EXPECT_NEAR(gaussian_quadrature_2pt(f_quad, a, b), expected, 1e-12);
}
