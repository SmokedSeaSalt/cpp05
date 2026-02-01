#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "terminalOutput.hpp"
#include <iostream>

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this == &other)
        return (*this);
    return (*this);
}

const formTable Intern::lookupTable_[] = {
    {"PresidentialPardon", &Intern::makePresidential},
    {"RobotomyRequest", &Intern::makeRobotomy},
    {"ShrubberyCreation", &Intern::makeShrubbery},
};

AForm* Intern::makePresidential(std::string formTarget)
{
    return (new PresidentialPardonForm(formTarget));
}

AForm* Intern::makeRobotomy(std::string formTarget)
{
    return (new RobotomyRequestForm(formTarget));
}

AForm* Intern::makeShrubbery(std::string formTarget)
{
    return (new ShrubberyCreationForm(formTarget));
}

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
    for (int i = 0; i < INTERN_LOOKUP_SIZE; i++)
    {
        if (formName == this->lookupTable_[i].name)
        {
            AForm* ret = (this->*lookupTable_[i].funcp)(formTarget);
            std::cout << C_GREEN << "Intern creates " << formName << "\n" << C_END;
            return (ret);
        }
    }
    std::cout << C_RED << "No form found with name: " << formName << "\n" << C_END;
    throw IncorrectArgument();
}

const char* Intern::IncorrectArgument::what() const noexcept
{
	return "Intern: Incorrect argument provided!\n";
}
