#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form
{
    public:
        Form(std::string name, int gradeToSign, int GradeToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        void beSigned(const Bureaucrat& bureaucrat);

        std::string getName() const;
        bool        getIsSigned() const;
        int         getGradeRequiredToSign() const;
        int         getGradeRequiredToExecute() const;

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
        bool              isSigned_;
        const int         gradeRequiredToSign_;
        const int         gradeRequiredToExecute_;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif // FORM_HPP
