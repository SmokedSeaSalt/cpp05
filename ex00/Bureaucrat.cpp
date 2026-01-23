#include "Bureaucrat.hpp"
#include <iostream>
#include "terminalOutput.hpp"

Bureaucrat::Bureaucrat(const std::string& name, const int& grade) : name_(name), grade_(grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name_(other.name_), grade_(other.grade_)  {}

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
	grade_--;
}

void Bureaucrat::decrementGrade()
{
	grade_++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bc)
{
	std::cout << C_BLUE << bc.getName() << ", bureaucrat grade " << bc.getGrade() << ".\n" << C_END;
	return os;
}
