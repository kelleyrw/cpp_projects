#ifndef LT_IS_EQUAL_HPP
#define LT_IS_EQUAL_HPP

namespace lt
{
    // ============================================================================================================== //
    bool is_equal(int const lhs, int const rhs);
    bool is_equal(long int const lhs, long int const rhs);
    bool is_equal(float const lhs, float const rhs);
    bool is_equal(double const lhs, double const rhs);
    bool is_equal(const long double lhs, const long double rhs);
    bool is_equal(float const lhs, float const rhs, float const relative_tolerance, float const absolute_tolerance);
    bool is_equal(double const lhs, double const rhs, double const relative_tolerance, double const absolute_tolerance);
    bool is_equal(const long double lhs, const long double rhs, const long double relative_tolerance, const long double absolute_tolerance);

    // ============================================================================================================== //

} // namespace lt

#endif // LT_IS_EQUAL_HPP
