#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
        Intern     i;

        AForm* forma = i.makeForm("PresidentialPardon", "targeta");
        AForm* formb = i.makeForm("RobotomyRequest", "targetb");
        AForm* formc = i.makeForm("ShrubberyCreation", "targetc");

        b.signForm(*forma);
        b.executeForm(*forma);
        b.signForm(*formb);
        b.executeForm(*formb);
        b.signForm(*formc);
        b.executeForm(*formc);

        delete forma;
        delete formb;
        delete formc;
    }
    catch (std::exception& e)
    {
        std::cout << C_RED << e.what() << C_END;
    }
    
    std::cout << C_YELLOW << "\nTest invalid form name\n" << C_END;
    try
    {
        Bureaucrat b("Test", 1);
        Intern     i;

        AForm* forma = i.makeForm("doesNotExist", "targeta");

        b.signForm(*forma);
        b.executeForm(*forma);

        delete forma;
    }
    catch (std::exception& e)
    {
        std::cout << C_RED << e.what() << C_END;
    }
}
