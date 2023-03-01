/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:39:48 by mnikolov          #+#    #+#             */
/*   Updated: 2023/03/01 03:06:52 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		ShrubberyCreationForm form("Home");
		std::cout << "ShrubberyCreationForm attributes: " << form << std::endl;

		Bureaucrat Bureaucrat1("Bureaucrat 1", 5);

		try
		{
			Bureaucrat1.executeForm(form);
		}
		catch(std::exception & e)
   		{
       		std::cout << e.what() << std::endl;
   		}

		Bureaucrat Bureaucrat2("Bureaucrat 2", 143);

		form.beSigned(Bureaucrat2);

		try
		{
			Bureaucrat2.executeForm(form);
		}
		catch(std::exception & e)
   		{
       		std::cout << e.what() << std::endl;
   		}

		form.beSigned(Bureaucrat1);
		Bureaucrat1.executeForm(form);
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}

	std::cout << std::endl;

	try
	{
		RobotomyRequestForm form("Robot");
		std::cout << "RobotomyRequestForm attributes: " << form << std::endl;

		Bureaucrat Bureaucrat1("Bureaucrat 1", 5);

		try
		{
			Bureaucrat1.executeForm(form);
		}
		catch(std::exception & e)
   		{
       		std::cout << e.what() << std::endl;
   		}

		Bureaucrat Bureaucrat2("Bureaucrat 2", 50);

		form.beSigned(Bureaucrat2);

		try
		{
			Bureaucrat2.executeForm(form);
		}
		catch(std::exception & e)
   		{
       		std::cout << e.what() << std::endl;
   		}

		form.beSigned(Bureaucrat1);
		Bureaucrat1.executeForm(form);
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}

	std::cout << std::endl;

	try
	{
		PresidentialPardonForm form("Pardon");
		std::cout << "PresidentialPardonForm attributes: " << form << std::endl;

		Bureaucrat Bureaucrat1("Bureaucrat 1", 5);

		try
		{
			Bureaucrat1.executeForm(form);
		}
		catch(std::exception & e)
   		{
       		std::cout << e.what() << std::endl;
   		}

		Bureaucrat Bureaucrat2("Bureaucrat 2", 20);

		form.beSigned(Bureaucrat2);

		try
		{
			Bureaucrat2.executeForm(form);
		}
		catch(std::exception & e)
   		{
       		std::cout << e.what() << std::endl;
   		}

		form.beSigned(Bureaucrat1);
		Bureaucrat1.executeForm(form);
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}

	return 0;
}