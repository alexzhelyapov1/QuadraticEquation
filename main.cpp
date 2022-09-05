#include "SolveQuadraticEquation.h"


//----------------------------------------------------------------
//!  Program propose to user enter coefficient for Quadratic equation
//!  And program will solve it.
//----------------------------------------------------------------

int main () {

#ifdef DEBUG
    if (!TestSolveQuadratic ())
        return ERROR_IN_TESTS;

#else
    double a = NAN, b = NAN, c = NAN;
    if (InputCoefficient (&a, &b, &c) != 3) //3 arguments must be read
        return FAILURE_READ_COEFFICIENTS;

    double root1 = NAN, root2 = NAN;
    int nRoots = SolveQuadratic (a, b, c, &root1, &root2);
    OutputAnswer (nRoots, root1, root2);
#endif

    return OK;
}

