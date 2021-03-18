#include "main.hpp"
using namespace std;

int main(){
    Vector<double> vec1({1, 2, 3});
    Vector<double> vec2({2, 1, 4});
    cout << vec1.dot(vec2) << endl;
    Vector<double> v1 = vec1/vec2;
    Vector<double> v2 = vec1*vec2;
    for (int i=0; i<v1.get_size(); i++){
        cout << v1[i] << " ";
    }
    cout << endl;
    for (int i=0; i<v1.get_size(); i++) {
        cout << v2[i] << ' ';
    }
    cout << endl;
    return 0;
}