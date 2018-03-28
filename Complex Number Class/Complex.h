//
//  Complex.h
//  Complex Number Class
//
//  Created by Tyler Coleman on 2/24/18.
//  Copyright © 2018 Tyler Coleman. All rights reserved.
//

#ifndef Complex_h
#define Complex_h

using namespace std;

class Complex {
    
private:
    double real;
    double imaginary;
    
public:
    Complex();
    Complex(double real, double imaginary);
    Complex(const Complex &other);
    
    const Complex &operator=(const Complex &other);
    
    double getReal() const {return real;}
    double getImaginary() const {return imaginary;}
    
    bool operator==(const Complex &other);
    bool operator!=(const Complex &other);
    Complex operator*();
};

// Not a method of Complex class.
ostream &operator<<(ostream &out, const Complex &c);

Complex operator+(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c, double d);
Complex operator+(double d, const Complex &c);
    
#endif /* Complex_h */
