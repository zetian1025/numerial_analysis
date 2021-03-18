#ifndef VECTOR_H_
#define VECTOR_H_

#include <vector>
#include <iostream>

using std::vector;

template <typename T>
class Vector{
    private:
    vector<T> my_vector;
    int size;
    
    public:
    int get_size() const;
    vector<T> get_vector() const;

    Vector(const int &, const T &);
    Vector(const vector<T> &);
    Vector(const Vector<T> &);

    T& operator[](const int &);
    const T& operator[](const int &) const;
    
    Vector operator+(const T &);
    Vector operator-(const T &);
    Vector operator*(const T &);
    Vector operator/(const T &);

    Vector operator+(const Vector &);
    Vector operator-(const Vector &);
    Vector operator*(const Vector &);
    Vector operator/(const Vector &);

    Vector& operator=(const Vector &);
    Vector& operator=(const vector<T> &);

    Vector& operator+=(const T &);
    Vector& operator-=(const T &);
    Vector& operator*=(const T &);
    Vector& operator/=(const T &);

    Vector& operator+=(const Vector &);
    Vector& operator-=(const Vector &);
    Vector& operator*=(const Vector &);
    Vector& operator/=(const Vector &);

    bool operator==(const Vector &);
    bool operator==(const vector<T> &);

    T dot(const Vector &);
    T dot(const vector<T> &);

    friend std::ostream& operator<<(std::ostream &, const Vector<T> &);
};

#endif