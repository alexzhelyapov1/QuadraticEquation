#include "SolveQuadraticEquation.h"

//! Structure to keep tests for function TestSolveQuadratic()
    struct test_values {

        double a;           //!<  Coefficient of equation for x^2
        double b;           //!<  Coefficient of equation for x
        double c;           //!<  Coefficient of equation for free member
        int nRoots;         //!<  Number of roots
        double root1;       //!<  First solution of equation
        double root2;       //!<  Second solution of equation
    };
int TestSolveQuadratic ();



int main () {
    if (!TestSolveQuadratic ())
    return ERROR_IN_TESTS;
}



//----------------------------------------------------------------
//!  Testing program of the function "SolveQuadratic()"
//!  @copyright AlexZ
//----------------------------------------------------------------

int TestSolveQuadratic () {

    const int NTESTS = 4;
    test_values arrayOfTests[NTESTS] =  {{1,  1, 1, NO_ROOTS,       0, 0},
                                        {0,  0, 0, INFINITY_ROOTS, 0, 0},
                                        {1,  2, 1, ONE_ROOT,      -1, 0},
                                        {1, -5, 6, TWO_ROOTS,      3, 2}};

    double a = NAN, b = NAN, c = NAN;
    double root1 = NAN, root2 = NAN;

    printf ("\n-------------------------------------\nTests are going!\n");
    for (int numberOfTest = 0; numberOfTest < NTESTS; numberOfTest++) {
        a = NAN; b = NAN; c = NAN; root1 = NAN; root2 = NAN;

        a = arrayOfTests[numberOfTest].a;
        b = arrayOfTests[numberOfTest].b;
        c = arrayOfTests[numberOfTest].c;
        int nRoots = SolveQuadratic (a, b, c, &root1, &root2);

        if (nRoots == arrayOfTests[numberOfTest].nRoots) {
            if (nRoots == INFINITY_ROOTS && nRoots == NO_ROOTS) 
                continue;
            if (nRoots == ONE_ROOT && IsEqual(root1, arrayOfTests[numberOfTest].root1))
                continue;
            if (IsEqual(root2, arrayOfTests[numberOfTest].root2))
                continue;
            }
        printf ("Error Test %d!\n", numberOfTest + 1);
    }
    printf ("End of Tests!\n-------------------------------------\n\n");
    return OK;
}