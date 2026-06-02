#include "numerical_methods/root_finding/bisection.hpp"
#include "numerical_methods/root_finding/newton_raphson.hpp"
#include <matplot/matplot.h>
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    using namespace nm::root_finding;
    namespace mp = matplot;

    // Function: f(x) = x^2 - 2 (root is sqrt(2) approx 1.414)
    auto f = [](double x) { return x * x - 2.0; };
    auto df = [](double x) { return 2.0 * x; };

    SolverParams params;
    params.tolerance = 1e-12;

    auto res_bis = bisection(f, 0.0, 2.0, params);
    auto res_nr = newton_raphson(f, df, 1.0, params);

    std::cout << "Bisection Root: " << res_bis.value << " (" << res_bis.iterations << " iterations)\n";
    std::cout << "Newton Root:    " << res_nr.value << " (" << res_nr.iterations << " iterations)\n";

    // Plotting convergence history
    auto fig = mp::figure(true);
    fig->size(800, 600);

    auto ax1 = mp::subplot(1, 1, 0);
    mp::semilogy(res_bis.errors, "-o")->name("Bisection");
    mp::hold(true);
    mp::semilogy(res_nr.errors, "-s")->name("Newton-Raphson");
    
    mp::title("Convergence History (f(x) = x^2 - 2)");
    mp::xlabel("Iteration");
    mp::ylabel("Absolute Error");
    mp::grid(true);
    mp::legend();

    mp::show();

    return 0;
}
