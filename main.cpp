#include "main.hpp"
using namespace std;

int main(){
    Matrix<double> I({
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 2}
    });
    Matrix<double> J({
        {2, 3, 4},
        {1, 2},
        {6, 7, 8}
    });

    cout << I*J << endl;

    return 0;
}