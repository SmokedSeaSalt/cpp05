#ifndef GRADETOOHIGHEXCEPTION_HPP
#define GRADETOOHIGHEXCEPTION_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

class Bureaucrat::GradeTooHighException : public std::exception
{
    public:
        const char* what() const noexcept override;
};

class Form::GradeTooHighException : public std::exception
{
    public:
        const char* what() const noexcept override;
};

#endif //GRADETOOHIGHEXCEPTION_HPP
