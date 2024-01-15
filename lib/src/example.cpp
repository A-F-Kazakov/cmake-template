#include <tmpl/example.hpp>

using tmpl::example;
using std::string;
using std::ostream;

example::example() = default;

example::example(string dta) : data(std::move(dta)){}

#ifndef TMPL_NO_DEPRECATED
std::string example::func() const { return "deprecated function"; }
#endif

ostream& tmpl::operator<<(ostream &os, const example& ex)
{
	os << ex.data;
	return os;
}	
