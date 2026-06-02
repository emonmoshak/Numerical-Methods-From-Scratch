add_executable(root_finding_example
    root_finding_example.cpp
)

target_link_libraries(root_finding_example
    PRIVATE
    ${PROJECT_NAME}
)
