#ifndef LINEAREQUATIONS_H_
#define LINEAREQUATIONS_H_

#include "vector.hpp"
#include "matrix.hpp"

std::pair<Matrix<double>, Matrix<double>> LU(const Matrix<double> &);

std::pair<Matrix<double>, Matrix<double>> _LU(const Matrix<double> &);

Matrix<double> LL(const Matrix<double> &);

std::pair<Matrix<double>, Matrix<double>> LDL(const Matrix<double> &);

Vector<double> Guass(const Matrix<double> &, const Vector<double> &);

Vector<double> Guass_Jordan(const Matrix<double> &, const Vector<double> &);

Vector<double> Doolittle_LU(const Matrix<double> &, Vector<double>);

Vector<double> Crout_LU(const Matrix<double> &, Vector<double>);

Vector<double> Cholesky_LL(const Matrix<double> &, const Vector<double> &);

Vector<double> Cholesky_LDL(const Matrix<double> &, const Vector<double> &);

Vector<double> Jacobi_iteration(const Matrix<double> &, const Vector<double> &);

Vector<double> Guass_Seidel_iteration(const Matrix<double> &, const Vector<double> &);

Vector<double> SOR_iteration(const Matrix<double> &, const Vector<double> &);

#endif