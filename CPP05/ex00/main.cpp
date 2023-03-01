/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:39:48 by mnikolov          #+#    #+#             */
/*   Updated: 2023/03/01 00:38:38 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat instance("Bureaucrat", -42);
		std::cout << instance << std::endl;
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}

	try
	{
		Bureaucrat instance("Bureaucrat", 255);
		std::cout << instance << std::endl;
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}

	try
	{
		Bureaucrat instance("Bureaucrat", 3);
		std::cout << instance << std::endl;
		instance.increment();
		instance.increment();
		instance.increment();
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}

	try
	{
		Bureaucrat instance("Bureaucrat", 149);
		std::cout << instance << std::endl;
		instance.decrement();
		instance.decrement();
		instance.decrement();
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}
		std::cout << std::endl;
	  try
    {
        Bureaucrat instance1("Bureaucrat", 10);
        instance1.increment();
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}
	try
	{
        Bureaucrat instance2("Bureaucrat", 150);
        instance2.decrement();
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}
	try
	{
        // This should throw a GradeTooHighException
        Bureaucrat instance3("Bureaucrat", 0);
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}
	try
	{
        // This should throw a GradeTooLowException
        Bureaucrat instance4("Bureaucrat", 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	return 0;
}