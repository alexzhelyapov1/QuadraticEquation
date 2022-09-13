#ifndef SOLVEQUADRATICEQUATION_H_INCLUDED
#define SOLVEQUADRATICEQUATION_H_INCLUDED
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

enum Errors {
    OK = 0,
    ERROR_IN_TESTS,
    FAILURE_READ_COEFFICIENTS
};

enum number_of_roots{
    INFINITY_ROOTS = -1,    //!<  Const in case of Infinity number of roots
    NO_ROOTS = 0,               //!<  Const in case of No roots
    ONE_ROOT = 1,               //!<  Const in case of Single root
    TWO_ROOTS = 2               //!<  Const in case of two roots
};


const double EPSILON = 1e-100;      //!<  Accuracy of our calculations (gets by MathAnalysis)


int InputCoefficients (double* a, double* b, double* c);
enum number_of_roots SolveLinear (double b, double c, double* root1, double* root2);
enum number_of_roots SolveQuadratic (double a, double b, double c, double* root1, double* root2);
void PrintAnswer (enum number_of_roots nRoots, double root1, double root2);

bool IsEqual (double value, double compareValue);
bool IsZero (double value);

// TODO: While certainly being a better way of implementing tests than
//       compiling them right in your program, a much better alternative
//       would be creating a different .cpp file with it's own main
//       and running tests from there.


#endif // SOLVEQUADRATICEQUATION_H_INCLUDED
