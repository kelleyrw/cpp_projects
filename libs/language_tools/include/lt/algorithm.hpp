#ifndef LT_ALGORITHM_HPP
#define LT_ALGORITHM_HPP

#include <vector>
#include <string>

namespace lt
{
    // ============================================================================================================== //

    // string of values for the array: {a, b, c, ...}
    // (elements of T must have << overloaded)
    template <typename T>
    std::string array_string(std::vector<T> const &v);

    template <typename T>
    std::string array_string(T const * const array, int const N);

    // -------------------------------------------------------------------------------------------------------------- //

    // filter the container
    template <typename Container, typename Predicate>
    Container filter_container(Container const &c, Predicate p);

    // combine containers 
    template <typename Container>
    Container concat_container(Container const &c1, Container const &c2);

    // delete all elements of a container
    template <typename Container>
    void delete_container(Container const &c);

    // initialize a container
    template <typename Container, typename Type>
    void init_container(Container const &c, Type const &t = Type());

    // ============================================================================================================== //

} // namespace lt

// ================================================================================================================== //
// implementation                                                                                                
// ================================================================================================================== //

#include <algorithm>
#include <sstream>
#include <cassert>

// ================================================================================================================== //

template <typename T>
std::string lt::array_string(std::vector<T> const& v)
{
    std::stringstream os;
    os << "{";
    for (size_t i = 0; i < v.size(); ++i)
    {
        os << v.at(i);
        if (i != (v.size() - 1)) os << ", ";
    }
    os << "}";
    return os.str();
}


template <typename T>
std::string lt::array_string(T const * const array, const int N)
{
    // test boundary conditions
    assert(!(array == NULL && N > 0));

    std::stringstream os;
    os << "{";
    for (int i = 0; i < N; ++i)
    {
        os << array[i];
        if (i != (N - 1)) os << ", ";
    }
    os << "}";
    return os.str();
}

// ------------------------------------------------------------------------------------------------------------------ //

template <typename Container, typename Predicate>
Container lt::filter_container(Container const &c, Predicate p)
{
    Container result;
    std::copy_if(c.begin(), c.end(), std::back_inserter(result), p);
    return result;
}

// combine containers 
template <typename Container>
Container lt::concat_container(Container const &c1, Container const &c2)
{
    Container result(c1);
    result.insert(c1.end(), c2.begin(), c2.end());
    return result;
}

// delete a pointer 
template <typename T>
struct delete_ptr : public std::unary_function<bool,T>
{
   bool operator()(T* ptr) const {delete ptr; return true;}
   bool operator()(T ptr ) const {delete ptr; return true;}
};

// delete the container
template <typename Container>
void lt::delete_container(Container const &c)
{
    std::for_each(c.begin(), c.end(), delete_ptr<typename Container::value_type>());
}

// initialze container
template <typename Container, typename Type>
void lt::init_container(Container const &c, const Type& t)
{
    std::for_each(c.begin(), c.end(), t);
}

// ================================================================================================================== //

#endif // LT_ALGORITHM_HPP
