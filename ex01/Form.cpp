#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "terminalOutput.hpp"
#include <string>

Form::Form(std::string name, int gradeToSign, int GradeToExecute)
    : name_(name), gradeRequiredToSign_(gradeToSign), gradeRequiredToExecute_(GradeToExecute)
{
    isSigned_ = false;
    if (gradeRequiredToSign_ < 1 || gradeRequiredToExecute_ < 1)
        throw GradeTooHighException();
    if (gradeRequiredToSign_ > 150 || gradeRequiredToExecute_ > 150)
        throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& other)
    : name_(other.name_), isSigned_(other.isSigned_), gradeRequiredToSign_(other.gradeRequiredToSign_),
      gradeRequiredToExecute_(other.gradeRequiredToExecute_)
{
}

Form& Form::operator=(const Form& other)
{
    if (this == &other)
        return (*this);
    return (*this);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= this->gradeRequiredToSign_)
    {
        this->isSigned_ = true;
        std::cout << C_GREEN << bureaucrat.getName() << " signed " << this->name_ << C_END << "\n";
    }
    else
        throw GradeTooLowException();
}

std::string Form::getName() const
{
    return name_;
}

bool Form::getIsSigned() const
{
    return isSigned_;
}

int Form::getGradeRequiredToSign() const
{
    return gradeRequiredToSign_;
}

int Form::getGradeRequiredToExecute() const
{
    return gradeRequiredToExecute_;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    std::cout << C_BLUE << "Form: " << form.getName() << "\n"
              << "Signed: " << std::boolalpha << form.getIsSigned() << std::noboolalpha << "\n"
              << "Grade to sign: " << form.getGradeRequiredToSign() << "\n"
              << "Grade to execute: " << form.getGradeRequiredToExecute() << "\n" << C_END;
    return os;
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Form: Grade too high!\n";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Form: Grade too low!\n";
}
