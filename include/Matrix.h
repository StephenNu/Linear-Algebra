#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
/*
 *	Matrix Representation. of type T (assumed int, float, double and complex)
 *	of N rows, and M Columns. *
 */
template <class T>
class Matrix {
	public:
		/*
		 * Constructors
		 */
		Matrix();
		Matrix(Matrix<T>&);
		Matrix(const Matrix<T>&);
		Matrix(vector<vector<T>>&);
		Matrix(const vector<T>&);
		
	private:
		vector<T> _matrix;
};
#endif
