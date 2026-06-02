#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>

namespace nm::interpolation {

/**
 * @brief Natural Cubic Spline Interpolator.
 */
class CubicSpline {
public:
    CubicSpline(const std::vector<double>& x, const std::vector<double>& y)
        : x_(x) {
        
        if (x.size() != y.size() || x.size() < 3) {
            throw std::invalid_argument("At least 3 points are required for cubic spline interpolation.");
        }

        int n = static_cast<int>(x.size()) - 1;
        std::vector<double> h(n);
        for (int i = 0; i < n; ++i) {
            h[i] = x[i + 1] - x[i];
            if (h[i] <= 0) throw std::invalid_argument("x coordinates must be strictly increasing.");
        }

        std::vector<double> alpha(n);
        for (int i = 1; i < n; ++i) {
            alpha[i] = 3.0 / h[i] * (y[i + 1] - y[i]) - 3.0 / h[i - 1] * (y[i] - y[i - 1]);
        }

        std::vector<double> l(n + 1), mu(n + 1), z(n + 1);
        l[0] = 1.0;
        mu[0] = 0.0;
        z[0] = 0.0;

        for (int i = 1; i < n; ++i) {
            l[i] = 2.0 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
            mu[i] = h[i] / l[i];
            z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
        }

        l[n] = 1.0;
        z[n] = 0.0;
        c_.resize(n + 1);
        b_.resize(n);
        d_.resize(n);
        a_ = y;

        c_[n] = 0.0;
        for (int j = n - 1; j >= 0; --j) {
            c_[j] = z[j] - mu[j] * c_[j + 1];
            b_[j] = (a_[j + 1] - a_[j]) / h[j] - h[j] * (c_[j + 1] + 2.0 * c_[j]) / 3.0;
            d_[j] = (c_[j + 1] - c_[j]) / (3.0 * h[j]);
        }
    }

    double operator()(double x) const {
        auto it = std::lower_bound(x_.begin(), x_.end(), x);
        int i = std::distance(x_.begin(), it) - 1;
        i = std::clamp(i, 0, static_cast<int>(x_.size()) - 2);

        double dx = x - x_[i];
        return a_[i] + b_[i] * dx + c_[i] * dx * dx + d_[i] * dx * dx * dx;
    }

private:
    std::vector<double> x_;
    std::vector<double> a_, b_, c_, d_;
};

} // namespace nm::interpolation
