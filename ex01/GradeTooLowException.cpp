#include "GradeTooLowException.hpp"

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Bureaucrat: Grade too low!\n";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Form: Grade too low!\n";
}
