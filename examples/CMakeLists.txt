add_executable(root_finding_example
    root_finding_example.cpp
)

add_executable(generate_plots
    generate_plots.cpp
)

target_link_libraries(root_finding_example
    PRIVATE
    ${PROJECT_NAME}
)

target_link_libraries(generate_plots
    PRIVATE
    ${PROJECT_NAME}
)
