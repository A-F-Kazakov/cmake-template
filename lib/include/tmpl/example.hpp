/**
 * \file
 * \brief example class file desctiption
 *
 * This file contains example class that shows how deprecation and exportion works
 */

#ifndef TMPL_LIB_EXAMPLE_HPP
#define TMPL_LIB_EXAMPLE_HPP

#include <tmpl/exports.hpp>
#include <ostream>
#include <string>

namespace tmpl
{
	/**
	 * \author example
	 *
	 * \~russian
	 * \brief Бессмысленный класс писателя
	 * \bug Не должен содержать багов
	 * \warning Демонстационный класс
	 * \todo NA
	 *
	 * Детали
	 *
	 * \~english
	 * \brief meaningless writer object
	 * \bug Implementation should not have bugs
	 * \warning This class is for demonstration only
	 * \todo NA
	 */
	struct TMPL_EXPORT example
	{
		/**
		 * \brief Creates the default example object
		 *
		 * This is more complex and exaustive description of this class
		 * \f[
		 *  n! = \prod_{i = 1}^n i
		 * \f]
		 */
		example();

		/**
		 * \brief creates example instance with specified string
		 *
		 * Details
		 *
		 * \throw std::exception never throws this
		 *
		 * \~russian
		 * \param[in] str Данная строка будет выведена в поток
		 */
		example(std::string str);

#ifndef TMPL_NO_DEPRECATED
		/**
		 * \brief creates example instance with specified string
		 *
		 * \return implementation defined string
		 *
		 * \code
		 *   std::string func() const { return "something"; }
       * \endcode
		 */
		TMPL_DEPRECATED std::string func() const;
#endif

		friend TMPL_EXPORT std::ostream& operator<<(std::ostream&, const example&);

	  private:
		std::string data;
	};

	/**
	 * \brief example stream operator
	 *
	 * prints underlying data to specific stream
	 *
	 * \param[in,out] os specific output stream
	 * \param[in] exmpl instance of the example
	 *
	 * \return same output stream
	 */
	TMPL_EXPORT std::ostream& operator<<(std::ostream& os, const example& exmpl);


	TMPL_EXPORT std::ostream& operator<<(std::ostream& os, const example& exmpl);
} // namespace tmpl

#endif
