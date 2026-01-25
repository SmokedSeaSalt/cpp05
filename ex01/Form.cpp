#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
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
    : name_(other.name_), gradeRequiredToSign_(other.gradeRequiredToSign_),
      gradeRequiredToExecute_(other.gradeRequiredToExecute_), isSigned_(other.isSigned_)
{
}

Form& Form::operator=(const Form& other)
{
    if (this == &other)
        return (*this);
    return (*this);
}

void beSigned(const Bureaucrat& bureaucrat) {}

bool getSigned() {}

int getGradeRequiredToSign() {}

int getGradeRequiredToExecute() {}

std::ostream& operator<<(std::ostream& os, const Form& form) {}
