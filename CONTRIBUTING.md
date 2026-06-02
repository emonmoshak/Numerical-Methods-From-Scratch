# Contributing to Numerical Methods From Scratch

Thank you for your interest in contributing! This project aims for high mathematical rigor and clean C++20 engineering.

## Mathematical Standards

- All algorithms must be accompanied by a derivation in `docs/derivations/`.
- Use LaTeX for all mathematical notation.
- Documentation should include:
    - Formal problem statement.
    - Derivation from first principles.
    - Complexity and stability analysis.

## Coding Standards

- **Modern C++**: Use C++20 features (concepts, ranges, etc.) where appropriate.
- **RAII**: Manage all resources using RAII and smart pointers.
- **Naming**: Use `snake_case` for variables and functions, `PascalCase` for classes and structs.
- **Formatting**: Run `clang-format` before submitting.
- **Linting**: Ensure `clang-tidy` passes with no warnings.
- **Testing**: Every feature must have unit tests in the `tests/` directory.

## Development Workflow

1. Fork the repository.
2. Create a feature branch (`git checkout -b feature/your-feature`).
3. Implement your changes (code + tests + docs).
4. Run tests: `cmake --build build --target test`.
5. Commit your changes (`git commit -m "feat: add amazing feature"`).
6. Push to the branch (`git push origin feature/your-feature`).
7. Open a Pull Request.

## Environment Setup

```bash
mkdir build
cd build
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build .
```
