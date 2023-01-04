/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:47:37 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/04 10:40:49 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) 
{
	ClapTrap	test("Attacker");
	std::cout << std::endl;
	
	test.takeDamage(6);
	std::cout << std::endl;
	
	test.beRepaired(3);
	std::cout << std::endl;
	
	test.attack("Target");
	std::cout << std::endl;
	
	test.takeDamage(8);
	std::cout << std::endl;
	
	test.attack("Target2");
	std::cout << std::endl;

	test.beRepaired(2);
	std::cout << std::endl;

	// Testing copy constructor
	ClapTrap	test2(test);

	test2.attack("Target");
	std::cout << std::endl;

	test2.takeDamage(6);
	std::cout << std::endl;

	test2.beRepaired(3);
	std::cout << std::endl;

	test2.attack("Target2");
	std::cout << std::endl;

	test2.takeDamage(8);
	std::cout << std::endl;

	test2.attack("Target3");
	std::cout << std::endl;

	test2.beRepaired(2);
	std::cout << std::endl;

	return 0;
}