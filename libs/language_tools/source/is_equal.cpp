#include "lt/is_equal.hpp"
#include <cstdlib>
#include <cmath>

// ------------------------------------------------------------------------------------------------------------------ //
// lt::is_equal
// ------------------------------------------------------------------------------------------------------------------ //

bool lt::is_equal(int const lhs, int const rhs)
{
    return lhs == rhs;
}

bool lt::is_equal(long int const lhs, long int const rhs)
{
    return lhs == rhs;
}

bool lt::is_equal(float const lhs, float const rhs)
{
    float const relative_tolerance = 0.00001f;
    float const absolute_tolerance = 0.000001f;
    return is_equal(lhs, rhs, relative_tolerance, absolute_tolerance);
}

bool lt::is_equal(double const lhs, double const rhs)
{
    double const relative_tolerance = 0.00001;
    double const absolute_tolerance = 0.000001;
    return is_equal(lhs, rhs, relative_tolerance, absolute_tolerance);
}

bool lt::is_equal(const long double lhs, const long double rhs)
{
    const long double relative_tolerance = 0.00001L;
    const long double absolute_tolerance = 0.000001L;
    return is_equal(lhs, rhs, relative_tolerance, absolute_tolerance);
}

bool lt::is_equal(float const lhs, float const rhs, float const relative_tolerance, float const absolute_tolerance)
{
    return fabs(rhs - lhs) <= (relative_tolerance * (fabs(lhs) + fabs(rhs)) + absolute_tolerance);
}

bool lt::is_equal(double const lhs, double const rhs, double const relative_tolerance, double const absolute_tolerance)
{
    return fabs(rhs - lhs) <= (relative_tolerance * (fabs(lhs) + fabs(rhs)) + absolute_tolerance);
}

bool lt::is_equal(const long double lhs, const long double rhs, const long double relative_tolerance, const long double absolute_tolerance)
{
    return fabs(rhs - lhs) <= (relative_tolerance * (fabs(lhs) + fabs(rhs)) + absolute_tolerance);
}
