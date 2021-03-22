#include "../includes/vector.hpp"
#include <cmath>

template <typename T>
inline int Vector<T>::get_size() const{ return size; }

template <typename T>
inline vector<T> Vector<T>::get_vector() const { return my_vector; }

template <typename T>
Vector<T>::Vector(){
    size = 1;
    my_vector = vector<T>(1, 0);
}

template <typename T>
Vector<T>::Vector(const int & length, const T & number){
    size = length;
    my_vector = vector<T>(length, number);
}

template <typename T>
Vector<T>::Vector(const vector<T> & vec){
    size = vec.size();
    my_vector = vec; 
}

template <typename T>
Vector<T>::Vector(const Vector<T> & Vec){
    vector<T> vec = Vec.get_vector();
    my_vector = vec;
    size = Vec.get_size();
}

template <typename T>
T& Vector<T>::operator [](const int & index){
    return my_vector[index];
}

template <typename T>
const T& Vector<T>::operator [](const int & index) const {
    return my_vector[index];
}

template <typename T>
Vector<T> Vector<T>::operator +(const T & number){
    vector<T> newVec(my_vector);
    for (auto& element : newVec)
        element += number;
    return Vector<T>(newVec);
}

template <typename T>
Vector<T> Vector<T>::operator -(const T & number){
    vector<T> newVec(my_vector);
    for (auto& element : newVec)
        element -= number;
    return Vector<T>(newVec);
}

template <typename T>
Vector<T> Vector<T>::operator *(const T & number){
    vector<T> newVec(my_vector);
    for (auto& element : newVec)
        element *= number;
    return Vector<T>(newVec);
}

template <typename T>
Vector<T> Vector<T>::operator /(const T & number){
    if (fabs(number) < ZERO_LIMIT){
        printf("div 0 error!\n");
        exit(-1);
    }
    vector<T> newVec(my_vector);
    for (auto& element : newVec)
        element /= number;
    return Vector<T>(newVec);
}

template <typename T>
Vector<T> Vector<T>::operator +(const Vector & Vec){
    Vector<T> newVec(my_vector);
    if (size != Vec.get_size()) {
        printf("vector size mismatched!\n");
        exit(-1);
    }
    for (int i=0; i<size; i++) {
        newVec[i] += Vec[i];
    }
    return newVec;
}

template <typename T>
Vector<T> Vector<T>::operator -(const Vector & Vec){
    Vector<T> newVec(my_vector);
    if (size != Vec.get_size()) {
        printf("vector size mismatched!\n");
        exit(-1);
    }
    for (int i=0; i<size; i++) {
        newVec[i] -= Vec[i];
    }
    return newVec;
}

template <typename T>
Vector<T> Vector<T>::operator *(const Vector & Vec){
    Vector<T> newVec(my_vector);
    if (size != Vec.get_size()) {
        printf("vector size mismatched!\n");
        exit(-1);
    }
    for (int i=0; i<size; i++) {
        newVec[i] *= Vec[i];
    }
    return newVec;
}

template <typename T>
Vector<T> Vector<T>::operator /(const Vector & Vec){
    Vector<T> newVec(my_vector);
    if (size != Vec.get_size()) {
        printf("vector size mismatched!\n");
        exit(-1);
    }
    for (int i=0; i<size; i++) {
        if (fabs(Vec[i]) < ZERO_LIMIT) {
            printf("div 0 error\n");
            exit(-1);
        }
        newVec[i] /= Vec[i];
    }
    return newVec;
}

template <typename T>
Vector<T>& Vector<T>::operator =(const Vector<T> & Vec){
    size = Vec.get_size();
    my_vector = Vec.get_vector();
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator =(const vector<T> & Vec){
    size = Vec.get_size();
    my_vector = Vec;
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator +=(const T & number) {
    for (auto& element : my_vector)
        element += number;
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator -=(const T & number) {
    for (auto& element : my_vector)
        element -= number;
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator *=(const T & number) {
    for (auto& element : my_vector)
        element *= number;
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator /=(const T & number) {
    if (fabs(number) < ZERO_LIMIT){
        printf("div 0 error\n");
        exit(-1);
    }
    for (auto& element : my_vector)
        element /= number;
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator +=(const Vector & Vec){
    if (size != Vec.get_size()){
        printf("vector size mismatched!\n");
        exit(-1);
    }
    for (int i=0; i<size; i++) 
        my_vector[i] += Vec[i];
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator -=(const Vector & Vec){
    if (size != Vec.get_size()){
        printf("vector size mismatched!\n");
        printf("size %d and %d\n", size, Vec.get_size());
        exit(-1);
    }
    for (int i=0; i<size; i++) 
        my_vector[i] -= Vec[i];
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator *=(const Vector & Vec){
    if (size != Vec.get_size()){
        printf("vector size mismatched!\n");
        exit(-1);
    }
    for (int i=0; i<size; i++) 
        my_vector[i] *= Vec[i];
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator /=(const Vector & Vec){
    if (size != Vec.get_size()){
        printf("vector size mismatched!\n");
        exit(-1);
    }
    for (int i=0; i<size; i++) {
        if (fabs(Vec[i]) < ZERO_LIMIT) {
            printf("div 0 error\n");
            exit(-1);
        }
        my_vector[i] /= Vec[i];
    }
    return *this;
}

template <typename T>
bool Vector<T>::operator ==(const Vector & Vec){
    if (size != Vec.get_size()){
        return false;
    }
    for (int i=0; i<size; i++) {
        if (fabs(my_vector[i] - Vec[i])>=ZERO_LIMIT) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool Vector<T>::operator ==(const vector<T> & vec){
    Vector<T> Vec(vec);
    return (*this)==Vec;
}

template <typename T>
T Vector<T>::dot(const Vector & Vec){
    if (size != Vec.get_size()) {
        printf("vector size mismatched!\n");
        exit(-1);
    }
    T num = 0;
    for (int i=0; i<size; i++)
        num += my_vector[i]*Vec[i];
    return num;
}

template <typename T>
T Vector<T>::dot(const vector<T> & vec){
    Vector<T> Vec(vec);
    return dot(Vec);
}

template <typename T>
Vector<T>& Vector<T>::resize(const int & newSize){
    if (newSize < size){
        while (size != newSize) {
            my_vector.pop_back();
            size--;
        }
    }
    else if (newSize > size){
        while (size != newSize) {
            my_vector.push_back(0);
            size++;
        }
    }
    return *this;
}
