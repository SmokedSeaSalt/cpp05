#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "terminalOutput.hpp"
#include <iostream>

int main(void)
{
    std::cout << C_YELLOW << "\nTest valid grades\n" << C_END;
    try
    {
        Bureaucrat b("Test", 50);
        Form f("TestForm", 140, 130);
        std::cout << f;
        f.beSigned(b);
        std::cout << f;
    }
    catch (std::exception& e)
    {
        std::cout << C_RED << e.what() << C_END;
    }

    std::cout << C_YELLOW << "\nTest invalid constructor grades\n" << C_END;
    try
    {
        Form f("TestForm", 0, 10);
    }
    catch (std::exception& e)
    {
        std::cout << C_RED << e.what() << C_END;
    }

    try
    {
        Form f("TestForm", 10, 0);
    }
    catch (std::exception& e)
    {
        std::cout << C_RED << e.what() << C_END;
    }

    try
    {
        Form f("TestForm", 151, 10);
    }
    catch (std::exception& e)
    {
        std::cout << C_RED << e.what() << C_END;
    }

    try
    {
        Form f("TestForm", 10, 151);
    }
    catch (std::exception& e)
    {
        std::cout << C_RED << e.what() << C_END;
    }

    std::cout << C_YELLOW << "\nTest invalid signing\n" << C_END;
    try
    {
        Bureaucrat invalid("Invalid", 100);
        Form f("TestForm", 99, 130);
        std::cout << f;
        invalid.signForm(f);
        std::cout << f;
    }
    catch (std::exception& e)
    {
        std::cout << C_RED << e.what() << C_END;
    }
}
