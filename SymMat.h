// SymMat.h
#ifndef SYMMAT_H
#define SYMMAT_H

#include <Eigen/Core>
#include <vector>

using namespace Eigen;
using namespace std;

class SymMat {
 private:
  vector<double> m;
 public:
  // Constructors
  SymMat(const Matrix<double, Dynamic, Dynamic> &m);
  SymMat(initializer_list<double> l);
  SymMat(const vector<double> &m);

  // Getters
  vector<double> getVector() const;
  Matrix<double, Dynamic, Dynamic> getAsEigenMatrix() const;
  size_t getSize() const;

  // Overloaded operators
  bool operator==(const SymMat& m) const;
  double operator()(size_t i, size_t j) const;
  SymMat operator+(const SymMat &m) const;
  SymMat operator-(const SymMat &m) const;
  Matrix<double, Dynamic, Dynamic> operator*(const SymMat &m) const;
  Matrix<double, Dynamic, Dynamic> operator+(const Matrix<double, Dynamic, Dynamic> &m) const;
  Matrix<double, Dynamic, Dynamic> operator-(const Matrix<double, Dynamic, Dynamic> &m) const;
  Matrix<double, Dynamic, Dynamic> operator*(const Matrix<double, Dynamic, Dynamic> &m) const;
};

#endif
