#pragma once

#include <vector>
#include <stdexcept>

namespace nm::interpolation {

/**
 * @brief Performs Lagrange Interpolation.
 * 
 * @param x_pts X coordinates of data points.
 * @param y_pts Y coordinates of data points.
 * @param x Target x value to interpolate.
 * @return Interpolated y value.
 */
inline double lagrange(const std::vector<double>& x_pts, const std::vector<double>& y_pts, double x) {
    if (x_pts.size() != y_pts.size() || x_pts.empty()) {
        throw std::invalid_argument("Invalid data points for Lagrange interpolation.");
    }

    int n = static_cast<int>(x_pts.size());
    double result = 0;

    for (int i = 0; i < n; ++i) {
        double term = y_pts[i];
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (std::abs(x_pts[i] - x_pts[j]) < 1e-15) {
                    throw std::runtime_error("Duplicate x coordinates in data points.");
                }
                term *= (x - x_pts[j]) / (x_pts[i] - x_pts[j]);
            }
        }
        result += term;
    }

    return result;
}

/**
 * @brief Newton Interpolation using divided differences.
 */
class NewtonInterpolator {
public:
    NewtonInterpolator(const std::vector<double>& x_pts, const std::vector<double>& y_pts)
        : x_pts_(x_pts) {
        
        int n = static_cast<int>(x_pts.size());
        coefs_ = y_pts;

        for (int j = 1; j < n; ++j) {
            for (int i = n - 1; i >= j; --i) {
                coefs_[i] = (coefs_[i] - coefs_[i - 1]) / (x_pts[i] - x_pts[i - j]);
            }
        }
    }

    double operator()(double x) const {
        int n = static_cast<int>(coefs_.size());
        double result = coefs_[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            result = coefs_[i] + (x - x_pts_[i]) * result;
        }
        return result;
    }

private:
    std::vector<double> x_pts_;
    std::vector<double> coefs_;
};

} // namespace nm::interpolation
