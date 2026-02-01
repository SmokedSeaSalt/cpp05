#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "terminalOutput.hpp"
#include <iostream>

int main(void)
{
    std::cout << C_YELLOW << "\nTest valid execution\n" << C_END;
    try
    {
        Bureaucrat b("Test", 1);
        AForm*     forma = new PresidentialPardonForm("TestTarget");
        AForm*     formb = new RobotomyRequestForm("TestTarget");
        AForm*     formc = new ShrubberyCreationForm("TestTarget");
        b.signForm(*forma);
        b.signForm(*formb);
        b.signForm(*formc);
        b.executeForm(*forma);
        b.executeForm(*formb);
        b.executeForm(*formb);
        b.executeForm(*formb);
        b.executeForm(*formb);
        b.executeForm(*formc);

        delete forma;
        delete formb;
        delete formc;
    }
    catch (std::exception& e)
    {
        std::cout << C_RED << e.what() << C_END;
    }
    std::cout << C_YELLOW << "\nTest invalid execution\n" << C_END;
    try
    {
        Bureaucrat b("Sign", 1);
        Bureaucrat c("Execute", 150);

        AForm* forma = new PresidentialPardonForm("TestTarget");
        b.signForm(*forma);
        c.executeForm(*forma);
        delete forma;
    }
    catch (std::exception& e)
    {
        std::cout << C_RED << e.what() << C_END;
    }

    try
    {
        Bureaucrat b("Sign", 1);
        Bureaucrat c("Execute", 150);

        AForm* forma = new RobotomyRequestForm("TestTarget");
        b.signForm(*forma);
        c.executeForm(*forma);
        delete forma;
    }
    catch (std::exception& e)
    {
        std::cout << C_RED << e.what() << C_END;
    }

    try
    {
        Bureaucrat b("Sign", 1);
        Bureaucrat c("Execute", 150);

        AForm* forma = new ShrubberyCreationForm("TestTarget");
        b.signForm(*forma);
        c.executeForm(*forma);
        delete forma;
    }
    catch (std::exception& e)
    {
        std::cout << C_RED << e.what() << C_END;
    }

}
