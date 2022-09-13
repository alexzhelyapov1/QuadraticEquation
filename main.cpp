#include "lib/SolveQuadraticEquation.h"
#include "tests/test.h"

//----------------------------------------------------------------
//!  Program propose to user enter coefficient for Quadratic equation
//!  And program will solve it.
//----------------------------------------------------------------

int main () {
    if (TestSolveQuadratic (PUBLIC))
        return ERROR_IN_TESTS;
    double a = NAN, b = NAN, c = NAN;
    if (InputCoefficients (&a, &b, &c) != 3) //3 arguments must be read
        return FAILURE_READ_COEFFICIENTS;

    double root1 = NAN, root2 = NAN;
    enum number_of_roots nRoots = SolveQuadratic (a, b, c, &root1, &root2);
    PrintAnswer (nRoots, root1, root2);

    return OK;
}

