#include "RobotomyRequestForm.hpp"
#include "terminalOutput.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequest", 72, 45), target_(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm("PresidentialPardon", 72, 45), target_(other.target_)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this == &other)
        return (*this);
    this->target_ = other.target_;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (AForm::getIsSigned() == false)
        std::cout << C_RED << "Form " << AForm::getName() << " is not yet signed!\n" << C_END;
    else
    {
        //check bureaucrat grade to form execute grade
        if (executor.getGrade() > AForm::getGradeRequiredToExecute())
            throw AForm::GradeTooLowException();
        std::cout << C_BLUE << "Brrrrrr.... ";
        if (rand() % 2)
            std::cout << target_ << "robotomy failed.\n" << C_END;
        else
            std::cout << target_ << "robotomy succesful.\n" << C_END;
    }
}