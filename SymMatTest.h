#ifndef SYMMATTEST_H
#define SYMMATTEST_H

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

using namespace std;

class SymMatTest : public CppUnit::TestCase {
 public:
 SymMatTest( string name ) : CppUnit::TestCase( name ) {}

  void runTest();
};

#endif
