/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:01:39 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/28 12:06:55 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
/*
A derived class should be able to call methods and use data members of its base class.
On the other hand, a base class does not normally call methods or use members of its derived class
(generally, it doesn't know which derived class it's a part of).
For this reason, base class is constructed first and destroyed last,
so that it's valid while the constructor and destructor of its derived classes runs.
*/
int main()
{
        // Create a ClapTrap object named Zombie. This will call the default constructor of ClapTrap.
    std::cout << "Creating a ClapTrap object named Zombie..." << std::endl;
    ClapTrap Zombie("Zombie");

        // Create a ClapTrap object named Mutant. This will call the default constructor of ClapTrap.
    std::cout << "Creating a ClapTrap object named Mutant..." << std::endl;
    ClapTrap Mutant("Mutant");

        // Zombie attacks Mutant, which reduces Mutant's hit points.
    std::cout << "Attacking Mutant with Zombie..." << std::endl;
    Zombie.attack("Mutant");

        // Zombie is repaired, which increases his hit points.
    std::cout << "Repairing Zombie..." << std::endl;
    Zombie.beRepaired(5);

        // Zombie attacks Mutant again, which reduces Mutant's hit points further.
    std::cout << "Attacking Mutant with Zombie again..." << std::endl;
    Zombie.attack("Alice");

        // Mutant takes damage, which reduces his hit points.
    std::cout << "Mutant takes damage..." << std::endl;
    Mutant.takeDamage(3);

        // Mutant takes more damage, which reduces his hit points more.
    std::cout << "Mutant takes more damage..." << std::endl;
    Mutant.takeDamage(8);

        // Zombie is destroyed, which reduces his hit points to 0.
    std::cout << "Zombie is destroyed..." << std::endl;
    Zombie.takeDamage(10);

        // Create a ClapTrap object named Xman. This will call the default constructor of ClapTrap.
    std::cout << "Creating a new ClapTrap object named Xman..." << std::endl;
    ClapTrap Xman("Xman");

    std::cout << std::endl;
    
        // Create a ScavTrap object named SuperMan. This will call the default constructor of ScavTrap.
    std::cout << "Creating a ScavTrap object named SuperMan..." << std::endl;
    ScavTrap SuperMan("SuperMan");

        // Create a ScavTrap object named TheKeeper. This will call the default constructor of ScavTrap.
    std::cout << "Creating a ScavTrap object named TheKeeper..." << std::endl;
    ScavTrap TheKeeper("TheKeeper");

        // SuperMan attacks TheKeeper, which reduces TheKeeper's hit points.
    std::cout << "Attacking TheKeeper with SuperMan..." << std::endl;
    SuperMan.attack("TheKeeper");

        // TheKeeper guards the gate.
    std::cout << "Guarding the gate with TheKeeper..." << std::endl;
    TheKeeper.guardGate();

        // SuperMan attacks TheKeeper again, which reduces hit points more
    std::cout << "Attacking TheKeeper with SuperMan again..." << std::endl;
    SuperMan.attack("TheKeeper");

        // TheKeeper takes damage, which reduces his hit points.
    std::cout << "TheKeeper takes damage..." << std::endl;
    TheKeeper.takeDamage(3);

        // TheKeeper takes more damage, which reduces his hit points more.
    std::cout << "TheKeeper takes more damage..." << std::endl;
    TheKeeper.takeDamage(8);

        // Zombie is destroyed, which reduces his hit points to 0.
    std::cout << "SuperMan is destroyed..." << std::endl;
    SuperMan.takeDamage(10);

        // TheKeeper is destroyed, which reduces his hit points to 0.
    std::cout << "TheKeeper is destroyed..." << std::endl;

    std::cout << "Creating a ScavTrap object named FragTrap1..." << std::endl;
    FragTrap FragTrap1("FragTrap1");

    std::cout << "Creating a ScavTrap object named FragTrap2..." << std::endl;
    FragTrap FragTrap2("FragTrap2");


    std::cout << "Attacking FragTrap1 with FragTrap2..." << std::endl;
    FragTrap2.attack("FragTrap1");

    std::cout << "FragTrap1 does high five..." << std::endl;
    FragTrap1.highFivesGuys();

    std::cout << "FragTrap1 does high five..." << std::endl;
    FragTrap2.highFivesGuys();

    std::cout << "FragTrap1 takes damage..." << std::endl;
    FragTrap1.takeDamage(8);

        // Zombie is destroyed, which reduces his hit points to 0.
    std::cout << "FragTrap2 takes damage..." << std::endl;
    FragTrap2.takeDamage(10);

    std::cout << "Creating a DiamondTrap object named DiamondTrap1..." << std::endl;
    DiamondTrap DiamondTrap1("DiamondTrap1");

    DiamondTrap1.whoAmI();

    return 0;
}