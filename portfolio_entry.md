# Numerical Methods From Scratch: A C++20 Engineering Showcase

**Overview:**
This project is a professional scientific computing library built from first principles to solve complex problems in mechatronics and robotics. By implementing core numerical analysis algorithms without high-level black-box dependencies, I demonstrate a deep understanding of mathematical stability, error propagation, and computational efficiency. The library provides robust solutions for non-linear equations, linear systems, and differential equations, all encapsulated within a modern C++ architecture.

**Engineering Highlights:**
*   **Rigorous Verification:** I developed a custom `Result<T>` pattern that exposes internal convergence history. This enabled empirical validation of theoretical convergence rates—such as the quadratic convergence of the Newton-Raphson method—ensuring the "physics" of the code matches the mathematics.
*   **Modern C++ Design:** The library leverages C++20 templates and RAII to ensure zero-cost abstractions and memory safety. By utilizing the Eigen library for linear algebra primitives, the solver remains performant while maintaining high-level mathematical expressiveness.
*   **Applied Mathematics:** I successfully mapped theoretical derivations—including the Intermediate Value Theorem, Taylor Series expansions, and Runge-Kutta theory—to production-grade code. This bridge between abstract theory and concrete implementation is essential for high-integrity engineering systems.

**Lessons Learned:**
The primary takeaway from this project was the realization that in engineering, **Numerical Stability often trumps raw Speed**. A slow-converging but unconditionally stable method like Bisection is often more valuable than a fast but sensitive method like Newton-Raphson when dealing with real-world, noisy data. Additionally, the project reinforced the importance of automated verification; with 25 precision unit tests and integrated plotting, I can guarantee the reliability of every solver across different problem scales.

**Outcome:**
The repository serves as a validated toolkit for engineering computation, backed by a 20-page technical report and a 100% pass rate on high-precision unit tests. It stands as a testament to my ability to engineer complex mathematical systems with professional polish and rigorous validation.
