/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : UiHyoen-Jeong
Created          : 12-05-2021
Modified         : 16-05-2021
Language/ver     : C++ in MSVS2019

Description      : myMatrix.h
----------------------------------------------------------------*/

#ifndef		_MY_MATRIX_H		// use either (#pragma once) or  (#ifndef ...#endif)
#define		_MY_MATRIX_H

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

typedef struct {
	double** at;
	int rows, cols;
}Matrix;


// Create Matrix with specified size
extern	Matrix	createMat(int _rows, int _cols);

// Free a memory allocated matrix
extern	void	freeMat(Matrix _A);

// Create a matrix from a text file
extern	Matrix	txt2Mat(std::string _filePath, std::string _fileName);

// Print matrix
extern	void	printMat(Matrix _A, const char* _name);

// initialization of Matrix elements
extern	void	initMat(Matrix _A, double _val);

// Create identity 
extern	Matrix	eye(int _rows, int _cols);

// Copy matrix Elements from A to B
extern	void	copyVal(Matrix _A, Matrix _B);

// Create matrix of all zeros
extern	Matrix	zeros(int _rows, int _cols);

// Create Transpose matrix
extern	Matrix	transpose(Matrix _A);

// Create a matrix from 1D-array
extern Matrix	arr2Mat(double* _1Darray, int _rows, int _cols);

#endif




