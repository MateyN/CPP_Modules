/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:50:39 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/25 11:54:01 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	std::cout << YELLOW << "Basic tests" << RESET << std::endl;
    Harl	_Harl;

	// Basic tests

	std::cout << "Testing debug log level:" << std::endl;
	_Harl.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "Testing info log level:" << std::endl;
	_Harl.complain("INFO");
	std::cout << std::endl;
	std::cout << "Testing warning log level:" << std::endl;
	_Harl.complain("WARNING");
	std::cout << std::endl;
	std::cout << "Testing error log level:" << std::endl;
	_Harl.complain("ERROR");
	std::cout << std::endl;



		// MORE TESTS
	/*
	std::cout << YELLOW << "More tests" << RESET << std::endl;
	Harl	test;

	for (int i = 0; i < 5; i++)
	{
		test.complain("DEBUG");
		std::cout << std::endl;
		test.complain("INFO");
		std::cout << std::endl;
		test.complain("WARNING");
		std::cout << std::endl;
		test.complain("ERROR");
		std::cout << std::endl;
	}
	*/



		// SOME MORE TESTS
	/*
	std::cout << YELLOW << "Some more tests" << RESET << std::endl;
	Harl	test2;

	for (int i = 0; i < 5; i++)
	{
		test2.complain("DEBUG");
		std::cout << std::endl;
	}
	
	for (int i = 0; i < 4; i++)
	{
		test2.complain("INFO");
		std::cout << std::endl;
	}

	for (int i = 0; i < 3; i++)
	{
		test2.complain("WARNING");
		std::cout << std::endl;
	}

	for (int i = 0; i < 2; i++)
	{
		test2.complain("ERROR");
		std::cout << std::endl;
	}
	*/



		// TEST WITH RANDOM LOG LEVEL
	/*
	std::cout << YELLOW << "Test with a random log level" << RESET << std::endl;
	Harl	test3;

	std::string lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 20; i++)
	{
    	int randNum = rand() % 4;
    	std::string randLvl = lvls[randNum];
    	test3.complain(randLvl);
		std::cout << std::endl;
	}
	*/
	return 0;
}
