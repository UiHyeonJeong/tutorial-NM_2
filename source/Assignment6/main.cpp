/*-------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : UiHyoen-Jeong
Created          : 12-05-2021
Modified         : 17-05-2021
Language/ver     : C++ in MSVS2019

Description      :  NM_MainTemplate.cpp
-------------------------------------------------------------------------------*/

#define Assignment	6		// enter your assignment number
#define eval		0		// set 0

#include "../../include/myNM.h"

// Define a function that defines the target equation.
double myFunc(const double x);

// Define a function that defines the target equation.
double mydFunc(const double x);

int main(int argc, char* argv[])
{
	// PART 1
	printf("\n**************************************************");
	printf("\n|                     PART 1.                    |");
	printf("\n**************************************************\n");

	double time[]={ 0, 0.2, 0.4, 0.6, 0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 2.0, 2.2, 2.4, 2.6, 2.8, 3.0, 3.2, 3.4, 3.6, 3.8, 4.0 };
	double x[] = { -5.87,-4.23,-2.55,-0.89,0.67,2.09,3.31,4.31,5.06,5.55,5.78,5.77,5.52,5.08,4.46,3.72,2.88,2.00,1.10,0.23,-0.59 };
	int m = 21;
	double dydx1[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	Matrix t = arr2Mat(time, m, 1);
	Matrix pos = arr2Mat(x, m, 1);

	Matrix vel = gradient(t, pos);
	Matrix acc = gradient(t, vel);

	printMat(t, "t");
	printMat(pos, "pos");
	printMat(vel, "vel");
	printMat(acc, "acc");

	gradient1D(time,x,dydx1,m);

	printf("dydx=\n");
	for (int i = 0; i < m; i++) {
		printf("\t%lf\n", dydx1[i]);
	}


	// PART 2
	printf("\n**************************************************");
	printf("\n|                     PART 2.                    |");
	printf("\n**************************************************\n");
	double tol = 0.000001;
	double  x0 = 1;

	Matrix xin = arr2Mat(time, m, 1);
	Matrix dydx = gradientFunc(myFunc, xin);

	printMat(xin, "xin");
	printMat(dydx, "dydx");

	printf("\n----------------------------------------------------");
	printf("\n|          NewtonRaphson Results                   |");
	printf("\n----------------------------------------------------\n");

	double NR_result = newtonRaphsonFunc(myFunc, mydFunc, x0, tol);
	printf("\nsolution of function:%lf\n", NR_result);

	system("pause");
	return 0;
}

// Define a function that defines the target equation.
double myFunc(const double x) {
	return  x * x * x;
}

// Define a function that defines the target equation.
double mydFunc(const double x) {
	return  3 * x * x;
}
