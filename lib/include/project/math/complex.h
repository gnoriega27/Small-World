#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <project/common.h>
#include <cmath>

namespace Math
{
    //! @brief a class to represent the complex number system
    class Complex
    {
    public:
        //! @brief Default constructor, creates the number (1, 0)
        Complex();

        //! @brief Creates a complex number from rectangular coordinates
        //! @param[in] x The x coordinate
        //! @param[in] y The y coordinate
        Complex( long double x, long double y );

        //! @brief Compare two complex numbers
        bool operator==( const Complex& other );
        //! @brief Compare two complex numbers
        bool operator!=( const Complex& other );

        //! @brief Add two compelx numbers
        Complex& operator+( const Complex& other );

    private:
        // Rectangular coordinates
        long double x;
        long double y;

        // Polar coordinates
        long double r;
        long double arg;
    };
}

#endif // COMPLEX_H_
