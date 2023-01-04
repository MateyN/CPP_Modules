/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:01:39 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/04 13:12:50 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap	test("toto");
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

	test.highFivesGuys();
	std::cout << std::endl;

	return 0;
}