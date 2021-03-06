#include <tmpl/example.hpp>

using LIB_NAMESPACE::example;
using std::string;
using std::ostream;

example::example() = default;

example::example(string dta) : data(std::move(dta)){}

ostream& LIB_NAMESPACE::operator<<(ostream &os, const example& ex)
{
	os << ex.data;
	return os;
}	
