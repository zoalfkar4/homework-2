#include <iostream>

const int size = 3;

class Vector {
  private:
  const int size = 3;
  double* data;

  public:
  Vector(int size): data(new double[size]) {}
  Vector(const Vector & other): size(other.size), data(new double[other.size]) {
    for (int i = 0; i < size; ++i) {
      data[i] = other.data[i];
    }
  }
  ~Vector() {
    delete[] data;
  }

  Vector& operator = (const Vector& other) {
    if (this != &other) {
      delete[] data;
      data = new double[size];
      for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
      }
    }
    return *this;
  }

  Vector& operator += (const Vector& other) {
    for (int i = 0; i < size; ++i) {
      data[i] += other.data[i];
    }
    return *this;
  }

  Vector& operator -= (const Vector& other) {
    for (int i = 0; i < size; ++i) {
      data[i] -= other.data[i];
    }
    return *this;
  }

  double operator[](int index) const {
    return data[index];
  }

  double& operator[](int index) {
    return data[index];
  }

  int getSize() const {
    return size;
  }

  friend std::ostream& operator << (std::ostream& os, const Vector & vec) {
    os << "(";
    for (int i = 0; i < vec.size - 1; ++i) {
      os << vec.data[i] << ", ";
    }
    os << vec.data[vec.size - 1] << ")";
    return os;
  }

  friend std::istream & operator >> (std::istream & is, Vector & vec) {
    for (int i = 0; i < vec.size; ++i) {
      is >> vec.data[i];
    }
    return is;
  }

  double operator * (const Vector& other) const {
    double result = 0.0;
    for (int i = 0; i < size; ++i) {
      result += data[i] * other.data[i];
    }
    return result;
  }

  Vector operator * (double scalar) const {
    Vector result(size);
    for (int i = 0; i < size; ++i) {
      result.data[i] = data[i] * scalar;
    }
    return result;
  }

  friend Vector operator + (const Vector& v1, const Vector& v2) {
    Vector result = v1;
    result += v2;
    return result;
  }

  friend Vector operator - (const Vector& v1, const Vector& v2) {
    Vector result = v1;
    result -= v2;
    return result;
  }
};

int main() {
 
  Vector v1(size);
  Vector v2(size);

  std::cout << "Enter vector v1 (" << size << " elements): ";
  std::cin >> v1;
  std::cout << "Enter vector v2 (" << size << " elements): ";
  std::cin >> v2;

  Vector sum = v1 + v2;
  Vector difference = v1 - v2;
  double dotProduct = v1 * v2;
  double scalar = 2.5;
  Vector scaled = v1 * scalar;

  std::cout << "v1: " << v1 << std::endl;
  std::cout << "v2: " << v2 << std::endl;
  std::cout << "Sum: " << sum << std::endl;
  std::cout << "Difference: " << difference << std::endl;
  std::cout << "Dot Product: " << dotProduct << std::endl;
  std::cout << "Scaled: " << scaled << std::endl;

  return 0;
}
