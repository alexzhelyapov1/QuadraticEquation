#include "SolveQuadraticEquation.h"

//----------------------------------------------------------------
//!  Solve quadratic equation of form a*x^2 + b*x + c = 0
//
//!  @param  [in]   a - coefficient
//!  @param  [in]   b - coefficient
//!  @param  [in]   c - coefficient
//!  @param  [out]   root1 - pointer to the 1st root
//!  @param  [out]   root2 - pointer to the 2nd root
//!  @return Number of roots
//!  @note In case of infinite number of roots program returns INFINITY_ROOTS
//!  @copyright AlexZ (Idea of Ded;))
//----------------------------------------------------------------

int SolveQuadratic (double a, double b, double c, double* root1, double* root2) {

    assert (!isnan (a));
    assert (!isnan (b));
    assert (!isnan (c));
    assert (root1 != NULL);
    assert (root2 != NULL);
    assert (root1 != root2);

    if (IsZero (a))
        return SolveLinear (b, c, root1, root2);
    double discriminant = pow (b, 2.0) - 4*a*c;

    if (discriminant < 0)
        return NO_ROOTS;
    if (IsZero (discriminant)) {
        *root1 = SolveLinear(2*a, b, root1, root2);
        printf ("%g*x^2 + %g*x + %g\nRoot 1 = %g, root 2 = %g\n", a, b, c, *root1, *root2);
        return ONE_ROOT;
    }
    *root1 = (-b + sqrt (discriminant)) / (2*a);
    *root2 = (-b - sqrt (discriminant)) / (2*a);
    return TWO_ROOTS;
    // printf ("%g*x^2 + %g*x + %g\nRoot 1 = %g, root 2 = %g\n", a, b, c, *root1, *root2);
}

//----------------------------------------------------------------
//!  Compare two double numbers
//!  @param [in] value - first number
//!  @param [in] compareValue - second number
//!  @return Is this two numbers equal?
//----------------------------------------------------------------

bool IsEqual (double value, double compareValue) {

    assert (!isnan (value));
    assert (!isnan (compareValue));

    return (fabs (value - compareValue) < EPSILON);
}

bool IsZero (double value) {
    assert (!isnan (value));

    return (fabs (value - 0.0) < EPSILON);
}

//----------------------------------------------------------------
//!  Program solve linear equation b * x + c = 0
//!  Program solve Quadratic equation a*x^2 + b*x + c = 0
//!  @param  [in]   b - coefficient
//   TODO: undocumented parameter
//!  @return Decision of equation
//!  @note Decision must exist!
//----------------------------------------------------------------

int SolveLinear (double b, double c, double* root1, double* root2){

    assert (!isnan (b));
    assert (!isnan (c));

    if (IsZero (b)) {
        if (IsZero (c)) {
            return INFINITY_ROOTS;
        }
        return NO_ROOTS;
    }
    *root1 = -c/b;
    return ONE_ROOT;
}


//----------------------------------------------------------------
//!  Program printing answer of equation
//!  @param  [in]   nRoots - number of roots
//!  @param  [in]   root1 - first root of equation
//!  @param  [in]   root2 - second root of equation
//----------------------------------------------------------------

void OutputAnswer (Number_of_roots nRoots, double root1, double root2) {
    assert (nRoots <= TWO_ROOTS && nRoots >= NO_ROOTS);

    switch (nRoots){
        case NO_ROOTS:
            printf ("No roots");
            break;
        case ONE_ROOT:
            printf ("x = %lg", root1);
            break;
        case TWO_ROOTS:
            printf ("x1 = %lg\nx2 = %lg", root1, root2);
            break;
        case INFINITY_ROOTS:
            printf ("Any roots!");
            break;
    }
}


//----------------------------------------------------------------
//!  Program gets values of variables
//!  @param  [out]   a - pointer to the "a" coefficient
//!  @param  [out]   b - pointer to the "b" coefficient
//!  @param  [out]   c - pointer to the "c" coefficient
//!  @note You have only 5 attempts to enter coefficients! \n Or you will go to sleep (maybe this isn't a threat:))
//----------------------------------------------------------------

int InputCoefficient (double* a, double* b, double* c) {
    assert (a != 0);
    assert (b != 0);
    assert (c != 0);

    printf ("# Please enter coefficient of equation (a, b, c)\n");
    int numberOfRead = scanf ("%lg %lg %lg", a, b, c);

    int countOfTry = 1;
    if (numberOfRead != 3) {
        while (countOfTry < 5) {
            fflush(stdin);
            printf ("Wrong coefficient!\nTry again!\n");
            if ((numberOfRead = scanf ("%lg %lg %lg", a, b, c)) == 3)
                return numberOfRead;
            countOfTry++;
        }
    }
    printf ("You're tired, go to sleep!!!");
    numberOfRead = 0; //nothing read
    return numberOfRead;
}


//----------------------------------------------------------------
//!  Testing program of the function "SolveQuadratic()"
//!  Tests already set!
//   ^~~~~~~~~~~~~~~~~ TODO: What does it mean?
//!  @copyright AlexZ
//----------------------------------------------------------------


#ifdef DEBUG

int TestSolveQuadratic () {

    // TODO: What is the reason to define test_values structure locally?
    //       I think making it top-level in appropriate header (e.g. equation-solver-test.h)
    //       would add a lot of possibilities for splitting this in more functions.  

    //! Structure to keep tests for function TestSolveQuadratic()
    struct test_values {

        double a;           //!<  Coefficient of equation for x^2
        double b;           //!<  Coefficient of equation for x
        double c;           //!<  Coefficient of equation for free member
        int nRoots;         //!<  Number of roots
        double root1;       //!<  First solution of equation
        double root2;       //!<  Second solution of equation
    };

    const int NTESTS = 4;
    test_values arrayOfTests[NTESTS] =  {{1,  1, 1, NO_ROOTS,       0, 0},
                                        {0,  0, 0, INFINITY_ROOTS, 0, 0},
                                        {1,  2, 1, ONE_ROOT,      -1, 0},
                                        {1, -5, 6, TWO_ROOTS,      3, 2}};

    double a = NAN, b = NAN, c = NAN;
    double root1 = NAN, root2 = NAN;

    printf ("\n-------------------------------------\nTests are going!\n");
    for (int numberOfTest = 0; numberOfTest < NTESTS; numberOfTest++) {

        a = arrayOfTests[numberOfTest].a;
        b = arrayOfTests[numberOfTest].b;
        c = arrayOfTests[numberOfTest].c;
        int nRoots = SolveQuadratic (a, b, c, &root1, &root2);

        if (nRoots != arrayOfTests[numberOfTest].nRoots) {
            PrintErrOfTest (numberOfTest);
        }
        else if (nRoots != INFINITY_ROOTS && nRoots != NO_ROOTS) {
            if (!IsEqual(root1, arrayOfTests[numberOfTest].root1)) {
                PrintErrOfTest (numberOfTest);
            }

            else if (nRoots != ONE_ROOT) {
                if (!IsEqual(root2, arrayOfTests[numberOfTest].root2)) {
                    PrintErrOfTest (numberOfTest);
                }
            }
        }
        a = NAN; b = NAN; c = NAN; root1 = NAN; root2 = NAN;
    }
    printf ("End of Tests!\n-------------------------------------\n\n");
    return OK;
}

#endif


//----------------------------------------------------------------
//!  Print "Error!" and number of test in case of failed
//!  @param [in] numberOfTest - coefficient
//----------------------------------------------------------------

void PrintErrOfTest (int numberOfTest) {
    printf ("Error Test %d!\n", numberOfTest + 1);
}
