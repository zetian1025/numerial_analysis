#include "main.hpp"
#include <iostream>
using namespace std;

int main(){
    Matrix<double> A ({
        {1, 2, 1, -2},
        {2, 5, 3, -2},
        {-2, -2, 3, 5},
        {1, 2, 2, 4}
    });
    Vector<double> B({4, 7, -1, 0});
    Vector<double> X = Guass(A, B);
    cout << X;
    return 0;
}