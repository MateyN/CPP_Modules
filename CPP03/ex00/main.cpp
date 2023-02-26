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

int main()
{
    std::cout << "Creating a ClapTrap object named Zombie" << std::endl;
    ClapTrap Zombie("Zombie");

    std::cout << "Creating a ClapTrap object named Mutant..." << std::endl;
    ClapTrap Mutant("Mutant");

    std::cout << "Attacking Mutant with Bob..." << std::endl;
    Zombie.attack("Mutant");

    std::cout << "Repairing Zombie..." << std::endl;
    Zombie.beRepaired(5);

    std::cout << "Attacking Mutant with Zombie again..." << std::endl;
    Zombie.attack("Mutant");

    std::cout << "Mutant takes damage..." << std::endl;
    Mutant.takeDamage(3);

    std::cout << "Mutant takes more damage..." << std::endl;
    Mutant.takeDamage(8);

    std::cout << "Zombie is destroyed..." << std::endl;
    Zombie.takeDamage(10);

    std::cout << "Creating a new ClapTrap object named Xman..." << std::endl;
    ClapTrap Xman("Xman");

    std::cout << "Copying Mutant into Xman..." << std::endl;
    Xman = Mutant;

    std::cout << "Mutant and Xman are destroyed..." << std::endl;

    std::cout << "Trying to attack with Zombie..." << std::endl;
    Zombie.attack("Mutant");

    std::cout << "Trying to repair Zombie with not enough hit points and energy..." << std::endl;
    Zombie.takeDamage(8);
    Zombie.beRepaired(10);

    std::cout << "Trying to attack with Zombie with not enough hit points..." << std::endl;
    Zombie.beRepaired(5);
    Zombie.takeDamage(10);
    Zombie.attack("Mutant");

    std::cout << "Trying to attack with Zombie with no energy..." << std::endl;
    Zombie.takeDamage(5);
    Zombie.attack("Mutant");

    return 0;
}