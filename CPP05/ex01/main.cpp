/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:39:48 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/13 12:03:42 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	try
	{
		Form form1("Form 1", 20, 10);
		std::cout << "Form created with attributes: " << form1 << std::endl;
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}

	std::cout << std::endl;
	
	try
	{
		Form form2("Form 2", 20, 10);
		std::cout << "Form created with attributes: " << form2 << std::endl;

		Bureaucrat bureaucrat1("Bureaucrat 1", 3);
		try
		{
			form2.beSigned(bureaucrat1);
			std::cout << "Form 2 attributes: " << form2 << std::endl;
		}
		catch(std::exception & e)
   		{
       		std::cout << e.what() << std::endl;
   		}

		std::cout << std::endl;

		Bureaucrat bureaucrat2("Bureaucrat 2", 4);
		form2.beSigned(bureaucrat2);
		std::cout << "Form 2 attributes: " << form2 << std::endl;
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}

	return 0;
}