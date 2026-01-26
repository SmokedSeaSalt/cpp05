#include "Bureaucrat.hpp"
#include "terminalOutput.hpp"
#include <iostream>

int main(void)
{
    std::cout << C_YELLOW << "\nTest valid grades\n" << C_END;
    try
    {
        Bureaucrat valid("Valid", 100);
        valid.incrementGrade();
        valid.decrementGrade();
        std::cout << C_GREEN << valid << C_END;
    }
    catch (std::exception& e)
    {
        std::cout << C_RED << e.what() << C_END;
    }

    std::cout << C_YELLOW << "\nTest invalid constructor grades\n" << C_END;
    try
    {
        Bureaucrat invalid("Invalid", 0);
    }
    catch (std::exception& e)
    {
        std::cout << C_RED << e.what() << C_END;
    }
    try
    {
        Bureaucrat invalid("Invalid", 151);
    }
    catch (std::exception& e)
    {
        std::cout << C_RED << e.what() << C_END;
    }

    std::cout << C_YELLOW << "\nTest invalid increment grades\n" << C_END;
    try
    {
        Bureaucrat invalid("Invalid", 2);
        invalid.incrementGrade();
        invalid.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << C_RED << e.what() << C_END;
    }

    std::cout << C_YELLOW << "\nTest invalid decrement grades\n" << C_END;
    try
    {
        Bureaucrat invalid("Invalid", 149);
        invalid.decrementGrade();
        invalid.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << C_RED << e.what() << C_END;
    }
}
