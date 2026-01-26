#include "GradeTooHighException.hpp"

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Bureaucrat: Grade too high!\n";
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Form: Grade too high!\n";
}
