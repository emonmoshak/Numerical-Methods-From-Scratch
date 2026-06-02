#include <gtest/gtest.h>
#include "numerical_methods/ode/solvers.hpp"
#include <cmath>

using namespace nm::ode;

// ODE: dy/dt = y, y(0) = 1. Solution: y(t) = e^t
double f_ode(double t, double y) { return y; }

TEST(ODETest, Euler) {
    auto res = euler(f_ode, 1.0, 0.0, 1.0, 0.01);
    EXPECT_NEAR(res.back().second, std::exp(1.0), 0.02);
}

TEST(ODETest, ImprovedEuler) {
    auto res = improved_euler(f_ode, 1.0, 0.0, 1.0, 0.01);
    EXPECT_NEAR(res.back().second, std::exp(1.0), 0.0002);
}

TEST(ODETest, RK4) {
    auto res = rk4(f_ode, 1.0, 0.0, 1.0, 0.1);
    EXPECT_NEAR(res.back().second, std::exp(1.0), 1e-5);
}
