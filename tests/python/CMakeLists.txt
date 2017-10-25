CONFIGURE_FILE("run_tests.py.in"  "run_tests.py")
ADD_TEST(NAME test_python COMMAND ${PYTHON_EXECUTABLE} run_tests.py)
