#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "terminalOutput.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, const int& grade) : name_(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    grade_ = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name_(other.name_), grade_(other.grade_) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this == &other)
        return (*this);
    this->grade_ = other.grade_;
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return name_;
}

int Bureaucrat::getGrade() const
{
    return grade_;
}

void Bureaucrat::incrementGrade()
{
    if ((grade_ - 1) < 1)
        throw GradeTooHighException();
    std::cout << C_BLUE << name_ << ": grade incremented from " << grade_;
    grade_--;
    std::cout << " to " << grade_ << ".\n" << C_END;
}

void Bureaucrat::decrementGrade()
{
    if ((grade_ + 1) > 150)
        throw GradeTooLowException();
    std::cout << C_BLUE << name_ << ": grade decremented from " << grade_;
    grade_++;
    std::cout << " to " << grade_ << ".\n" << C_END;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bc)
{
    std::cout << C_BLUE << bc.getName() << ", bureaucrat grade " << bc.getGrade() << ".\n" << C_END;
    return os;
}

void Bureaucrat::signForm(AForm& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << C_GREEN << this->name_ << " signed " << form.getName() << C_END << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << C_RED << this->name_ << " couldn't sign " << form.getName() << " because " << e.what() << C_END << '\n';
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << C_GREEN << this->name_ << " executed " << form.getName() << C_END << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << C_RED << this->name_ << " couldn't execute " << form.getName() << " because " << e.what() << C_END << '\n';
    }
}


const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Bureaucrat: Grade too high!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Bureaucrat: Grade too low!\n";
}
