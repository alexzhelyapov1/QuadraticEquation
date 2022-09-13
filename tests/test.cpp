#include "../lib/SolveQuadraticEquation.h"
#include "test.h"

//! Structure to keep tests for function TestSolveQuadratic()
    struct test_values {

        double a;           //!<  Coefficient of equation for x^2
        double b;           //!<  Coefficient of equation for x
        double c;           //!<  Coefficient of equation for free member
        int n_roots;         //!<  Number of roots
        double root1;       //!<  First solution of equation
        double root2;       //!<  Second solution of equation
    };

//----------------------------------------------------------------
//!  Testing program of the function "SolveQuadratic()"
//!  @copyright AlexZ
//----------------------------------------------------------------

int TestSolveQuadratic (enum mode_of_testing mode) {

    const int NTESTS = 5;
    test_values tests_array[NTESTS] =  {{1,  1, 1, NO_ROOTS,       0, 0},
                                        {0,  0, 0, INFINITY_ROOTS, 0, 0},
                                        {1,  2, 1, ONE_ROOT,      -1, 0},
                                        {1, -5, 6, TWO_ROOTS,      3, 2},
                                        {1, 0, 0,  ONE_ROOT,       0, 0}};

    double a = NAN, b = NAN, c = NAN;
    double root1 = NAN, root2 = NAN;

    printf ("\n-------------------------------------\nTests are going!\n");
    for (int number_of_test = 0; number_of_test < NTESTS; number_of_test++) {
        a = NAN; b = NAN; c = NAN; root1 = NAN; root2 = NAN;

        a = tests_array[number_of_test].a;
        b = tests_array[number_of_test].b;
        c = tests_array[number_of_test].c;
        int n_roots = SolveQuadratic (a, b, c, &root1, &root2);

        if (CompareResultWithExpectation (n_roots, root1, root2, tests_array[number_of_test])) {
            if (mode == PUBLIC) {
                printf ("Test %d, passed OK!\n", number_of_test + 1);
                continue;
            }
        }
        if (mode == PUBLIC) {
            printf ("Error in test %d!\n", number_of_test + 1);
            printf ("Input params: a = %lg, b = %lg, c = %lg\n", a, b, c);
            printf ("Expected values: number of roots = %d, root 1 = %lg, root 2 = %lg\n", 
                tests_array[number_of_test].n_roots, tests_array[number_of_test].root1, tests_array[number_of_test].root2);
            printf ("Returned values: number of roots = %d, root 1 = %lg, root 2 = %lg\n\n", 
                n_roots, root1, root2);
        }
        else
            return ERROR_IN_TESTS;

    }
    printf ("End of Tests!\n-------------------------------------\n\n");
    return OK;
}

int CompareResultWithExpectation (int n_roots, double root1, double root2, struct test_values test_result_expected) {

    if (n_roots == test_result_expected.n_roots) {
        if (n_roots == INFINITY_ROOTS || n_roots == NO_ROOTS) 
            return 1;
        if (n_roots == ONE_ROOT) {
            if (IsEqual(root1, test_result_expected.root1))
                return 1;
        }
        else if (IsEqual(root2, test_result_expected.root2))
            return 1;
    }
    return 0;
}