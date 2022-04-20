#include "Fraction.h"
#include <iostream>
#include <numeric>

using namespace std;

/*
* Constructor to make a Fraction object
*/
Fraction::Fraction(int n, int d) {
    this->numer = n;
    this->denom = d;
}

/*
* Overloaded operator that prints the contents of a fraction object
*/
void Fraction::operator!() const {
    cout << this->numer << "/" << this->denom << endl;
}

/*
* Overloaded operator that evaluates if two fraction objects are equal
*/
bool Fraction::operator==(const Fraction &f) const {
    return (this->numer * f.denom == f.numer * this->denom);
}

/*
* Overloaded operator that evaluates if two fraction objects are not equal
*/
bool Fraction::operator!=(const Fraction &f) const {
    return (this->numer * f.denom != f.numer * this->denom);
}

/*
* Overloaded operator that adds two fraction objects together and returns
* the result as a new Fraction object.
*/
Fraction Fraction::operator+(const Fraction &f) const {
    int mul1 = 0; int mul2 = 0;
    int newDenom = 0;
    if (this->denom == f.denom) {
        mul1 = 1;
        mul2 = 1;
        newDenom = this->denom;
    } else if (this->denom % f.denom == 0 || f.denom % this->denom == 0){
        newDenom = this->denom > f.denom ? this->denom : f.denom;
        mul1 = this->denom > f.denom ? 1 : f.denom / this->denom;
        mul2 = f.denom > this->denom ? 1 : this->denom / f.denom;
    } else {
        int lcm = 1;
        while (!(lcm % this->denom == 0 && lcm % f.denom == 0)) {
            lcm++;
        }
        mul1 = lcm / this->denom;
        mul2 = lcm / f.denom;
        newDenom = lcm;
    }
    return Fraction((this->numer * mul1) + (f.numer * mul2), newDenom);
}

/*
* Overloaded operator that subtracts two fraction objects and returns
* the result as a new fraction object.
*/
Fraction Fraction::operator-(const Fraction &f) const {
    int mul1 = 0; int mul2 = 0;
    int newDenom = 0;
    if (this->denom == f.denom) {
        mul1 = 1;
        mul2 = 1;
        newDenom = this->denom;
    } else if (this->denom % f.denom == 0 || f.denom % this->denom == 0){
        newDenom = this->denom > f.denom ? this->denom : f.denom;
        mul1 = this->denom > f.denom ? 1 : f.denom / this->denom;
        mul2 = f.denom > this->denom ? 1 : this->denom / f.denom;
    } else {
        int lcm = 1;
        while (!(lcm % this->denom == 0 && lcm % f.denom == 0)) {
            lcm++;
        }
        mul1 = lcm / this->denom;
        mul2 = lcm / f.denom;
        newDenom = lcm;
    }
    return Fraction((this->numer * mul1) - (f.numer * mul2), newDenom);
}

/*
* Overloaded operator that multiplies two fraciton objects and returns 
* the result as a new fraction object
*/
Fraction Fraction::operator*(const Fraction &f) const {
    return Fraction(this->numer * f.numer, this->denom * f.denom);
}

/*
* Overloaded operator that divides two fraction objects and returns
* the result as a new fraction object
*/
Fraction Fraction::operator/(const Fraction &f) const {
    return Fraction(this->numer * f.denom, this->denom * f.numer);
}

/*
* Overloaded operator that adds a fraction and an integer and returns
* the result as a new fraction object
*/
Fraction Fraction::operator+(int n) const {
    return Fraction((this->numer) + (n * this->denom), this->denom);
}

/*
* Overloaded operator that subtracts a fraction and an integer and returns
* the result as a new fraction object
*/
Fraction Fraction::operator-(int n) const {
    return Fraction((this->numer) - (n * this->denom), this->denom);
}

/*
* Overloaded operator that multiplies a fraction and an inteeger and returns
* the result as a new fraction object
*/
Fraction Fraction::operator*(int n) const {
    return Fraction(this->numer * n, this->denom);
}

/*
* Overloaded operator that divides a fraction and an integer and returns
* the result as a new fraction object
*/
Fraction Fraction::operator/(int n) const {
    return Fraction(this->numer, this->denom * n);
}

