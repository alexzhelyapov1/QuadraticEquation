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

enum number_of_roots SolveQuadratic (double a, double b, double c, double* root1, double* root2) {

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
        return SolveLinear(2*a, b, root1, root2);
    }
    *root1 = (-b + sqrt (discriminant)) / (2*a);
    *root2 = (-b - sqrt (discriminant)) / (2*a);
    return TWO_ROOTS;
}

//----------------------------------------------------------------
//!  Compare two double numbers
//!  @param [in] value - first number
//!  @param [in] compare_value - second number
//!  @return Is this two numbers equal?
//----------------------------------------------------------------

bool IsEqual (double value, double compare_value) {
    // printf ("\nHELOOOOO %lg %lg\n", value, compare_value);

    assert (!isnan (value));
    assert (!isnan (compare_value));

    return (fabs (value - compare_value) < EPSILON);
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

enum number_of_roots SolveLinear (double a, double b, double* root1, double* root2){

    assert (!isnan (a));
    assert (!isnan (b));

    if (IsZero (a)) {
        if (IsZero (b)) {
            return INFINITY_ROOTS;
        }
        return NO_ROOTS;
    }
    *root1 = -b/a;
    return ONE_ROOT;
}


//----------------------------------------------------------------
//!  Program printing answer of equation
//!  @param  [in]   nRoots - number of roots
//!  @param  [in]   root1 - first root of equation
//!  @param  [in]   root2 - second root of equation
//----------------------------------------------------------------

void PrintAnswer (number_of_roots nRoots, double root1, double root2) {
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

int InputCoefficients (double* a, double* b, double* c) {
    assert (a);
    assert (b);
    assert (c);

    printf ("# Please enter coefficient of equation (a, b, c)\n");
    int number_of_read = scanf ("%lg %lg %lg", a, b, c);

    int countOfTry = 1;
    if (number_of_read != 3) {
        while (countOfTry < 5) {
            printf ("Wrong coefficient!\nTry again!\n");
            if ((number_of_read = scanf ("%lg %lg %lg", a, b, c)) == 3)
                return number_of_read;
            countOfTry++;
        }
        printf ("You're tired, go to sleep!!!");
        number_of_read = 0; //nothing read
    }
    return number_of_read;
}
