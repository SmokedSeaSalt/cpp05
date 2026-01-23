#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

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

    private:
        const std::string name_;
        int               grade_;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bc);

#endif // BUREAUCRAT_HPP
