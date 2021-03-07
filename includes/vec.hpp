#ifndef VEC_H_
#define VEC_H_

#include <vector>
using std::vector;

typedef vector<double> vector_d;

class vec{
    private:
    vector_d vec_d;

    public:
    vec(int, double);
    vec(const vector_d &);

    const int size() const;

    vector_d data() const;

    double& operator [](int);
    const double& operator [](int) const;

    vec operator +(const vec &);
    void operator +=(const vec &);
    vec operator -(const vec &);
    void operator -=(const vec &);
    vec operator *(const vec &);
    void operator *=(const vec &);
    vec operator /(const vec &);
    void operator /=(const vec &);

    vec operator +(const double &);
    void operator +=(const double &);
    vec operator -(const double &);
    void operator -=(const double &);
    vec operator *(const double &);
    void operator *=(const double &);
    vec operator /(const double &);
    void operator /=(const double &);
};

#endif