#include <iostream>
#include <cstdlib>
#include "lt/language_tools.hpp"

bool const test_string_contains()
{
	bool result = true;
	result &= lt::string_contains("Ryan Ward Kelley", "Kelley")==true;
	result &= lt::string_contains("Ryan Ward Kelley", "kelley")==false;
	return result;
}

int main()
{
    std::cout << "testing lt::language_tools..." << std::endl;

	bool result = true;
	result &= test_string_contains();
	return result ? EXIT_SUCCESS : EXIT_FAILURE;
}
