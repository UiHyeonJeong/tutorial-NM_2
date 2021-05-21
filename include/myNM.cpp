/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : UiHyoen-Jeong
Created          : 12-05-2021
Modified         : 17-05-2021
Language/ver     : C++ in MSVS2019

Description      : myNM.cpp
----------------------------------------------------------------*/

#include "myNM.h"

// Return the dy/dx results for the input data. (truncation error: O(h^2))
Matrix	gradient(Matrix _x, Matrix _y) {

	int m = _x.rows - 1;
	int n = _y.rows - 1;

	//error check
	if (m != n) {
		printf("Error:size of Matrix x, Matrix y is not same\n");
		system("pause");
	}

	double h = _x.at[1][0] - _x.at[0][0]; //Assumption constant h
	int i = 0;

	Matrix Out = createMat(_y.rows, 1);

	if (n > 2) {
		//3 point forward difference
		Out.at[0][0] = (-3 * _y.at[0][0] + 4 * _y.at[1][0] - _y.at[2][0]) / (2 * h);
		//2 point central difference
		for (i = 1; i < _y.rows - 1; i++) {
			Out.at[i][0] = (_y.at[i + 1][0] - _y.at[i - 1][0]) / (2 * h);
		}
		//3 point backward difference
		Out.at[m][0] = (_y.at[m - 2][0] - 4 * _y.at[m - 1][0] + 3 * _y.at[m][0]) / (2 * h);
	}
	if(n == 2) {
		 Out.at[0][0]=(_y.at[1][0] - _y.at[0][0]) / ( 2 * h); //use 2 point forward difference
		 Out.at[1][0]=(_y.at[1][0] - _y.at[0][0]) / (2 * h); //use 2point backward difference
	}
	return Out;
}


//Find dy/dx results for the input data. (truncation error: O(h^2))
void gradient1D(double _x[], double _y[], double _dydx[], int m) {

	Matrix y = arr2Mat(_y, m, 1);
	int n = y.rows;

	if (m != n) {
		printf("Error:size of Matrix x, Matrix y is not same\n");
		system("pause");
	}

	double h = _x[1] - _x[0]; //Assumption constant h
	int i = 0;

	if (n > 2) {
		//3 point forward difference
		_dydx[0] = (-3 * _y[0] + 4 * _y[1] - _y[2]) / (2 * h);
		//2 point central difference
		for (i = 1; i <n- 1; i++) {
			_dydx[i]= (_y[i + 1] - _y[i - 1]) / (2 * h);
		}
		//3 point backward difference
		_dydx[m - 1] = (_y[m - 3] - 4 * _y[m - 2] + 3 * _y[m - 1]) / (2 * h);
	}
	if (n == 2) {
		_dydx[0] = (_y[1] - _y[0]) / (2 * h);//use 2 point forward difference
		_dydx[1] = (_y[1] - _y[0]) / (2 * h);//use 2point backward difference
	}
	
}


// Return the dy/dx results for the target equation. (truncation error: O(h^2))
Matrix	gradientFunc(double func(const double x), Matrix xin) {

	int n = xin.rows;
	int i = 0;

	Matrix y = createMat(n, 1);
	Matrix df = createMat(n, 1);

	//define y[0] to y[n-1]
	for (int i = 0; i < n; i++) {
		y.at[i][0] = func(xin.at[i][0]);
	}

	//numerical deifferentiation
	return gradient(xin, y);
}

//Modify newtonraphson function to pass functions as input
double newtonRaphsonFunc(double func(const double x), double dfunc(const double x), double _x0, double _tol) {
	
	/************      Variables declaration & initialization      ************/
	int k = 1;
	int Nmax = 100;
	double x = _x0;
	double  ep = 100;
	double xn = 0;
	double  h = 0;

	/************      First iteration and values     ************/
	xn = x;
	ep = fabs(func(xn));
	printf("Iteration:%d \t", 0);
	printf("X(n): %lf \t", xn);
	printf("Tolerance: %lf\n", ep);

	/************     Repeat until condition unsatisfied    ************/
	while (k<Nmax && ep>_tol) {
		h = -func(xn) / dfunc(xn);
		xn = xn + h;
		ep = fabs(func(xn));

		printf("Iteration:%d \t", k);
		printf("X(n): %lf \t", xn);
		printf("Tolerance: %lf\n", ep);
		k++;
	}
	return xn;
}
