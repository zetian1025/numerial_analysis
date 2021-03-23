#include "main.hpp"
#include <iostream>
using namespace std;

int main(){
    Matrix<double> A ({
        {10, 4, 4},
        {4, 10, 8},
        {4, 8, 10}
    });
    auto LD = LDL(A);
    auto L = LD.first, D = LD.second;
    cout << L << D << transpose(L);
    return 0;
}