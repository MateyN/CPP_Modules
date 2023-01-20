/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:39:48 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/20 11:06:38 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{

	Intern intern;
	Bureaucrat bureaucrat("Bureaucrat 1", 1);
	Form* id;
	Form* robotomy;
	Form* presidential;
	Form* shrubbery;

	std::cout << std::endl;

	try
	{
	id = intern.makeForm("fake id", "Travel");

	std::cout << std::endl;

	robotomy = intern.makeForm("robotomy request", "President");

	std::cout << std::endl;

	presidential = intern.makeForm("presidential pardon", "Pardon");

	std::cout << std::endl;

	shrubbery = intern.makeForm("shrubbery creation", "Home");
	shrubbery->execute(bureaucrat);
	}

	catch(std::exception & e)
   	{
		std::cout << e.what() << std::endl;
   	}

	delete id;
	delete robotomy;
	delete presidential;
	delete shrubbery;

	return 0;
}