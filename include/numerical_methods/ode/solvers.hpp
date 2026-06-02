#pragma once

#include <functional>
#include <vector>

namespace nm::ode {

/**
 * @brief Represents a state vector in an ODE.
 */
using State = double; // Can be extended to Eigen::VectorXd for systems

/**
 * @brief ODE system function: dy/dt = f(t, y)
 */
using SystemFunction = std::function<double(double, double)>;

/**
 * @brief Solves the ODE using the Euler Method.
 */
inline std::vector<std::pair<double, double>> euler(
    const SystemFunction& f, 
    double y0, 
    double t0, 
    double tf, 
    double h) {
    
    std::vector<std::pair<double, double>> result;
    double t = t0;
    double y = y0;
    result.push_back({t, y});

    while (t < tf) {
        if (t + h > tf) h = tf - t;
        y = y + h * f(t, y);
        t = t + h;
        result.push_back({t, y});
    }

    return result;
}

/**
 * @brief Solves the ODE using the Improved Euler Method (Heun's).
 */
inline std::vector<std::pair<double, double>> improved_euler(
    const SystemFunction& f, 
    double y0, 
    double t0, 
    double tf, 
    double h) {
    
    std::vector<std::pair<double, double>> result;
    double t = t0;
    double y = y0;
    result.push_back({t, y});

    while (t < tf) {
        if (t + h > tf) h = tf - t;
        double k1 = f(t, y);
        double y_pred = y + h * k1;
        double k2 = f(t + h, y_pred);
        y = y + 0.5 * h * (k1 + k2);
        t = t + h;
        result.push_back({t, y});
    }

    return result;
}

/**
 * @brief Solves the ODE using the Runge-Kutta 4 Method.
 */
inline std::vector<std::pair<double, double>> rk4(
    const SystemFunction& f, 
    double y0, 
    double t0, 
    double tf, 
    double h) {
    
    std::vector<std::pair<double, double>> result;
    double t = t0;
    double y = y0;
    result.push_back({t, y});

    while (t < tf) {
        if (t + h > tf) h = tf - t;
        double k1 = f(t, y);
        double k2 = f(t + 0.5 * h, y + 0.5 * h * k1);
        double k3 = f(t + 0.5 * h, y + 0.5 * h * k2);
        double k4 = f(t + h, y + h * k3);
        y = y + (h / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
        t = t + h;
        result.push_back({t, y});
    }

    return result;
}

} // namespace nm::ode
