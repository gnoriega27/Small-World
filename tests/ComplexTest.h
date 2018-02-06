#ifndef COMPLEXTEST_H_
#define COMPLEXTEST_H_

#include "testsuite.h"

#include <project/math/complex.h>

using namespace Math;

class ComplexTest : public TestFixture
{
    CPPUNIT_TEST_SUITE( ComplexTest );
    CPPUNIT_TEST( Equality );
    CPPUNIT_TEST( ScalarMultiply );
    CPPUNIT_TEST( Addition );
    CPPUNIT_TEST( Multiplication );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
        c1 = new Complex( 1, 1 );
        c2 = new Complex( 1, 1 );
        c3 = new Complex( 2, 2 );
    }

    void tearDown()
    {
    }

    void Equality();
    void ScalarMultiply();
    void Addition();
    void Multiplication();

private:
    Complex* c1;
    Complex* c2;
    Complex* c3;
};

#endif // COMPLEXTEST_H_
