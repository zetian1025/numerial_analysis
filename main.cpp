#include "main.hpp"
#include <iostream>
using namespace std;

int main(){
    Matrix<double> I ({
        {5, 7, 9, 10},
        {6, 8, 10, 9},
        {7, 10, 8, 7},
        {5, 7, 6, 5}
    });
    Vector<double> B({1, 1, 1, 1});
    Vector<double> X = Crout_LU(I, B);
    cout << X;
    return 0;
}