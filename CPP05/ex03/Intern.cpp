/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:37:36 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/19 12:38:58 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern:: Intern(void)
{
    std::cout << GREEN << "Intern constructor is called." << RESET << std::endl;
}

Intern:: Intern(Intern const &obj)
{
    std::cout << YELLOW << "Intern copy constructor is called." << RESET << std::endl;
    *this = obj;
}

Intern & Intern:: operator=(Intern const &obj)
{
    std::cout << YELLOW << "Intern copy assignment operator is called." << RESET << std::endl;
    (void)obj;
    return *this;
}

Intern:: ~Intern(void)
{
    std::cout << RED << "Intern destructor is called." << RESET << std::endl;
    return ;
}

Form* Intern:: makeForm(std::string name, std::string target)
{
    std::string tab[4] = {"shrubbery creation", "robotomy request", "presidential pardon", "no form"};
    for (int i = 0; i < 4; i++)
    {
        if (name == tab[i] || i == 3)
        {
            switch(i)
            {
                case 0:
                        std::cout << MAGENTA << "Intern creates " << name << " form" << RESET << std::endl;
                        return (new ShrubberyCreationForm(target));
                        break;
                case 1:
                        std::cout << MAGENTA << "Intern creates " << name << " form" << RESET << std::endl;
                        return (new RobotomyRequestForm(target));
                        break;
                case 2:
                        std::cout << MAGENTA << "Intern creates " << name << " form" << RESET << std::endl;
                        return (new PresidentialPardonForm(target));
                case 3:
                        std::cout << MAGENTA << "Error: the form " << name << " does not exist!" << RESET << std::endl;
                        return 0;
                        break;
            }
        }
    }
    return 0;
}