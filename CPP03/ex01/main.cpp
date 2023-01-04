/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:01:39 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/04 12:40:33 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	test("toto");
	std::cout << std::endl;

	test.takeDamage(30);
	std::cout << std::endl;

	test.beRepaired(3);
	std::cout << std::endl;

	ClapTrap	instance("tata");
	std::cout << std::endl;

	instance.attack("foo");
	std::cout << std::endl;

	test.attack("foo");
	std::cout << std::endl;

	test.takeDamage(95);
	std::cout << std::endl;

	test.attack("42");
	std::cout << std::endl;

	test.beRepaired(2);
	std::cout << std::endl;

	test.guardGate();
	std::cout << std::endl;

	return 0;
}