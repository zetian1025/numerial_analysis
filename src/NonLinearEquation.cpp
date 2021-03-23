#include "../includes/NonLinearEquation.hpp"
#include <cstdio>
#include <cmath>

#define INTERATION_TIME 10

double Newton(double (*f)(double x), double (*_f)(double x), double x0, double eps1, double eps2) {
    double residual, x = x0;
    std::cout << (int)INTERATION_TIME << std::endl;
    for (int n=0; n<(int)INTERATION_TIME; n++) {
        if (fabs(f(x)) < eps1) return x;
        else if (fabs(_f(x)) < eps2) {
            printf("Newton method failed.\n");
            exit(-1);
        }
        x -= (residual = f(x)/_f(x));
        if (fabs(residual) < eps1) return x;
    }
    printf("Newton method failed.\n");
    exit(-1);
}