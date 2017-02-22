#include <fstream>
#include "Windows.h"

using namespace std;

const int n = 100;
const double a = 7, b = 20;
double my_func(double x);
void GaussianElimination(double matrix[n][n + 1], int m, double result[n]);
double Natural_Cubic_Spline(double x, double* A, double* C, double* D, double* B);
void SplineInterpolation(double* Ai, double* Bi, double* Ci, double* Di);