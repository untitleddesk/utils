add_executable(log-test test.cc)
target_link_libraries(log-test log)

enable_testing()
add_test(NAME log-test COMMAND log-test)