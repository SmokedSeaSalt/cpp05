#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
//#include "GradeTooHighException.hpp"
//#include "GradeTooLowException.hpp"

class Bureaucrat
{
    public:
        Bureaucrat(const std::string& name, const int& grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        std::string getName() const;
        int         getGrade() const;
        void        incrementGrade();
        void        decrementGrade();

        //exception classes
        class GradeTooHighException;
        class GradeTooLowException;

    private:
        const std::string name_;
        int               grade_;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bc);

#endif // BUREAUCRAT_HPP
