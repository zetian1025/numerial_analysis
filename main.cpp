#include "main.hpp"
#include <iostream>
using namespace std;

double f(double x) { return cos(x) - x; }
double _f(double x) { return -sin(x) - 1;}

double g(double x) { return exp(-x) - sin(x); }
double _g(double x) { return -exp(-x)-cos(x); }

double h(double x) { return x-exp(-x); }
double _h(double x) { return 1+exp(-x); }

double w(double x) { return x*x - 2*x*exp(-x) + exp(-2*x);}
double _w(double x) { return 2*x - 2*exp(-x) + 2*x*exp(-x) -2*exp(-2*x);}

double Legendre(double x) {
    
}

int main(){
    double ans1, ans2, ans3, ans4;
    ans1 = Newton(f, _f, (double)M_PI/4, 1e-6, 1e-4);
    ans2 = Newton(g, _g, 0.6, 1e-6, 1e-4);
    cout << "ans1: " << ans1 << "\tans2: " << ans2 << endl;

    ans3 = Newton(h, _h, 0.5, 1e-6, 1e-4);
    cout << "ans3: " << ans3 << endl;

    ans4 = Newton(w, _w, 0.5, 1e-6, 1e-4);
    cout << "ans4: " << ans4 << endl;
    return 0;
}