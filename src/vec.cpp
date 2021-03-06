#include "../includes/vec.hpp"
#include <cstdio>
#include <cstdlib>

using std::vector;

vec::vec(int row, double number){
    vec_d = vector_d(row, number);
}

vec::vec(const vector_d & vect){
    vec_d = vect;
}

const int vec::size() const{
    return vec_d.size();
}

vector_d vec::data() const {
    return this->vec_d;
}

vec vec::operator +(const vec & vect){
    if (size() != vect.size()) {
        printf("vector size mismatch!");
        exit(1);
    }

    vector_d newVec;
    for (int i=0; i<size(); i++){
        newVec.push_back(vec_d[i] + vect[i]);
    }
    return vec(newVec);
}

vec vec::operator -(const vec & vect){
    if (size() != vect.size()) {
        printf("vector size mismatch!");
        exit(1);
    }

    vector_d newVec;
    for (int i=0; i<size(); i++){
        newVec.push_back(vec_d[i] - vect[i]);
    }
    return vec(newVec);
}

vec vec::operator *(const vec & vect){
    if (size() != vect.size()) {
        printf("vector size mismatch!");
        exit(1);
    }

    vector_d newVec;
    for (int i=0; i<size(); i++){
        newVec.push_back(vec_d[i] * vect[i]);
    }
    return vec(newVec);
}

vec vec::operator /(const vec & vect){
    if (size() != vect.size()) {
        printf("vector size mismatch!");
        exit(1);
    }

    vector_d newVec;
    for (int i=0; i<size(); i++){
        newVec.push_back(vec_d[i] / vect[i]);
    }
    return vec(newVec);
}

vec vec::operator +=(const vec & vect){
    if (size() != vect.size()){
        printf("vector size mismatch!");
        exit(1);
    }

    for (int i=0; i<size(); i++){
        vec_d[i] += vect[i];
    }

    return *this;
}

vec vec::operator -=(const vec & vect){
    if (size() != vect.size()){
        printf("vector size mismatch!");
        exit(1);
    }

    for (int i=0; i<size(); i++){
        vec_d[i] -= vect[i];
    }

    return *this;
}

vec vec::operator *=(const vec & vect){
    if (size() != vect.size()){
        printf("vector size mismatch!");
        exit(1);
    }

    for (int i=0; i<size(); i++){
        vec_d[i] *= vect[i];
    }

    return *this;
}

vec vec::operator /=(const vec & vect){
    if (size() != vect.size()){
        printf("vector size mismatch!");
        exit(1);
    }

    for (int i=0; i<size(); i++){
        vec_d[i] /= vect[i];
    }

    return *this;
}

double& vec::operator [](int index){
    if (index < 0 || index >= size()){
        printf("index out of bound!");
        exit(1);
    }
    return vec_d[index];
}

const double vec::operator [](int index) const {
    if (index < 0 || index >= size()){
        printf("index out of bound!");
        exit(1);
    }
    return vec_d[index];
} 