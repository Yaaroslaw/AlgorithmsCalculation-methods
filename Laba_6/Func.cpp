#include "Header.h"

double my_func(double x) {
	return 0.2*log(abs(sin(x / 3)) / 3) + 1;
}


double Natural_Cubic_Spline(double x,double* A,double* C, double* D,double* B)
{
	double h = (b - a) / n;
	int i = 0;

	if ((x <= a) || (x > b))
		return 0;
	//Номер відрізку
	while (x > (a + i * h)) { ++i; }
	--i;

	double xi = a + i * h;

	//Значення сплайну в точці
	return A[i] + B[i] * (x - xi) + C[i] * (x - xi) * (x - xi) / 2 + D[i] * (x - xi) * (x - xi) * (x - xi) / 6;
}


void SplineInterpolation(double* Ai, double* Bi, double* Ci, double* Di) {
	
	ofstream fout("results.txt");
	int k = (b - a) * 250; //кількість точок, які обчислюються на заданому інтервалі
	double step = (b - a) / (double)k;
	double x, y;
	x = a;
	for (int i = 0; i <= k; ++i) {
		y = Natural_Cubic_Spline(x,Ai, Bi, Ci, Di);
		if (abs(x) < 10e-6) fout << 0;
		else fout << x;
		fout << " ; ";
		if (abs(y) < 10e-6) fout << 0;
		else fout << y;
		fout << endl;
		x += step;
	}
	fout.close();
	return;
}
//cхема єдиного поділу
void GaussianElimination(double matrix[n][n + 1], int m, double result[n]) {
	double x = matrix[m][m];
	for (int i = m; i < n + 1; i++)
		matrix[m][i] = matrix[m][i] / x;

	for (int i = m + 1; i < n; i++) {
		x = matrix[i][m];
		for (int j = m; j < n + 1; j++)
			matrix[i][j] -= matrix[m][j] * x;
	}

	if (m < n - 1)
		GaussianElimination(matrix, m + 1, result);
	result[m] = matrix[m][n];
	for (int j = m + 1; j < n; j++) {
		result[m] -= matrix[m][j] * result[j];
	}
}
