#include "PresidentialPardonForm.hpp"
#include "terminalOutput.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardon", 25, 5), target_(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm("PresidentialPardon", 25, 5), target_(other.target_)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this == &other)
        return (*this);
    this->target_ = other.target_;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
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
        std::cout << C_GREEN << "Informs that " << target_
                  << " has been pardoned by Zaphod Beeblebrox.\n"
                  << C_END;
    }
}
