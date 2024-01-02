#include <iostream>
#include <cmath>

class Fraction {
 public:
  
  Fraction(int num = 0, int denom = 1): numerator(num), denominator(denom) {
    simplify();
  }
  int getNumerator() const {
    return numerator;
  }

  int getDenominator() const {
    return denominator;
  }
  void setNumerator(int num) {
    numerator = num;
    simplify();
  }

  void setDenominator(int denom) {
    if (denom != 0) {
      denominator = denom;
      simplify();
    } else {
      std::cout << "NO division by zero" << std::endl;
    }
  }

  Fraction& operator += (const Fraction& other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
    simplify();
    return *this;
  }

  Fraction& operator -= (const Fraction& other) {
    numerator = numerator * other.denominator - other.numerator * denominator;
    denominator *= other.denominator;
    simplify();
    return *this;
  }

  Fraction& operator *= (const Fraction& other) {
    numerator *= other.numerator;
    denominator *= other.denominator;
    simplify();
    return *this;
  }

  Fraction& operator /= (const Fraction& other) {
    if (other.numerator != 0) {
      numerator *= other.denominator;
      denominator *= other.numerator;
      simplify();
    } else {
      std::cout << "Error: Division by zero." << std::endl;
    }
    return *this;
  }

  Fraction operator + (const Fraction& other) const {
    Fraction result = *this;
    result += other;
    return result;
  }

  Fraction operator - (const Fraction & other) const {
    Fraction result = *this;
    result -= other;
    return result;
  }

  Fraction operator * (const Fraction & other) const {
    Fraction result = *this;
    result *= other;
    return result;
  }

  Fraction operator / (const Fraction & other) const {
    Fraction result = *this;
    result /= other;
    return result;
  }

  friend std::ostream & operator << (std::ostream & os,
    const Fraction & fraction) {
    os << fraction.numerator;
    if (fraction.denominator != 1) {
      os << '/' << fraction.denominator;
    }
    return os;
  }

  friend std::istream & operator >> (std::istream & is, Fraction & fraction) {
    char slash;
    is >> fraction.numerator;
    if (is.peek() == '/') {
      is >> slash >> fraction.denominator;
      fraction.simplify();
    } else {
      fraction.denominator = 1;
    }
    return is;
  }

  double toDouble() const {
    return static_cast < double > (numerator) / denominator;
  }

 private: 
  int numerator;
  int denominator;

  int gcd(int a, int b) const {
    if (b == 0) {
      return a;
    }
    return gcd(b, a % b);
  }

  void simplify() {
    int common = gcd(std::abs(numerator), denominator);
    numerator /= common;
    denominator /= common;
    if (denominator < 0) {
      numerator = -numerator;
      denominator = -denominator;
    }
  }
};

int main() {
  Fraction f1(1, 2);
  Fraction f2(3, 4);
  
  Fraction sum = f1 + f2;
  Fraction difference = f1 - f2;
  Fraction product = f1 * f2;
  Fraction quotient = f1 / f2;
  
  std::cout << "f1: " << f1 << std::endl;
  std::cout << "f2: " << f2 << std::endl;
  std::cout << "Sum: " << sum << std::endl;
  std::cout << "Difference: " << difference << std::endl;
  std::cout << "Product: " << product << std::endl;
  std::cout << "Quotient: " << quotient << std::endl;
  return 0;
}