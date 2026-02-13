#include "ShrubberyCreationForm.hpp"
#include "terminalOutput.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137), target_("")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreation", 145, 137), target_(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm("ShrubberyCreation", 145, 137), target_(other.target_)
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
        //check bureaucrat grade to form execute grade
        if (executor.getGrade() > AForm::getGradeRequiredToExecute())
            throw AForm::GradeTooLowException();
        std::ofstream file;

        file.open(target_ + "_shrubbery");
        if (!file.is_open())
        {
            std::cout << C_RED << "File creation error!\n" << C_END;
            return;
        }
        file << TREE_STRING;
        file.close();
    }
}
