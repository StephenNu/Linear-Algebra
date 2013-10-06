#ifndef DIMENSION_TO_HIGH_EXCEPTION_H
#define DIMENSION_TO_HIGH_EXCEPTION_H
#include <exception>

class dimension_to_high_exception : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "dimension is to high for that operation";
		}
};
#endif
