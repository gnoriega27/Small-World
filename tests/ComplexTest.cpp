#include "ComplexTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( ComplexTest );

void ComplexTest::Equality()
{
    CPPUNIT_ASSERT( *c1 == *c2 );
    CPPUNIT_ASSERT( Complex( 1, 1 ) == Complex( 1, 1 ) );
    CPPUNIT_ASSERT( Complex( 1, 1 ) != Complex( 2, 2 ) );
}

void ComplexTest::ScalarMultiply()
{
    CPPUNIT_FAIL( "Not yet implemented" );
}
void ComplexTest::Addition()
{
    CPPUNIT_FAIL( "Not yet implemented" );
}
void ComplexTest::Multiplication()
{
    CPPUNIT_FAIL( "Not yet implemented" );
}
