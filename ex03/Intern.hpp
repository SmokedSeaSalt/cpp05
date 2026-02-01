#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

#define INTERN_LOOKUP_SIZE 3

class Intern;

struct formTable
{
        std::string name;
        AForm* (Intern::*funcp)(std::string formTarget);
};

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm* makeForm(std::string formName, std::string formTarget);

        class IncorrectArgument : public std::exception
        {
            public:
                const char* what() const noexcept override;
        };

    private:
        AForm* makePresidential(std::string formTarget);
        AForm* makeRobotomy(std::string formTarget);
        AForm* makeShrubbery(std::string formTarget);

        const static formTable lookupTable_[INTERN_LOOKUP_SIZE];
};

#endif // INTERN_HPP
