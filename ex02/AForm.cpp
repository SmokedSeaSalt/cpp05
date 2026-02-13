#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "terminalOutput.hpp"
#include <string>

AForm::AForm() : gradeRequiredToSign_(0), gradeRequiredToExecute_(0) {}

AForm::AForm(std::string name, int gradeToSign, int GradeToExecute)
    : name_(name), gradeRequiredToSign_(gradeToSign), gradeRequiredToExecute_(GradeToExecute)
{
    isSigned_ = false;
    if (gradeRequiredToSign_ < 1 || gradeRequiredToExecute_ < 1)
        throw GradeTooHighException();
    if (gradeRequiredToSign_ > 150 || gradeRequiredToExecute_ > 150)
        throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& other)
    : name_(other.name_), isSigned_(other.isSigned_), gradeRequiredToSign_(other.gradeRequiredToSign_),
      gradeRequiredToExecute_(other.gradeRequiredToExecute_)
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this == &other)
        return (*this);
    return (*this);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= this->gradeRequiredToSign_)
    {
        this->isSigned_ = true;
    }
    else
        throw GradeTooLowException();
}

std::string AForm::getName() const
{
    return name_;
}

bool AForm::getIsSigned() const
{
    return isSigned_;
}

int AForm::getGradeRequiredToSign() const
{
    return gradeRequiredToSign_;
}

int AForm::getGradeRequiredToExecute() const
{
    return gradeRequiredToExecute_;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    std::cout << C_BLUE << "AForm: " << form.getName() << "\n"
              << "Signed: " << std::boolalpha << form.getIsSigned() << std::noboolalpha << "\n"
              << "Grade to sign: " << form.getGradeRequiredToSign() << "\n"
              << "Grade to execute: " << form.getGradeRequiredToExecute() << "\n" << C_END;
    return os;
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "AForm: Grade too high!\n";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "AForm: Grade too low!\n";
}
