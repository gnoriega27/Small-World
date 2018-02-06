#include <iostream>
#include <project/common.h>
#include <project/math/complex.h>

//! @brief main entry point of example application
int main()
{
    Math::Complex c( 10, 1 );
    Math::Complex d( 1, 1 );

    std::cout << ( c == d ) << std::endl;

    return 0;
}
