
/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : UiHyoen-Jeong
Created          : 12-05-2021
Modified         : 16-05-2021

Description      : myNM.h
----------------------------------------------------------------*/

#ifndef		_MY_NM_H		// use either (#pragma once) or  (#ifndef ...#endif)
#define		_MY_NM_H

#include "myMatrix.h"


// Return the dy/dx results for the input data. (truncation error: O(h^2))
extern Matrix	gradient(Matrix _x, Matrix _y);

//Find dy/dx results for the input data. (truncation error: O(h^2))
extern void gradient1D(double x[], double y[], double dydx[], int m);

// Return the dy/dx results for the target equation. (truncation error: O(h^2))
extern Matrix	gradientFunc(double func(const double x), Matrix xin);

//Modify newtonraphson function to pass functions as input
double newtonRaphsonFunc(double func(const double x), double dfunc(const double x), double x0, double tol);

#endif
