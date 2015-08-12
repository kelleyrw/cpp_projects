#include "lt/is_zero.hpp"
#include "lt/is_equal.hpp"

// ------------------------------------------------------------------------------------------------------------------ //
// lt::is_zero
// ------------------------------------------------------------------------------------------------------------------ //

bool lt::is_zero(int const value)
{
    return lt::is_equal(value, 0);
}

bool lt::is_zero(long int const value)
{
    return lt::is_equal(value, 0l);
}

bool lt::is_zero(float const value)
{
    return lt::is_equal(value, 0.0f);
}

bool lt::is_zero(double const value)
{
    return lt::is_equal(value, 0.0);
}

bool lt::is_zero(long double const value)
{
    return lt::is_equal(value, 0.0L);
}
