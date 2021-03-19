#include "main.hpp"
using namespace std;

int main(){
    Matrix<double> I(3, 3);
    I = I.identity();
    I[1][0] = 2;
    for (int i=0; i<I.get_size().first; i++) {
        for (int j=0; j<I.get_size().second; j++){
            cout << I[i][j] << ' ';
        }
        cout << endl;
    }
    I = I.invertion();
    for (int i=0; i<I.get_size().first; i++) {
        for (int j=0; j<I.get_size().second; j++){
            cout << I[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}