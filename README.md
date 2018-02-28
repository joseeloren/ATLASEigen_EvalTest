# SymMat Class for ATLASEigen EvalTest Project
SymMat is a class to do some basic operations with Symmetric matrixes, only storing the upper triangular part of the matrix.

This project is the evaluation test required by ATLAS project from CERN for GSoC 2018. More information: https://github.com/StewMH/GSoC2018/blob/master/evaluation_test.pdf

## How to compile?
Using G++, you have to run:
g++ -std=c++11 -I /path/to/Eigen -lcppunit main.cpp SymMat.cpp SymMatTest.cpp -o SysMatTest

*Note 1: You need to have Eigen installed: http://eigen.tuxfamily.org/index.php?title=Main_Page*
*Note 2: On Debian, for example, the default path of Eigen is /usr/include/eigen3*
*Note 3: You need to have cppunit installed: http://cppunit.sourceforge.net/doc/cvs/cppunit_cookbook.html*

# Algorithm notes
Please check Wiki for information about some calculation done on the code to solve the problem.


## Future work
* Check run time in order to improve calculations
* Refactor some common code in methods
