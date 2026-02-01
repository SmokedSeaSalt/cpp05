#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

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

        void signForm(AForm& form) const;
        void executeForm(AForm const & form) const;

        //exception classes
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const noexcept override;
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const noexcept override;
        };

    private:
        const std::string name_;
        int               grade_;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bc);

#endif // BUREAUCRAT_HPP
