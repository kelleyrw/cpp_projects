#include "lt/string_tools.hpp"
#include "boost/algorithm/string.hpp"
#include "boost/lexical_cast.hpp"
#include <cstdarg>
#include <cstdio>

// ------------------------------------------------------------------------------------------------------------------ //
// lt::string_tools
// ------------------------------------------------------------------------------------------------------------------ //

bool lt::string_contains(std::string const &str, std::string const &sub_str)
{
    return std::string::npos != str.find(sub_str);
}

std::string lt::string_remove_all(std::string const &str, std::string const &sub_str)
{
    std::string result(str);
    while(string_contains(result, sub_str))
    {
        size_t pos = result.find(sub_str);
        result.erase(pos, sub_str.size());
    }
    return result;
}

std::string lt::string_replace_all(std::string const &str, std::string const &sub_str, std::string const &new_sub_str)
{
    std::string result(str);
    boost::replace_all(result, sub_str, new_sub_str); 
    return result;
}

std::string lt::string_replace_first(std::string const &str,  std::string const &sub_str,  std::string const &new_sub_str)
{
    std::string result(str);
    boost::replace_first(result, sub_str, new_sub_str); 
    return result;
}

std::string lt::string_replace_last(std::string const &str,  std::string const &sub_str,  std::string const &new_sub_str)
{
    std::string result(str);
    boost::replace_first(result, sub_str, new_sub_str); 
    return result;
}


std::string lt::string_lower(std::string const &str)
{
    std::string result(str);
    boost::to_lower(result);
    return result;
}

std::string lt::string_upper(std::string const &str)
{
    std::string result(str);
    boost::to_upper(result);
    return result;
}

float lt::string_to_float(std::string const &str)
{
    return boost::lexical_cast<float>(str);
}
double lt::string_to_double(std::string const &str)
{
    return boost::lexical_cast<double>(str);
}

int lt::string_to_int(std::string const &str)
{
    return boost::lexical_cast<int>(str);
}

std::vector<std::string> lt::string_split(std::string const &str, std::string const &delim)
{
    std::vector<std::string> str_vector;
    boost::split(str_vector, str, boost::is_any_of(delim));
    return str_vector; 
}

std::string lt::string_join(std::vector<std::string> const &str_vector, std::string const &delim)
{
    std::string result = boost::join(str_vector, delim);
    return result; 
}

std::string lt::string_format(char const * const format, ...)
{
    va_list vl;
    va_start(vl, format);
    char * temp = nullptr;
    vasprintf(&temp, format, vl);
    va_end(vl);
    std::string result(temp);
    free(temp);
    return result;
}

std::string lt::string_format(std::string const &format, ...)
{
    return lt::string_format(format.c_str());
}

// ------------------------------------------------------------------------------------------------------------------ //

bool lt::is_space(char const c)
{
    return static_cast<bool>(isspace(c));
}

bool lt::not_space(char const c)
{
    return !is_space(c);
}

// ------------------------------------------------------------------------------------------------------------------ //

std::string lt::pm(double const value, double const error, std::string const &precision)
{
    std::string format_string = "%" + precision + "f +/- %" + precision +"f";
    return std::string(string_format(format_string, value, error));
}

std::string lt::pm(std::pair<double, double> const &value_pair, std::string const &precision)
{
    std::string format_string = "%" + precision + "f +/- %" + precision +"f";
    return std::string(string_format(format_string, value_pair.first, value_pair.second));
}

std::string lt::pm(std::pair<float, float> const &value_pair, std::string const &precision)
{
    std::string format_string = "%" + precision + "f +/- %" + precision +"f";
    return std::string(string_format(format_string, value_pair.first, value_pair.second));
}

// print value and error with +/- in latex
// ------------------------------------------------------------------------------------------------------------------ //

std::string lt::pm_latex(double const value, double const error, std::string const &precision)
{
    std::string format_string = "%" + precision + "f $\\pm$ %" + precision +"f";
    return std::string(string_format(format_string, value, error));
}

std::string lt::pm_latex(std::pair<double, double> const &value_pair, std::string const &precision)
{
    std::string format_string = "%" + precision + "f $\\pm$ %" + precision +"f";
    return std::string(string_format(format_string, value_pair.first, value_pair.second));
}

std::string lt::pm_latex(std::pair<float, float> const &value_pair, std::string const &precision)
{
    std::string format_string = "%" + precision + "f $\\pm$ %" + precision +"f";
    return std::string(string_format(format_string, value_pair.first, value_pair.second));
}
