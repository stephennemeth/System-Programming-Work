#ifndef FRACTION_H
#define FRACTION_H

/*
 *  The class represents a Fraction as an int numerator (numer) 
 *  and an int demoninator (denom), where denom is not equal to zero. 
 *  This class has various overloaded operators.  
 *  Note: this class's member functions/operators will not reduce or simplify fractions.  
 */
class Fraction{
 private:
  int numer, denom;
 public:
  Fraction(int n = 0, int d = 1);
  void operator! (void) const;		// print the Fraction to standard output
  bool operator== (const Fraction&) const;
  bool operator!= (const Fraction&) const;
  Fraction operator+ (const Fraction&) const;
  Fraction operator- (const Fraction&) const;
  Fraction operator* (const Fraction&) const;
  Fraction operator/ (const Fraction&) const;
  Fraction operator+ (int) const;
  Fraction operator- (int) const;
  Fraction operator* (int) const;
  Fraction operator/ (int) const;
};

#endif
