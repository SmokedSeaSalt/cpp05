#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm
{
    public:
        AForm(std::string name, int gradeToSign, int GradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm() = 0;

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

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif // AFORM_HPP
