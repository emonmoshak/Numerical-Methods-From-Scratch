#pragma once

#include <vector>
#include <string>
#include <optional>

namespace nm::common {

/**
 * @brief Represents the status of a numerical computation.
 */
enum class Status {
    Success,
    MaxIterationsReached,
    Diverged,
    InvalidInput,
    Error
};

/**
 * @brief Encapsulates the result of a numerical method.
 * 
 * @tparam T The type of the numerical result (usually double or Eigen::VectorXd).
 */
template <typename T>
struct Result {
    T value;                    ///< The computed value.
    Status status;              ///< Computation status.
    int iterations;             ///< Number of iterations performed.
    std::vector<double> errors; ///< History of error metrics across iterations.
    std::string message;        ///< Optional descriptive message (e.g., error details).

    /**
     * @brief Checks if the computation was successful.
     */
    [[nodiscard]] bool is_success() const { return status == Status::Success; }
};

} // namespace nm::common
