/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:01:39 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/26 14:17:30 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "Creating a ClapTrap object named Zombie..." << std::endl;
    ClapTrap Zombie("Zombie");

    std::cout << "Creating a ClapTrap object named Mutant..." << std::endl;
    ClapTrap Mutant("Mutant");

    std::cout << "Attacking Mutant with Zombie..." << std::endl;
    Zombie.attack("Mutant");

    std::cout << "Repairing Zombie..." << std::endl;
    Zombie.beRepaired(5);

    std::cout << "Attacking Mutant with Zombie again..." << std::endl;
    Zombie.attack("Alice");

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

    std::cout << std::endl;

    std::cout << "Creating a ScavTrap object named SuperMan..." << std::endl;
    ScavTrap SuperMan("SuperMan");

    std::cout << "Creating a ScavTrap object named TheKeeper..." << std::endl;
    ScavTrap TheKeeper("TheKeeper");

    std::cout << "Attacking TheKeeper with SuperMan..." << std::endl;
    SuperMan.attack("TheKeeper");

    std::cout << "Guarding the gate with TheKeeper..." << std::endl;
    TheKeeper.guardGate();

    std::cout << "Attacking TheKeeper with SuperMan again..." << std::endl;
    SuperMan.attack("TheKeeper");

    std::cout << "TheKeeper takes damage..." << std::endl;
    TheKeeper.takeDamage(3);

    std::cout << "TheKeeper takes more damage..." << std::endl;
    TheKeeper.takeDamage(8);

    std::cout << "SuperMan is destroyed..." << std::endl;
    SuperMan.takeDamage(10);

    std::cout << "Creating a new ScavTrap object named Unknown..." << std::endl;
    ScavTrap Unknown("Unknown");

    std::cout << "Copying TheKeeper into Unknown..." << std::endl;
    Unknown = TheKeeper;

    std::cout << "TheKeeper and Unknown are destroyed..." << std::endl;

    return 0;
}