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
    return (231*pow(x, 6) - 315*pow(x, 4) + 105*pow(x, 2) - 5)/16;
}
double _Legendre(double x) {
    return (6*231*pow(x, 5) - 4*315*pow(x, 3) + 2*105*x)/16;
}

double Chebyshev(double x) {
    return 32*pow(x, 6) - 48*pow(x, 4) + 18*pow(x, 2) - 1;
}
double _Chebyshev(double x) {
    return 6*32*pow(x, 5) - 4*48*pow(x, 3) + 2*18*x;
}

double Laguerre(double x) {
    return (-pow(x, 5) + 25*pow(x, 4) - 200*pow(x, 3) + 600*pow(x, 2) - 600*x + 120) / 120;
}
double _Laguerre(double x) {
    return (-5*pow(x, 4) + 100*pow(x, 3) - 600*pow(x, 2) + 1200*x - 600) / 120;
}

double Hermite(double x) {
    return 64*pow(x, 6) - 480*pow(x, 4)+720*pow(x, 2) - 120;
}
double _Hermite(double x) {
    return 6*64*pow(x, 5)-4*480*pow(x, 3)+2*720*x;
}

int main(){
    // double ans1, ans2, ans3, ans4, ans5, ans6;
    // cout.precision(10);
    // ans1 = Newton(f, _f, (double)M_PI/4, 1e-6, 1e-4);
    // ans2 = Newton(g, _g, 0.6, 1e-6, 1e-4);
    // cout << "ans1: " << ans1 << "\tans2: " << ans2 << endl;

    // ans3 = Newton(h, _h, 0.5, 1e-6, 1e-4);
    // cout << "ans3: " << ans3 << endl;

    // ans4 = Newton(w, _w, 0.5, 1e-6, 1e-4);
    // cout << "ans4: " << ans4 << endl;

    // ans1 = Newton(Legendre, _Legendre, 1, 1e-6, 1e-6);
    // ans2 = Newton(Legendre, _Legendre, -1, 1e-6, 1e-6);
    // ans3 = Newton(Legendre, _Legendre, 0.6, 1e-6, 1e-6);
    // ans4 = Newton(Legendre, _Legendre, -0.6, 1e-6, 1e-6);
    // ans5 = Newton(Legendre, _Legendre, 0.2, 1e-6, 1e-6);
    // ans6 = Newton(Legendre, _Legendre, -0.2, 1e-6, 1e-6);
    // cout << "ans1: " << ans1 << endl;
    // cout << "ans2: " << ans2 << endl;
    // cout << "ans3: " << ans3 << endl;
    // cout << "ans4: " << ans4 << endl;
    // cout << "ans5: " << ans5 << endl;
    // cout << "ans6: " << ans6 << endl;

    // for (int i=0; i<=6; i++) {
    //     ans1 = Newton(Chebyshev, _Chebyshev, cos((2*i+1)/14.0*M_PI), 1e-6, 1e-16);
    //     cout << "ans" << i+1 << ": " << ans1 << endl;
    // }

    // ans1 = Newton(Laguerre, _Laguerre, 0.26, 1e-6, 1e-6);
    // ans2 = Newton(Laguerre, _Laguerre, 1.41, 1e-6, 1e-6);
    // ans3 = Newton(Laguerre, _Laguerre, 3.59, 1e-6, 1e-6);
    // ans4 = Newton(Laguerre, _Laguerre, 7.08, 1e-6, 1e-6);
    // ans5 = Newton(Laguerre, _Laguerre, 12.64, 1e-6, 1e-6);
    // cout << "ans1: " << ans1 << endl;
    // cout << "ans2: " << ans2 << endl;
    // cout << "ans3: " << ans3 << endl;
    // cout << "ans4: " << ans4 << endl;
    // cout << "ans5: " << ans5 << endl;

    // ans1 = Newton(Hermite, _Hermite, 2.3, 1e-6, 1e-6);
    // ans2 = Newton(Hermite, _Hermite, -2.3, 1e-6, 1e-6);
    // ans3 = Newton(Hermite, _Hermite, 1.3, 1e-6, 1e-6);
    // ans4 = Newton(Hermite, _Hermite, -1.3, 1e-6, 1e-6);
    // ans5 = Newton(Hermite, _Hermite, 0.3, 1e-6, 1e-6);
    // ans6 = Newton(Hermite, _Hermite, -0.3, 1e-6, 1e-6);
    // cout << "ans1: " << ans1 << endl;
    // cout << "ans2: " << ans2 << endl;
    // cout << "ans3: " << ans3 << endl;
    // cout << "ans4: " << ans4 << endl;
    // cout << "ans5: " << ans5 << endl;
    // cout << "ans6: " << ans6 << endl;

    Matrix<double> A1({
        {0.4096, 0.1234, 0.3678, 0.2943},
        {0.2246, 0.3872, 0.4015, 0.1129},
        {0.3645, 0.1920, 0.3781, 0.0643},
        {0.1784, 0.4002, 0.2786, 0.3927}
    });
    Vector<double> B1({1.1951, 1.1262, 0.9989, 1.2499});
    cout << Guass_Jordan(A1, B1);

    Matrix<double> A2({
        {136.01, 90.860, 0, 0},
        {90.860, 98.810, -67.590, 0},
        {0, -67.590, 132.01, 46.260},
        {0, 0, 46.260, 177.17}
    });
    Vector<double> B2({226.87, 122.08, 110.68, 223.43});
    cout << Guass_Jordan(A2, B2);

    Matrix<double> A3({
        {1, 0.5, 1.0/3, 1.0/4},
        {1.0/2, 1.0/3, 1.0/4, 1.0/5},
        {1.0/3, 1.0/4, 1.0/5, 1.0/6},
        {1.0/4, 1.0/5, 1.0/6, 1.0/7}
    });
    Vector<double> B3({25.0/12, 77.0/60, 57.0/60, 319.0/420});
    cout << Guass_Jordan(A3, B3);

    Matrix<double> A4({
        {10, 7, 8, 7},
        {7, 5, 6, 5},
        {8, 6, 10, 9},
        {7, 5, 9, 10}
    });
    Vector<double> B4({32, 23, 33, 31});
    cout << Guass_Jordan(A4, B4);
    return 0;
}