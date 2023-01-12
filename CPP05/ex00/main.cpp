/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:39:48 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/11 12:29:38 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat instance("Bureaucrat", -2);
		std::cout << instance << std::endl;
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}

	try
	{
		Bureaucrat instance("Bureaucrat", 154);
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

	return 0;
}