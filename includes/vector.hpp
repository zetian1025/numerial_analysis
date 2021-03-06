#ifndef VECTOR_H_
#define VECTOR_H_

#define ZERO_LIMIT 1e-6
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

    Vector();
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

    Vector& resize(const int &);

    friend std::ostream& operator <<(std::ostream& os, const Vector<T> & Vec){
        for (auto& ele : Vec.get_vector()) {
            os << ele << '\t';
        }
        os << std::endl;
        return os;
    }

    friend Vector<T> operator *(const double & k, Vector<T> Vec) { return Vec * k;}

    friend Vector<T> operator -(Vector<T> Vec) { return -1*Vec; }
};

#endif