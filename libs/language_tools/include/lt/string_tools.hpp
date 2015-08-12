#ifndef LT_STRINGTOOL_HPP
#define LT_STRINGTOOL_HPP

#include <string>
#include <vector>
#include <utility>

namespace lt
{
    // ============================================================================================================== //

    // does str contains sub_str?
    bool string_contains(std::string const &str, std::string const &sub_str);

    // remove all occurrences of sub_str from str
    std::string string_remove_all(std::string const &str,  std::string const &sub_str);

    // replace all occurrences of sub_str from str with new_sub_str
    std::string string_replace_all(std::string const &str, std::string const &sub_str, std::string const &new_sub_str);

    // replace first occurrences of sub_str from str with new_sub_str
    std::string string_replace_first(std::string const &str,  std::string const &sub_str,  std::string const &new_sub_str);

    // replace last occurrences of sub_str from str with new_sub_str
    std::string string_replace_last(std::string const &str,  std::string const &sub_str,  std::string const &new_sub_str);

    // replace all upper case characters to lower case 
    std::string string_lower(std::string const &str);

    // replace all lower case characters to upper case 
    std::string string_upper(std::string const &str);

    // convert to double/float/int
    double string_to_double(std::string const &str);
    float string_to_float(std::string const &str);
    int string_to_int(std::string const &str);

    // split the string into a vector of string based on the deliminator 
    std::vector<std::string> string_split(std::string const &str, std::string const &delim = ",");

    // join the string into a delim seperated list 
    std::string string_join(std::vector<std::string> const &str_vector, std::string const &delim = ",");

    // return string formated 
    std::string string_format(char const * const format, ...);
    std::string string_format(std::string const &format, ...);

    // -------------------------------------------------------------------------------------------------------------- //

    // character is space
    bool is_space(char const c);

    // character is not a space
    bool not_space(char const c);

    // -------------------------------------------------------------------------------------------------------------- //

    // print the value/error with +/-
    std::string pm(double const value, double const error, std::string const &precision = "1.2");
    std::string pm(std::pair<double, double> const &value_pair, std::string const &precision = "1.2");
    std::string pm(std::pair<float, float> const &value_pair, std::string const &precision = "1.2");

    // print the value/error with +/- in latex
    std::string pm_latex(double const value, double const error, std::string const &precision = "1.2");
    std::string pm_latex(std::pair<double, double> const &value_pair, std::string const &precision = "1.2");
    std::string pm_latex(std::pair<float, float> const &value_pair, std::string const &precision = "1.2");

    // ============================================================================================================== //

} // namespace lt

#endif // LT_STRINGTOOLS_HPP
