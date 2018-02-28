#include "SymMatTest.h"
#include "SymMat.h"

using namespace std;

void SymMatTest::runTest() {
  // Creating some example matrices
  MatrixXd M(3,3);
  M << 1,2,3,
       2,5,6,
       3,6,9;

  MatrixXd N(3,3);
  N << 2,4,3,
       4,5,7,
       3,7,9;

  MatrixXd O(3,4);
  O << 2,4,3,1,
       4,5,7,2,
       3,7,9,3;
   
  SymMat m(M);
  SymMat n = {N(0,0), N(0,1), N(0,2),
	              N(1,1), N(1,2),
	                      N(2,2)};

  // 1. Adding test SymMat-SymMat
  SymMat r11 = m+n;

  MatrixXd R12(3,3);
  R12 << 3,6,6,
         6,10,13,
         6,13,18;
  
  SymMat r12(R12);
  CPPUNIT_ASSERT(r11==r12);

  // 2. Adding test SymMat-Eigen::Matrix
  Matrix<double,Dynamic,Dynamic> R21 = m+N;

  MatrixXd R22(3,3);
  R22 << 3,6,6,
         6,10,13,
         6,13,18;

  CPPUNIT_ASSERT(R21==R22);

  // 3. Subtraction test SymMat-SymMat

  SymMat r31 = m-n;

  MatrixXd R32(3,3);
  R32 << -1,-2,0,
         -2,0,-1,
          0,-1,0;
  
  SymMat r32(R32);
  CPPUNIT_ASSERT(r31==r32);

  // 4. Subtraction test SymMat-Eigen::Matrix
  Matrix<double,Dynamic,Dynamic> R41 = m-N;

  MatrixXd R42(3,3);
  R42 << -1,-2,0,
         -2,0,-1,
         0,-1,0;

  CPPUNIT_ASSERT(R41==R42);

  // 5. Multiplication test SymMat-SymMat
  MatrixXd R51 = m*n;
  
  MatrixXd R52(3,3);
  R52 << 19,35,44,
         42,75,95,
         57,105,132;

  CPPUNIT_ASSERT(R51 == R52);


  // 6. Multiplication test SymMat-Eigen::Matrix
  MatrixXd R61 = m*N;

  MatrixXd R62(3,3);
  R62 << 19,35,44,
         42,75,95,
         57,105,132;
  
  CPPUNIT_ASSERT(R61 == R62);


  // Size test
  CPPUNIT_ASSERT(n.getSize() == 3);

  // Accessor tests
  CPPUNIT_ASSERT(n(0,1) == n(1,0));
  CPPUNIT_ASSERT(n(1,1) == n(1,1));
  CPPUNIT_ASSERT(n(2,0) == n(0,2));
  CPPUNIT_ASSERT(n(2,1) == n(1,2));
}
