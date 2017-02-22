#include "Header.h"


int main() {
	double matrix[n][n + 1];
	double x = a, xi, h = (b - a) / n;
	double Ai[n + 1], Ci[n + 1], Bi[n + 1], Di[n + 1];
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= n; j++)
			matrix[i][j] = 0;
	for (int i = 0; i <= n; i++) {
		Ai[i] = my_func(x);
		x += h;
	}
	x = a;
	matrix[0][0] = 4 * h;
	matrix[0][1] = h;
	matrix[0][n] = 6 * ((my_func(x + h) - my_func(x)) / h - (my_func(x) - my_func(x - h)) / h);
	for (int i = 1; i < n - 1; i++) {
		matrix[i][i - 1] = h;
		matrix[i][i] = 4 * h;
		matrix[i][i + 1] = h;
		matrix[i][n] = 6 * ((my_func(x + h) - my_func(x)) / h - (my_func(x) - my_func(x - h)) / h);
		x += h;

	}
	matrix[n - 1][n - 2] = h;
	matrix[n - 1][n - 1] = 4 * h;
	matrix[n - 1][n] = 6 * ((my_func(x + h) - my_func(x)) / h - (my_func(x) - my_func(x - h)) / h);
	GaussianElimination(matrix, 0, Ci);
	Ci[n]=Ci[0]=0;
	x = a;
	for (int i = 1; i <= n; i++) {
		Di[i] = (Ci[i] - Ci[i - 1]) / h;
		Bi[i] = h*Ci[i] / 2 - h*h*Di[i] / 6 + (my_func(x) - my_func(x - h)) / h;
		SplineInterpolation(Ai, Bi, Ci, Di);
		x += h;
	}
	system("pause");
}