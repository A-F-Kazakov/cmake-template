#ifndef TMPL_LIB_EXAMPLE_HPP
#define TMPL_LIB_EXAMPLE_HPP

#include <Tmpl.hpp>
#include <ostream>
#include <string>

namespace LIB_NAMESPACE
{
	/**
	 * \brief meaningless writer object
	 *
	 * This is more complex and exaustive description of this class
	 */
	struct TMPL_EXPORT example
	{
		/**
		 * \effects Creates the default example object
		 */
		example();

		/**
		 * \effects creates example instance with specified string
		 */
		example(std::string);

		friend TMPL_EXPORT std::ostream& operator<<(std::ostream&, const example&);

	  private:
		std::string data;
	};

	/**
	 * \brief example stream operator
	 *
	 * prints underlying data to specific stream
	 *
	 * \param os specific output stream
	 *
	 * \param exmpl instance of the example
	 *
	 * \returns same output stream
	 */
	TMPL_EXPORT std::ostream& operator<<(std::ostream& os, const example& exmpl);
} // namespace LIB_NAMESPACE

#endif
