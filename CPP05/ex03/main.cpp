/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:39:48 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/20 11:37:00 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{

	Intern someRandomIntern;
	Bureaucrat bureaucrat("Bureaucrat 1", 1);
	Form* id;
	Form* rrf;
	Form* prf;
	Form* shcf;

	std::cout << std::endl;

	try
	{
	id = someRandomIntern.makeForm("fake id", "Travel");

	std::cout << std::endl;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	std::cout << std::endl;

	prf = someRandomIntern.makeForm("presidential pardon", "Pardon");

	std::cout << std::endl;

	shcf = someRandomIntern.makeForm("shrubbery creation", "Home");
	shcf->execute(bureaucrat);
	}

	catch(std::exception & e)
   	{
		std::cout << e.what() << std::endl;
   	}

	delete id;
	delete rrf;
	delete prf;
	delete shcf;

	return 0;
}