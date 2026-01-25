#ifndef GRADETOOLOWEXCEPTION_HPP
#define GRADETOOLOWEXCEPTION_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

class Bureaucrat::GradeTooLowException : public std::exception
{
    public:
        const char* what() const noexcept override;
};

class Form::GradeTooLowException : public std::exception
{
    public:
        const char* what() const noexcept override;
};

#endif //GRADETOOLOWEXCEPTION_HPP
