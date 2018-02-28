#include "SymMat.h"
#include <math.h>

using namespace Eigen;
using namespace std;

SymMat::SymMat(const Matrix<double, Dynamic, Dynamic> &m) {
  if (m.rows() != m.cols())
    throw invalid_argument("Matrix must be symmetric");
  
  this -> size = m.rows();
  
  for (size_t i=0, nRows = m.rows(), nCols = m.cols(); i<nRows; ++i)
    for(size_t j=i; j<nCols; ++j)
      this->m.push_back(m(i,j));
}

SymMat::SymMat(initializer_list<double> l) : m(l) {
  // Check README on GitHub for information about this calculation
  this->size = (-1+sqrt(1+8*(this->getVector()).size()))/2;
}

SymMat::SymMat(const vector<double> &m) {
  this->m = m;
  //TODO - Refactor this equation
  this->size = (-1+sqrt(1+8*(this->getVector()).size()))/2;
}

SymMat SymMat::operator+(const SymMat &m) const {
  if (m.getSize() != this->getSize())
    throw invalid_argument("Matrix param has different size");

  vector<double> m1_v = this->getVector();
  vector<double> m2_v = m.getVector();
    
  vector<double> result = vector<double>(m1_v.size());
  transform(m1_v.begin(), m1_v.end(), m2_v.begin(), result.begin(), plus<double>());
  return SymMat(result);
}

Matrix<double, Dynamic, Dynamic> SymMat::operator+(const Matrix<double, Dynamic, Dynamic> &m) const{
  if (m.rows() != m.cols() && m.rows() != this->getSize())
    throw invalid_argument("Matrix param has different size");

  Matrix<double, Dynamic, Dynamic> r = m.replicate(1,1);
    
  for (size_t i=0; i<this->getSize(); ++i)
    for(size_t j=0; j<this->getSize(); ++j)
      r(i,j) += (*this)(i,j);

  return r;
}

SymMat SymMat::operator-(const SymMat &m) const {
  if (m.getSize() != this->getSize())
    throw invalid_argument("Matrix param has different size");
  
  vector<double> m1_v = this->getVector();
  vector<double> m2_v = m.getVector();
    
  vector<double> result = vector<double>(m1_v.size());
  transform(m1_v.begin(), m1_v.end(), m2_v.begin(), result.begin(), minus<double>());
  return SymMat(result);
}

Matrix<double, Dynamic, Dynamic> SymMat::operator-(const Matrix<double, Dynamic, Dynamic> &m) const{
  if (m.rows() != m.cols() && m.rows() != this->getSize())
    throw invalid_argument("Matrix param has different size");

  size_t m_size = this->getSize();
  Matrix<double, Dynamic, Dynamic> r(this->getSize(), this->getSize());
    
  for (size_t i=0; i<m_size; ++i)
    for(size_t j=0; j<m_size; ++j)
      r(i,j) = (*this)(i,j)-m(i,j);

  return r;
}

Matrix<double, Dynamic, Dynamic> SymMat::operator*(const SymMat &m) const {
  if (m.getSize() != this->getSize())
    throw invalid_argument("Matrix param has different size");
  
  Matrix<double, Dynamic, Dynamic> result(this->getSize(),this->getSize());

  for (size_t i=0; i<this->getSize(); ++i)
    for (size_t j=0; j<this->getSize(); ++j) {
      double addition = 0;
      for (size_t k=0; k<m.getSize(); ++k)
	addition += (*this)(i,k) * m(k,j);
      result(i,j) = addition;
    }
	
  return result;
}

Matrix<double, Dynamic, Dynamic> SymMat::operator*(const Matrix<double, Dynamic, Dynamic> &m) const {
  if (m.rows() != m.cols() && m.rows() != this->getSize())
    throw invalid_argument("Matrix param has different size");
  
  Matrix<double, Dynamic, Dynamic> result(this->getSize(),this->getSize());

  for (size_t i=0; i<this->getSize(); ++i)
    for (size_t j=0; j<this->getSize(); ++j) {
      double addition = 0;
      for (size_t k=0; k<this->getSize(); ++k)
	addition += (*this)(i,k) * m(k,j);
      result(i,j) = addition;
    }
	
  return result;
}

bool SymMat::operator==(const SymMat& m) const{
  return this->getVector() == m.getVector();
}

vector<double> SymMat::getVector() const {
  return this->m;
}

size_t SymMat::getSize() const {
  return this->size;
}

double SymMat::operator()(size_t i, size_t j) const{
  if ((i+1) > this->getSize())
    throw invalid_argument(" Invalid row number");
  else if ((j+1) > this->getSize())
    throw invalid_argument(" Invalid col number");
  
  // Check README on GitHub for information about this calculation
  if (i <= j) return this->m[(((2*this->getSize())-(i-1))*i)/2+(j-i)];
  else return this->m[(((2*this->getSize())-(j-1))*j)/2+(i-j)];
}

Matrix<double, Dynamic, Dynamic> SymMat::getAsEigenMatrix() const{
  size_t m_size = this->getSize();
  Matrix<double, Dynamic, Dynamic> m(m_size,m_size);
    
  for (size_t i=0; i<m_size; ++i)
    for(size_t j=0; j<m_size; ++j)
      m(i,j) = (*this)(i,j);

  return m;
}
