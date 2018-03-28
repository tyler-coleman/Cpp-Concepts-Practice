//
//  Complex.cpp
//  Complex Number Class
//
//  Created by Tyler Coleman on 2/24/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex() : real(0), imaginary(0) {}
Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

Complex::Complex(const Complex &other) {
    *this = other;
}

const Complex &Complex::operator=(const Complex &other) {
    real = other.real;
    imaginary = other.imaginary;

    return *this;
}

bool Complex::operator==(const Complex &other) {
    return (real == other.getReal() && imaginary == other.getImaginary());
}

// Can take advantage of the fact that == is already overloaded.
bool Complex::operator!=(const Complex &other) {
    return !(*this == other);
}

// Overload * operator to return complex conjugate.
Complex Complex::operator*() {
    return Complex(real, -imaginary);
}

ostream &operator<<(ostream &out, const Complex &c) {
    out << c.getReal() << " + " << c.getImaginary() << "i";
    return out;
}

Complex operator+(const Complex &c1, const Complex &c2) {
    double real = c1.getReal() + c2.getReal();
    double imaginary = c1.getImaginary() + c2.getImaginary();
    
    return Complex(real,imaginary);
}

Complex operator+(const Complex &c, double d) {
    return Complex(c.getReal() + d, c.getImaginary());
}

Complex operator+(double d, const Complex &c) {
    return Complex(c.getReal() + d, c.getImaginary());
}


