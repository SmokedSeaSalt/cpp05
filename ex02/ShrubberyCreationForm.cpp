#include "ShrubberyCreationForm.hpp"
#include "terminalOutput.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("RobotomyRequest", 72, 45), target_(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm("PresidentialPardon", 72, 45), target_(other.target_)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this == &other)
        return (*this);
    this->target_ = other.target_;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (AForm::getIsSigned() == false)
    {
        std::cout << C_RED << "Form " << AForm::getName() << " is not yet signed!\n" << C_END;
    }
    else
    {
        // put tree in file
    }
}