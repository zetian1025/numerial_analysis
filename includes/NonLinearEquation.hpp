#ifndef NONLINEAREQUATION_H_
#define NONLINEAREQUATION_H_

#include "./matrix.hpp"
#include "./vector.hpp"

double Newton(double (*f)(double), double(*_f)(double), double, double, double);

#endif