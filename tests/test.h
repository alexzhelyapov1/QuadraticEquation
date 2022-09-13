enum mode_of_testing {
    HIDDEN,
    PUBLIC
};

int TestSolveQuadratic (enum mode_of_testing mode); // Testing quadratic solve of equations
int CompareResultWithExpectation (int n_roots, double root1, double root2, struct test_values test_result_expected);