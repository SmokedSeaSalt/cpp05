#include "Bureaucrat.hpp"
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

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade too high!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade too low!\n";
}
