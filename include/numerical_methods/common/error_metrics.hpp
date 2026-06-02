#pragma once

#include <cmath>
#include <limits>
#include <stdexcept>

namespace nm::common {

/**
 * @brief Utility class for calculating numerical error metrics.
 */
class ErrorMetrics {
public:
    /**
     * @brief Calculates the absolute error between an approximation and the true value.
     * 
     * Formula: |approx - true_val|
     */
    static double absolute_error(double approx, double true_val) {
        return std::abs(approx - true_val);
    }

    /**
     * @brief Calculates the relative error between an approximation and the true value.
     * 
     * Formula: |(approx - true_val) / true_val|
     * @throws std::domain_error if true_val is zero.
     */
    static double relative_error(double approx, double true_val) {
        if (std::abs(true_val) < std::numeric_limits<double>::epsilon()) {
            throw std::domain_error("Relative error undefined for true value of zero.");
        }
        return std::abs((approx - true_val) / true_val);
    }

    /**
     * @brief Calculates the approximate relative error between current and previous iterations.
     * 
     * Formula: |(current - previous) / current|
     */
    static double approximate_relative_error(double current, double previous) {
        if (std::abs(current) < std::numeric_limits<double>::epsilon()) {
            return std::abs(current - previous); // Fallback to absolute if current is near zero
        }
        return std::abs((current - previous) / current);
    }
};

} // namespace nm::common
