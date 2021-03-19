#ifndef UTIL_H_
#define UTIL_H_

template <typename T>
void swap(T& a, T&b) {
    T temp = a;
    a = b;
    b = temp;
}

#endif