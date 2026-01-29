#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const& executor) const override;

    private:
        std::string target_;
};

#define TREE_STRING "888 \n888                              ,d \n888                              88                                       _ \n888888888d888 .d88b.  .d88b.   MM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba,  | | \n888   888P\"  d8P  Y8bd8P  Y8b    88    88P'   \"Y8 a8P_____88 a8P_____88  | |_ _ __ ___  ___ \n888   888    8888888888888888    88    88         8PP\"\"\"\"\"\"\" 8PP\"\"\"\"\"\"\"  | __| '__/ _ \\/ _ \\ \nY88b. 888    Y8b.    Y8b.        88,   88         \"8b,   ,aa \"8b,   ,aa  | |_| | |  __/  __/ \n \"Y888888     \"Y8888  \"Y8888     \"Y888 88          `\"Ybbd8\"'  `\"Ybbd8\"'   \\__|_|  \\___|\\___|"

#endif // SHRUBBERYCREATIONFORM_HPP