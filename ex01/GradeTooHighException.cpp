#include "GradeTooHighException.hpp"

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade too high!\n";
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Grade too high!\n";
}
