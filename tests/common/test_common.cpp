#include <gtest/gtest.h>
#include "numerical_methods/common/error_metrics.hpp"
#include "numerical_methods/common/result.hpp"

using namespace nm::common;

TEST(ErrorMetricsTest, AbsoluteError) {
    EXPECT_DOUBLE_EQ(ErrorMetrics::absolute_error(10.5, 10.0), 0.5);
    EXPECT_DOUBLE_EQ(ErrorMetrics::absolute_error(9.5, 10.0), 0.5);
}

TEST(ErrorMetricsTest, RelativeError) {
    EXPECT_DOUBLE_EQ(ErrorMetrics::relative_error(11.0, 10.0), 0.1);
    EXPECT_THROW(ErrorMetrics::relative_error(1.0, 0.0), std::domain_error);
}

TEST(ErrorMetricsTest, ApproximateRelativeError) {
    EXPECT_DOUBLE_EQ(ErrorMetrics::approximate_relative_error(100.0, 90.0), 0.1);
    // Near zero case
    EXPECT_DOUBLE_EQ(ErrorMetrics::approximate_relative_error(0.0, 0.1), 0.1);
}

TEST(ResultTest, SuccessStatus) {
    Result<double> res{1.23, Status::Success, 5, {0.1, 0.01}, "OK"};
    EXPECT_TRUE(res.is_success());
    EXPECT_DOUBLE_EQ(res.value, 1.23);
    EXPECT_EQ(res.iterations, 5);
}

TEST(ResultTest, FailureStatus) {
    Result<double> res{0.0, Status::Diverged, 100, {}, "Failed"};
    EXPECT_FALSE(res.is_success());
}
