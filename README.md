# SymMat Class for ATLASEigen EvalTest Project
SymMat is a class to do some basic operations with Symmetric matrices, only storing the upper triangular part of the matrix.

This project is the evaluation test required by ATLAS project from CERN for GSoC 2018. More information: https://github.com/StewMH/GSoC2018/blob/master/evaluation_test.pdf

## How to compile?
Using `g++`, you have to run:
```bash
g++ -std=c++11 -I /path/to/Eigen -lcppunit main.cpp SymMat.cpp SymMatTest.cpp -o SymMatTest
```

*Note 1: You need to have Eigen installed: http://eigen.tuxfamily.org/index.php?title=Main_Page*
*Note 2: On Debian, for example, the default path of Eigen is /usr/include/eigen3*
*Note 3: You need to have cppunit installed: http://cppunit.sourceforge.net/doc/cvs/cppunit_cookbook.html*

## Algorithm notes
Please check Wiki for information about some calculation done on the code to solve the problem.

## Doubts about the Evaluation Test PDF
* On multiplications, you can multiply matrices with different dimentions, not only squared matrices. For example:
If N is a matrix with size mxn and M a matrix with size pxq, and m is not equal to n and p is not equal to q, you can do NxM if n is equal to p.
On the PDF is said that matrices must have same dimensions, understood as same rows and cols.
* Also, multiplication operator is not commutative, because operation order is defined on the PDF. In other operations like minus, it is like this too.

## Future work
* Add more tests and refactor tests and data.
* Check run time in order to improve calculations.
* Refactor some common code in methods.
