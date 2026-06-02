add_executable(unit_tests
    common/test_common.cpp
    root_finding/test_root_finding.cpp
    linear_algebra/test_linear_algebra.cpp
    interpolation/test_interpolation.cpp
    calculus/test_calculus.cpp
    ode/test_ode.cpp
)

target_link_libraries(unit_tests
    PRIVATE
    ${PROJECT_NAME}
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)
