#include "numerical_methods/root_finding/bisection.hpp"
#include "numerical_methods/root_finding/newton_raphson.hpp"
#include "numerical_methods/root_finding/secant.hpp"
#include "numerical_methods/ode/solvers.hpp"
#include "numerical_methods/calculus/integration.hpp"
#include "numerical_methods/linear_algebra/iterative_solvers.hpp"
#include <matplot/matplot.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <Eigen/Dense>

namespace mp = matplot;

void plot_root_finding() {
    using namespace nm::root_finding;
    auto f = [](double x) { return x * x - 2.0; };
    auto df = [](double x) { return 2.0 * x; };
    SolverParams params;
    params.tolerance = 1e-15;
    params.max_iterations = 50;

    auto res_bis = bisection(f, 0.0, 2.0, params);
    auto res_nr = newton_raphson(f, df, 1.0, params);
    auto res_sec = secant(f, 1.0, 2.0, params);

    auto fig = mp::figure(false);
    fig->size(800, 600);
    mp::semilogy(res_bis.errors, "-o")->display_name("Bisection (Linear)");
    mp::hold(true);
    mp::semilogy(res_nr.errors, "-s")->display_name("Newton-Raphson (Quadratic)");
    mp::semilogy(res_sec.errors, "-^")->display_name("Secant (Superlinear)");
    
    mp::title("Root Finding Convergence: f(x) = x^2 - 2");
    mp::xlabel("Iteration");
    mp::ylabel("Absolute Error");
    mp::grid(true);
    mp::legend();
    mp::save("assets/images/root_finding_convergence.png");
    std::cout << "Saved root_finding_convergence.png\n";
}

void plot_ode_comparison() {
    using namespace nm::ode;
    auto f = [](double t, double y) { return y; };
    double y0 = 1.0;
    double t0 = 0.0;
    double tf = 2.0;
    double h = 0.2;

    auto res_euler = euler(f, y0, t0, tf, h);
    auto res_imp_euler = improved_euler(f, y0, t0, tf, h);
    auto res_rk4 = rk4(f, y0, t0, tf, h);

    std::vector<double> t_exact = mp::linspace(0, 2, 100);
    std::vector<double> y_exact(t_exact.size());
    for(size_t i=0; i<t_exact.size(); ++i) y_exact[i] = std::exp(t_exact[i]);

    std::vector<double> t_e, y_e, t_ie, y_ie, t_rk, y_rk;
    for(auto p : res_euler) { t_e.push_back(p.first); y_e.push_back(p.second); }
    for(auto p : res_imp_euler) { t_ie.push_back(p.first); y_ie.push_back(p.second); }
    for(auto p : res_rk4) { t_rk.push_back(p.first); y_rk.push_back(p.second); }

    auto fig = mp::figure(false);
    fig->size(800, 600);
    mp::plot(t_exact, y_exact, "k--")->display_name("Analytical (exp(t))");
    mp::hold(true);
    mp::plot(t_e, y_e, "-o")->display_name("Euler (O(h))");
    mp::plot(t_ie, y_ie, "-s")->display_name("Improved Euler (O(h^2))");
    mp::plot(t_rk, y_rk, "-^")->display_name("RK4 (O(h^4))");

    mp::title("ODE Solver Comparison: dy/dt = y, y(0) = 1");
    mp::xlabel("Time (t)");
    mp::ylabel("Solution (y)");
    mp::grid(true);
    mp::legend();
    mp::save("assets/images/ode_comparison.png");
    std::cout << "Saved ode_comparison.png\n";
}

void plot_integration_accuracy() {
    using namespace nm::calculus;
    auto f = [](double x) { return std::sin(x); };
    double a = 0.0;
    double b = M_PI;
    double exact = 2.0;

    std::vector<double> n_vals = {2, 4, 8, 16, 32, 64, 128, 256};
    std::vector<double> err_trap, err_simp;

    for(double n : n_vals) {
        err_trap.push_back(std::abs(trapezoidal_rule(f, a, b, (int)n) - exact));
        err_simp.push_back(std::abs(simpsons_rule(f, a, b, (int)n) - exact));
    }

    auto fig = mp::figure(false);
    fig->size(800, 600);
    mp::loglog(n_vals, err_trap, "-o")->display_name("Trapezoidal Rule");
    mp::hold(true);
    mp::loglog(n_vals, err_simp, "-s")->display_name("Simpson's Rule");
    
    // Gaussian 2-point is constant here as it doesn't depend on n in our current impl
    double err_gauss = std::abs(gaussian_quadrature_2pt(f, a, b) - exact);
    std::vector<double> gauss_line(n_vals.size(), err_gauss);
    mp::loglog(n_vals, gauss_line, "k--")->display_name("Gaussian 2-pt (Fixed)");

    mp::title("Integration Accuracy: sin(x) on [0, pi]");
    mp::xlabel("Number of Intervals (n)");
    mp::ylabel("Absolute Error");
    mp::grid(true);
    mp::legend();
    mp::save("assets/images/integration_accuracy.png");
    std::cout << "Saved integration_accuracy.png\n";
}

void plot_linear_solver_accuracy() {
    using namespace nm::linear_algebra;
    int n = 10;
    Eigen::MatrixXd A = Eigen::MatrixXd::Identity(n, n) * 5.0 + Eigen::MatrixXd::Random(n, n);
    Eigen::VectorXd b = Eigen::VectorXd::Random(n);

    IterativeParams params;
    params.max_iterations = 50;
    params.tolerance = 1e-15;

    auto res_jacobi = jacobi(A, b, params);
    auto res_gs = gauss_seidel(A, b, params);

    auto fig = mp::figure(false);
    fig->size(800, 600);
    mp::semilogy(res_jacobi.errors, "-o")->display_name("Jacobi");
    mp::hold(true);
    mp::semilogy(res_gs.errors, "-s")->display_name("Gauss-Seidel");

    mp::title("Linear Solver Convergence: 10x10 Diagonally Dominant System");
    mp::xlabel("Iteration");
    mp::ylabel("Residual Norm ||Ax - b||");
    mp::grid(true);
    mp::legend();
    mp::save("assets/images/linear_solver_convergence.png");
    std::cout << "Saved linear_solver_convergence.png\n";
}

int main() {
    try {
        plot_root_finding();
        plot_ode_comparison();
        plot_integration_accuracy();
        plot_linear_solver_accuracy();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
