#include <tmpl/example.hpp>

using tmpl::example;
using std::string;
using std::ostream;

example::example() = default;

example::example(string dta) : data(std::move(dta)){}

#ifndef SOMELIB_NO_DEPRECATED
void example::func() {}
#endif

ostream& tmpl::operator<<(ostream &os, const example& ex)
{
	os << ex.data;
	return os;
}	
