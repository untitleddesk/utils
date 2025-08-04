add_executable(TestInstantiator vector.cc)
target_link_libraries(TestInstantiator untitledlogger untitledmath)
add_test(NAME TestInstantiator
         COMMAND TestInstantiator)