/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:47:33 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/28 12:45:21 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap:: ScavTrap(void) : ClapTrap()
{
    std::cout << YELLOW << this->Name << " ScavTrap constructor is called." << RESET << std::endl;
    this->Name = "";
    this->Hit = 100;
    this->Energy = 50;
    this->attackDamage = 20;
    return ;
}

ScavTrap:: ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << YELLOW << this->Name << " ScavTrap constructor is called." << RESET << std::endl;
    this->Name = name;
    this->Hit = 100;
    this->Energy = 50;
    this->attackDamage = 20;
    return ;
}

ScavTrap:: ScavTrap(ScavTrap const &obj) : ClapTrap(obj)
{
    std::cout << YELLOW << " ScavTrap copy constructor is called" << RESET << std::endl;
    *this = obj;
}

ScavTrap & ScavTrap:: operator=(ScavTrap const &obj)
{
    std::cout << YELLOW << " ScavTrap Copy assignment operator called" << RESET << std::endl;
    this->Name = obj.Name;
    this->Hit = obj.Hit;
    this->Energy = obj.Energy;
    this->attackDamage = obj.attackDamage;
    return (*this);
}

ScavTrap:: ~ScavTrap(void)
{
    std::cout << RED << this->Name << " ScavTrap destructor is called" << RESET << std::endl;
    return ;
}

void    ScavTrap:: attack(const std::string& target)
{
    if (this->Energy > 0 && this->Hit > 0)
    {
        //ScavTrap instance(target);
        std::cout << GREEN  << "ScavTrap " << this->Name << " attacks " << target <<
        ", causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
        //instance.takeDamage(attackDamage);
        this->Energy--;
        std::cout << GREEN << "ScavTrap " << this->Name << " used 1 NRG pt and now has " << this->Energy << " NRG points left." << RESET << std::endl;
    }
    else if (this->Energy == 0)
		std::cout << GREEN << "ScavTrap " << this->Name << " is not able to attack " << target << ", because he has no energy points left." << RESET << std::endl;
	else
		std::cout << GREEN << "ScavTrap " << this->Name << " is not able to attack " << target << ", because he has not enough hit points." << RESET << std::endl;
}

void    ScavTrap:: guardGate(void)
{
    std::cout << BLUE << this->Name << " is now in Gate keeper mode." << RESET << std::endl;
    return ;
}